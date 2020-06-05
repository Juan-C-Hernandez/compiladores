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
	if(tt->num > 0){
		finish_typ(tt->head);
		tt->tail = tt->head;
		tt->num = 0;
		finish_typ_tab(tt->next);
		tt->next = NULL;
	}
}


// Reserva memoria para la pila
TSTACK *init_type_tab_stack(){
	TSTACK *stack = malloc(sizeof *stack);
	if(!stack){
	    return NULL;
    }
	stack->top = stack->tail = NULL;
	return stack;
}


// Reserva memoria para una tabla de tipos de inserta los tipos nativos
TYPTAB *init_type_tab(){
	TYPTAB *tabla_tipos = malloc(sizeof *tabla_tipos);
	if(!tabla_tipos){
	    return NULL;
    }
	/*	TIPOS NATIVOS	
	TYP *tipo_nativo = init_type();
	*/
	tabla_tipos->next = NULL;
	tabla_tipos->num = 0;
	return tabla_tipos;
}


//Reserva memoria para un tipo
TYP *init_type(){
	TYP *tipo = malloc(sizeof *tipo);
	if(!tipo){
	    return NULL;
    }
	tipo->next = NULL;
	return tipo;
}

// Libera memoria para la pila
void finish_typ_tab_stack(TSTACK *s){
	finish_typ_tab(s->tail);
	free(s);
}

// Libera memoria para una tabla de tipos
void finish_typ_tab(TYPTAB *tt){
	if(tt->next == NULL){
		finish_typ(tt->head);
		free(tt);
	}
	finish_typ_tab(tt->next);
}

// libera memoria para un tipo
void finish_typ(TYP *t){
	if(t->next == NULL){
		free(t);
	}
	finish_typ(t->next);
}

// Retorna el tamaño de un tipo
int getTam(TYPTAB *t, int id){
	TYP *tmp = busca_typ(t->head, id);
	if(!tmp){
		return -1;
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
	TYP *tmp = busca_typ(t->head, id);
	/*if(!tmp){
		return -1;
	}*/
	
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
	
	for(i = 0; i < t->num; i++){
		printf("|%10d|%13s|%5zu|%17p|%17p|\n", tmp->id, tmp->nombre, tmp->tam, tmp, tmp->next);
		printf("--------------------------------------------------------------------\n");
		tmp = tmp->next;
	}
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
