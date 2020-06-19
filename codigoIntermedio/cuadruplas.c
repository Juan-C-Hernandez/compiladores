#include "cuadruplas.h"
#include <stdlib.h>

// Reserva memoria para una cuadrupla
QUAD *init_quad() {
	QUAD *tmp = malloc(sizeof *tmp);
	if(!tmp) {
		return NULL;
	}
	
	tmp->next = NULL;
	return tmp;
}

// Libe ra la memoria de una cuadrupla
void finish_quad(QUAD *c) {
	if(!c) {
		return;
	}
	
	finish_quad(c->next);
	free(c->arg1);
	free(c->arg2);
	free(c->op);
	free(c->res);
	free(c);
}

// Reserva memoria para e l codigo
CODE *init_code() {
	CODE *tmp = malloc(sizeof *tmp);
	if(!tmp) {
		return NULL;
	}
	
	tmp->head = tmp->tail = NULL;
	return tmp;
}

// Libera la memoria de la lista ligada del codigo
void finish_code(CODE *c) {
	finish_quad(c->head);
	free(c);
}

// Agrega una cuadrupla al final de la lista
void append_quad(CODE* C, QUAD *cd) {
	if(!C->head) {
		C->head = C->tail = cd;
	} else {
		C->tail->next = cd;
		C->tail = cd;
	}
	
	C->tail->next = NULL;
}
