#include "tabla_simbolos.h"
#include <stdlib.h>
#include <stdio.h>

//Agrega un argumento al final
void append_arg(ARGS *args, int arg) {
	/* FUNCIONA */
	ARG *argp = init_arg(arg);
	if(!argp) {
		exit(1);
	}
	if (!args->head) {
		args->head = args->tail = argp;
	} else {
		args->tail->next = argp;
		args->tail = argp;
	}

	args->tail->next = NULL;
	args->num++;
}

//Compara dos lista y devuelve 1 si son iguales, 0 si son diferentes
int compare_args(ARGS *a1, ARGS *a2) {
	/* FUNCIONA */
	ARG *tmp1 = a1->head, *tmp2 = a2->head;
	for( ; tmp1 && tmp2; tmp1 = tmp1->next, tmp2 = tmp2->next)
		if(tmp1->arg != tmp2->arg) return 0;
		//if(tmp1->arg != tmp2->arg) break;

	return !(!!tmp1 || !!tmp2);
}

//Agrega al final de la tabla un nuevo simbolo
void append_sym(SYMTAB *t, SYM *s) {
	/* FUNCIONA */
	if (!t->head){
		t->head = t->tail = s;
	} else {
		t->tail->next = s;
		t->tail = s;
	}
	
	t->tail->next = NULL;
	t->num++;
}

// Deja vacia la tabla
void clear_sym_tab(SYMTAB *t) {
	/* FUNCIONA */
	if (!!t) {
		finish_sym(t->head);
		t->head = t->tail = NULL;
		t->num = 0;
	}
}

// Ejecuta un pop sobre la pila de tablas de simbolos
SYMTAB pop_st(SSTACK *s){
	/* FUNCIONA */
    SYMTAB *tmp = s->top;
    s->top = s->top->next;
    tmp->next = NULL;
    SYMTAB tmp_valor = *tmp;
    free(tmp);
    return tmp_valor;
    
}

// Ingresa una tabla a la pila de tablas de simbolos
void push_st(SSTACK *s, SYMTAB*st) {
	/* FUNCIONA */
	if (!s->top) {
		s->tail = s->top = st;
	} else {
		SYMTAB *tmp = s->top;
		s->top = st;
		s->top->next = tmp;
	}
}

// Retorna el apunador a un tipo ARGS
ARGS *init_args() {
	/* FUNCIONA */
	ARGS *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->head = tmp->tail = NULL;
	tmp->num = 0;
	return tmp;
}

// Reserva memoria para un tipo ARG y retorna el apuntador
ARG *init_arg(int dato) {
	/* FUNCIONA */
	ARG *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->next = NULL;
	tmp->arg = dato;
	return tmp;
}

// Reserva memoria para la pila
SSTACK *init_sym_tab_stack() {
	/* FUNCIONA */
	SSTACK *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->tail = tmp->top = NULL;
	return tmp;
}

// Reserva memoria para una tabla de simbolos vacia
SYMTAB *init_sym_tab() {
	/* FUNCIONA */
	SYMTAB *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->head = tmp->tail = NULL;
	tmp->next = NULL;
	tmp->num = 0;
	return tmp;
}

// Reserva memoria para un simbolo vacio
SYM *init_sym() {
	/* FUNCIONA */
	SYM *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->args = NULL;
	tmp->next = NULL;
}

// Libera la memoria para la pila
void finish_sym_tab_stack(SSTACK *s) {
	finish_sym_tab(s->top);
	free(s);
}

// Libera memoria para una tabla de simbolos
void finish_sym_tab(SYMTAB *st) {
	if (!st) {
		return;
	}
	
	finish_sym_tab(st->next);
	finish_sym(st->head);
	free(st);
}

// libera memoria para un simbolo
void finish_sym(SYM *s) {
	if (!s) {
		return;
	}
	
	finish_sym(s->next);
	free(s);
}

// libera memoria para un arg
void finish_arg(ARG *a) {
	if (!a) {
		return;
	}
	
	finish_arg(a->next);
	free(a);
}

// libera memoria para una lista ARGS
void finish_args(ARGS *a) {
	finish_arg(a->head);
	free(a);
}

// Imprime en pantalla la tabla de simbolos
void print_tab(SYMTAB *t) {
	/* FUNCIONA */
	printf("----------------------------------------------------\n");
	printf("|%-29s %-20p|\n","Imprimiendo tabla de simbolos", t);
	printf("----------------------------------------------------\n");
	SYM *tmp = t->head;
	if(!tmp) {
		printf("|%50s|\n","Tabla vacia, nada que imprimir");
		printf("----------------------------------------------------\n");
	} else {
		while(tmp){
			printf("|Direccion simbolo: %-31p|\n", tmp);
			printf("|Dir: %-45d|\n|Tipo: %-44d|\n|Id: %-46s|\n|%-50s|\n", tmp->dir, tmp->tipo, tmp->id, "Argumentos: ");
			print_args(tmp->args);
			printf("|Num: %-45d|\n|Var: %-45d|\n|Next: ", tmp->num, tmp->var);
			if(!tmp->next){
				printf("%-44s|\n", "NULL");
			} else {
				printf("%-44p|\n", tmp->next);
			}
			printf("----------------------------------------------------\n");
			tmp = tmp->next;
		}
		
	}
	printf("------------------------\n");
	printf("|Num: %-17d|\n", t->num);
	printf("------------------------\n");
	printf("|Next: ");
	if(!t->next){
		printf("%-16s|\n", "NULL");
	} else {
		printf("%-16p|\n", t->next);
	}
	printf("------------------------\n");
}

// Imprime en pantalla los argumentos
void print_args(ARGS *args) {
	/* FUNCIONA */
	ARG *tmp = args->head;
	int i;
	printf("|");
	while(!!tmp) {
		printf("%d, ", tmp->arg);
		tmp = tmp->next;
	}
	printf("|\n");
}

int getDir(SYMTAB *T, char *id) {
	/* FUNCIONA */
	SYM *tmp = busca_sym(T->head, id);
	if(!tmp) {
		return -1;
	}
	
	return tmp->dir;
}

int getTipo(SYMTAB *T, char *id) {
	/* FUNCIONA */
	SYM *tmp = busca_sym(T->head, id);
	if(!tmp) {
		return -1;
	}
	return tmp->tipo;
}

int getVar(SYMTAB *T, char *id) {
	/* FUNCIONA */
	SYM *tmp = busca_sym(T->head, id);
	if(!tmp) {
		return -1;
	}
	
	return tmp->var;
}

ARGS getArgs(SYMTAB *T, char *id) {
	SYM *tmp = busca_sym(T->head, id);
	if (!tmp) {
		return;
	}
	
	return *tmp->args;
}

int getNumArgs(SYMTAB *T, char *id) {
	/* FUNCIONA */
	SYM *tmp = busca_sym(T->head, id);
	if(!tmp) {
		return -1;
	}
	
	return tmp->num;
}

SYM *busca_sym(SYM *s, char *id) {
	/* FUNCIONA */
	if(!s) {
		return NULL;
	}
	
	if(!strcmp(s->id, id)) {
		return s;
	}
	
	return busca_sym(s->next, id);
}
