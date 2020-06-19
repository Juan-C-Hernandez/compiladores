#include "backpatch.h"
#include <stdlib.h>
#include "cuadruplas.h"

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
	LINDEX *list = malloc(sizeof *list);
	if(!list) {
		return NULL;
	}
	list->head = list->tail = i;
	list->tail->next = NULL;
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
	LINDEX *nueva = malloc(sizeof *nueva);
	if(!nueva) {
		return NULL;
	}
	
	nueva->head = l1.head;
	l1.tail->next = l2.head;
	nueva->tail = l2.tail;
	
	return nueva;
}

// Reemplaza label en cada aparicion de un indice en la cuadruplas del codigo c
/*void backpath(CODE *c, LINDEX l, char *label) {
	
}*/
