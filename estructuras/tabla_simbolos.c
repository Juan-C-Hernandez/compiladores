#include "tabla_simbolos.h"
#include <string.h>

//Agrega un argumento al final
void append_arg(ARGS args, int arg) {
	if (!args->head) {
		args->head = args->tail = arg;
	} else {
		args->tail->next = arg;
		args->tail = arg;
	}
	
	args->tail->next = NULL;
	args->num++;
}


//Compara dos lista y devuelve 1 si son iguales, 0 si son diferentes
/*int compare_args(ARGS a1, ARGS a2) {
	if (a1->num != a2->num) {
		return 0;
	}
	
	ARG *tmp1 = a1->head, *tmp2 = a2->head;
	while (!!tmp1->next && !!tmp2->next) {
		if (tmp1->arg == tmp2->arg) {
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		} else {
			return 0;
		}
	}
	
	return tmp1->arg == tmp2->arg ? 1 : 0;
}*/

//Agrega al final de la tabla un nuevo simbolo
void append_sym(SYMTAB t, SYM s) {
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
void clear_sym_tab(SYMTAB t) {
	if (!!t) {
		finish_sym(t->head);
		t->head = t->tail = NULL;
		t->num = 0;
	}
}

// Ejecuta un pop sobre la pila de tablas de simbolos
SYMTAB pop_st(SSTACK s) {
	SYMTAB *tmp = s->top;
	tmp->next = NULL;
	SYMTAB popped = *tmp;
	s->top = s->top->next;
	finish_sym_tab(tmp);
	return popped;
}

// Ingresa una tabla a la pila de tablas de simbolos
void push_st(SSTACK s, SYMTAB st) {
	if (!s->top) {
		s->tail = s->top = st;
	} else {
		SYMTAB *tmp = s->top;
		s->top = st;
		s->top->next = tmp;
	}
}

// Retorna el apunador a un tipo ARGS
ARGS init_args() {
	ARGS *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->head = tmp->tail = NULL;
	tmp->num = 0;
	return tmp;
}

// Reserva memoria para un tipo ARG y retorna el apuntador
ARG init_arg(int dato) {
	ARG *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->next = NULL;
	return tmp;
}

// Reserva memoria para la pila
SSTACK init_sym_tab_stack() {
	SSTACK *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->tail = tmp->top = NULL;
	return tmp;
}

// Reserva memoria para una tabla de simbolos vacia
SYMTAB init_sym tab() {
	SYMTAB *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->head = tmp->tail = tmp->next = NULL;
	tmp->num = 0;
	return tmp;
}

// Reserva memoria para un simbolo vacio
SYM init_sym() {
	SYM *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->args = tmp->next = NULL;
	tmp->id = {'\0', };
}

// Libera la memoria para la pila
void finish_sym_tab_stack(SSTACK s) {
	finish_sym_tab(s->top);
	free(s);
}

// Libera memoria para una tabla de simbolos
void finish_sym_tab(SYMTAB st) {
	if (!st) {
		return;
	}
	
	finish_sym_tab(st->next);
	finish_sym(st->head);
	free(st);
}

// libera memoria para un simbolo
void finish_sym(SYM s) {
	if (!s) {
		return;
	}
	
	finish_sym(s->next);
	free(s);
}

// libera memoria para un arg
void finish_arg(ARG a) {
	if (!a) {
		return;
	}
	
	finish_arg(a->next);
	free(a);
}

// libera memoria para una lista ARGS
void finish_args(ARGS a) {
	finish_arg(a->head);
	free(a);
}

// Imprime en pantalla la tabla de simbolos
void print_tab(SYMTAB t) {
	
}

int getDir(SYMTAB T, char *id) {
	SYM *tmp = busca_sym(T->head);
	if(!tmp) {
		return -1;
	}
	
	return tmp->dir;
}

int getTipo(SYMTAB T, char *id) {
	SYM *tmp = busca_sym(T->head);
	if(!tmp) {
		return -1;
	}
	return tmp->tipo;
}

int getVar(SYMTAB T, char *id) {
	SYM *tmp = busca_sym(T->head);
	if(!tmp) {
		return -1;
	}
	
	return tmp->var;
}

ARGS getArgs(SYMTAB T, char *id) {
	SYM *tmp = busca_sym(T->head);
	if (!tmp) {
		return;
	}
	
	return *tmp->args;
}

int getNumArgs(SYMTAB T, char *id) {
	SYM *tmp = busca_sym(T->head);
	if(!tmp) {
		return -1;
	}
	
	return tmp->num;
}

SYM *busca_sym(SYM s, char *id) {
	if(!s) {
		return NULL;
	}
	
	if(!strcmp(s->id, id)) {
		return s;
	}
	
	busca_sym(s->next);
}
