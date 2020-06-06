//
// Created by juan2 on 31/05/2020.
//

#include <stdlib.h>
#include "tabla_tipos.h"
#include <stdio.h>

// Agrega al final de la tabla un nuevo tipo
void append_type(TYPTAB *TT, TYP *t){
    /* FUNCIONA */
	if(TT->num == 0){
	   TT->head = t;
	   TT->tail = TT->head;
	} else{
        TT->tail->next = t;
        TT->tail = t;
    }
    
	TT->tail->next = NULL;
	TT->num++;
}

// Deja vacia la tabla
void clear_type_tab(TYPTAB *tt){
    /* FUNCIONA */
	if(tt->num > 0){
	    finish_typ(tt->head);
		tt->tail = tt->head = NULL;
		tt->num = 0;
	}
}

/*
// Ejecuta un pop sobre la pila de tablas de tipos
TYPTAB pop_st(TSTACK *s){
    TYPTAB tmp = *
}*/

// ingresa una tabla a la pila de tabla de tipos
void push_st(TSTACK *s, TYPTAB *tt){
    /* CORREGIR */
    if(!s->top){
        s->tail = s->top = tt;
    } else{
        TSTACK tmp = s->top;
        s->top = tt;
        s->top->next = tmp;
    }
}

// Reserva memoria para la pila
TSTACK *init_type_tab_stack(){
    /* FUNCIONA */
	TSTACK *stack = malloc(sizeof *stack);
	if(!stack){
	    return NULL;
    }
	stack->top = stack->tail = NULL;
	return stack;
}


// Reserva memoria para una tabla de tipos de inserta los tipos nativos
TYPTAB *init_type_tab(){
    /* FUNCIONA */
	TYPTAB *tabla_tipos = malloc(sizeof *tabla_tipos);
	if(!tabla_tipos){
	    return NULL;
    }
    
	/*	AGREGAR TIPOS NATIVOS	
	TYP *tipo_nativo = init_type();
	*/
	
    tabla_tipos->head = tabla_tipos->tail = NULL;
	tabla_tipos->next = NULL;
	tabla_tipos->num = 0;
	return tabla_tipos;
}


//Reserva memoria para un tipo
TYP *init_type(){
    /* FUNCIONA */
	TYP *tipo = malloc(sizeof *tipo);
	if(!tipo){
	    return NULL;
    }
	tipo->next = NULL;
	return tipo;
}

// Libera memoria para la pila
void finish_typ_tab_stack(TSTACK *s){
    /* +++++++++++++++++++++++++++++++++++++++++++ */
	finish_typ_tab(s->tail);
	free(s);
}

// Libera memoria para una tabla de tipos y las tablas siguientes
void finish_typ_tab(TYPTAB *tt){
    /* +++++++++++++++++++++++++++++++++++++++++++ */
	if(!tt){
		return;
	}
	
	finish_typ_tab(tt->next);
	finish_typ(tt->head);
	free(tt);
}

// libera memoria para un tipo y los tipos siguientes
void finish_typ(TYP *t){
    /* +++++++++++++++++++++++++++++++++++++++++++ */
	if(!t){
	    return;
	}
	
	finish_typ(t->next);
    free(t);
}

// Retorna el tamaño de un tipo
int getTam(TYPTAB *t, int id){
    /* FUNCIONA */
	TYP *tmp = busca_typ(t->head, id);
	if(!tmp){
		return 0;
	}
	
	return tmp->tam;
}

//retorna el tipo base
TB getTipoBase(TYPTAB *t, int id){
	TYP *tmp = busca_typ(t->head, id);
	/*if(!tmp){
		return -1;
	}*/
	
	return tmp->tb;
}

// Retorna el nombre de un tipo
char *getNombre(TYPTAB *t, int id){
    /* FUNCIONA */
	TYP *tmp = busca_typ(t->head, id);
	if(!tmp){
		return '\0';
	}
	
	return tmp->nombre;
}

int getNum(TYPTAB *T){
    /* FUNCIONA */
    return T->num;
}

// imprime en pantalla la tabla de tipos
void print_tab(TYPTAB *t){
    /* FUNCIONA */
	int i;
	TYP *tmp = t->head;
	printf("--------------------------------------------------------------------\n");
	printf("|%10s|%13s|%5s|%17s|%17s|\n", "id", "nombre", "tam", "direccion", "siguiente");
	printf("--------------------------------------------------------------------\n");
	
	if(!tmp){
	    printf("|%66s|\n", "La lista esta vacia");
	    printf("--------------------------------------------------------------------\n");
    } else{
        for(i = 0; i < t->num; i++){
            printf("|%10d|%13s|%5zu|%17p|", tmp->id, tmp->nombre, tmp->tam, tmp);
            if(!tmp->next){
                printf("%17s|\n", "NULL");
            } else{
                printf("%17p|\n", tmp->next);
            }
		  printf("--------------------------------------------------------------------\n");
		tmp = tmp->next;
	   }
    }
	
	printf("-------------------------------------------\n");
    printf("|%5s|%17s|%17s|\n", "num", "direccion", "siguiente");
    printf("-------------------------------------------\n");
    printf("|%5d|%17p|",t->num, t);
    if(!t->next){
        printf("%17s|\n", "NULL");
    } else{
        printf("%17p|\n", t->next);
    }
    printf("-------------------------------------------\n");
	printf("\n");
}

// Busca ID en una lista ligada
TYP *busca_typ(TYP *t, int id){
    /* FUNCIONA */
	if(t == NULL){
		return NULL;
	}
	
	if(t->id == id){
		return t;
	}
	
	return busca_typ(t->next, id);
}
