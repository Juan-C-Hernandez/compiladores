#include <stdio.h>
#include <stdlib.h>
#include "backpatch.h"
#include <string.h>

void print_lista(LINDEX *l) {
	INDEX *i = l->head;
	while(i){
		printf("%s ->", i->indice);
		i = i->next;
	}
	printf("\n");
}

int main(int argc, char *argv[]) {
	INDEX *i = init_index();
	i->indice = malloc(sizeof *i->indice * 32);
	strcpy(i->indice, "indice1");
	
	INDEX *i2 = init_index();
	i2->indice = malloc(sizeof *i2->indice * 32);
	strcpy(i2->indice, "indice2");
	
	INDEX *i3 = init_index();
	i3->indice = malloc(sizeof *i3->indice * 32);
	strcpy(i3->indice, "indice3");
	
	INDEX *i4 = init_index();
	i4->indice = malloc(sizeof *i4->indice * 32);
	strcpy(i4->indice, "indice4");
	
	INDEX *i5 = init_index();
	i5->indice = malloc(sizeof *i5->indice * 32);
	strcpy(i5->indice, "indice5");
	
	LINDEX *lista1 = init_list_index(i);
	append_index(lista1, i3);
	printf("Lista1: ");
	print_lista(lista1);
	LINDEX *lista2 = init_list_index(i2);
	append_index(lista2, i5);
	append_index(lista2, i4);
	printf("Lista2: ");
	print_lista(lista2);
	
	printf("Despues de combinar:\n");
	LINDEX *lista_nueva = combinar(*lista1, *lista2);
	printf("lista nueva: ");
	print_lista(lista_nueva);
	printf("Lista1: ");
	print_lista(lista1);
	printf("Lista2: ");
	print_lista(lista2);
}
