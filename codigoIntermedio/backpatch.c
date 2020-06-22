#include "backpatch.h"
#include <stdio.h>
#include <stdlib.h>
#include "cuadruplas.h"
#include <string.h>

void append_list(LINDEX *dest, LINDEX orig);

// Reserva memoria para un nodo de indice
INDEX *init_index() {
	INDEX *tmp = malloc(sizeof *tmp);
	if (!tmp) {
		return NULL;
	}
	
	tmp->next = NULL;
	return tmp;
}

// Libera la memoria de un nodo indice
void finish_index(INDEX *i) {
	if (!i) {
		return;
	}
	
	finish_index(i->next);
	free(i->indice);
	free(i);
}

// Reserva memoria para la lista de indice se inserta el primero
LINDEX *init_list_index(INDEX *i) {
	LINDEX *list = init_list_index_empty();
	if(!list) {
		return NULL;
	}
	append_index(list, i);
	return list;
}

LINDEX *init_list_index_empty() {
	LINDEX *list = malloc(sizeof *list);
	if(!list) {
		return NULL;
	}
	
	list->head = list->tail = NULL;
	
	return list;
}

// Libera la memoria de la lista y de todos los nodos dentro
void finish_list_index(LINDEX *L) {
	finish_index(L->head);
	free(L);
}

// Agrega un nodo indice al final de la lista
void append_index(LINDEX *l, INDEX *i) {
	if(!l->head) {
		l->head = l->tail = i;
	} else {
		l->tail->next = i;
		l->tail = i;
	}
	
	l->tail->next = NULL;
}

// retorna una lista ligada de la concatenacion de l1 con l2 // nueva
LINDEX *combinar(LINDEX l1, LINDEX l2) {
	LINDEX *nueva = init_list_index_empty();
	if(!nueva) {
		return NULL;
	}
	
	append_list(nueva, l1);
	append_list(nueva, l2);
	
	return nueva;
}

void append_list(LINDEX *dest, LINDEX orig) {
	INDEX *tmp = orig.head;
	INDEX *nueva_tmp;
	int len;

	// Copia cada elemento de orig en dest
	for(; tmp; tmp = tmp->next) {
		nueva_tmp = init_index();
		len = strlen(tmp->indice) + 1;
		nueva_tmp->indice = malloc(len);
		strcpy(nueva_tmp->indice, tmp->indice);
		append_index(dest, nueva_tmp);
	}
}

// Reemplaza label en cada aparicion de un indice en la cuadruplas del codigo c
/*void backpath(CODE *c, LINDEX l, char *label) {
	
}*/
