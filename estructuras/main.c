//
// Created by juan2 on 31/05/2020.
//

#include "tabla_simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_stack(SSTACK *s){
    SYMTAB *tmp = s->top;
    printf("------------------------------------------------\n");
    if(!tmp){
        printf("Nada que imprimir\n");
    } else{
        printf("Imprimiendo pila:\nTOP\n");
        while(tmp != NULL){
        	print_tab(tmp);
        	printf("\n");
        	tmp = tmp->next;
    	}
    }
}

int main(int arc, char **argv){
    ARGS *args = init_args();
	ARGS *args1 = init_args();
	ARGS *args2 = init_args();
	ARGS *args3 = init_args();
	ARGS *args4 = init_args();
	ARGS *args5 = init_args();
	int i;
	
	append_arg(args, 0);
	append_arg(args, 2);
	append_arg(args, 3);
	append_arg(args, 8);
	append_arg(args, 90);
	append_arg(args, 50);
	
	append_arg(args1, 0);
	append_arg(args1, 2);
	append_arg(args1, 33);
	append_arg(args1, 8);
	append_arg(args1, 90);
	append_arg(args1, 50);
	
	print_args(args);
	print_args(args1);
	i = compare_args(args, args1);
	if(i == 1){
		printf("Son iguales\n");
	} else {
		printf("No son iguales\n");
	}
	
	printf("\n");
	
	append_arg(args2, 0);
	append_arg(args2, 2);
	append_arg(args2, 3);
	append_arg(args2, 8);
	append_arg(args2, 90);
	append_arg(args2, 50);
	append_arg(args2, 50);
	
	print_args(args);
	print_args(args2);
	i = compare_args(args, args2);
	if(i == 1){
		printf("Son iguales\n");
	} else {
		printf("No son iguales\n");
	}
	printf("\n");
	
	print_args(args2);
	print_args(args);
	i = compare_args(args2, args);
	if(i == 1){
		printf("Son iguales\n");
	} else {
		printf("No son iguales\n");
	}
	printf("\n");
	
	append_arg(args4, 0);
	append_arg(args4, 2);
	append_arg(args4, 33);
	append_arg(args4, 8);
	append_arg(args4, 90);
	append_arg(args4, 51);
	
	print_args(args);
	print_args(args4);
	i = compare_args(args, args4);
	if(i == 1){
		printf("Son iguales\n");
	} else {
		printf("No son iguales\n");
	}
	printf("\n");
	
	append_arg(args5, 1);
	append_arg(args5, 2);
	append_arg(args5, 33);
	append_arg(args5, 8);
	append_arg(args5, 90);
	append_arg(args5, 50);
	
	print_args(args);
	print_args(args5);
	i = compare_args(args, args5);
	if(i == 1){
		printf("Son iguales\n");
	} else {
		printf("No son iguales\n");
	}
	printf("\n");
	
	append_arg(args3, 0);
	append_arg(args3, 2);
	append_arg(args3, 3);
	append_arg(args3, 8);
	append_arg(args3, 90);
	append_arg(args3, 50);
	print_args(args);
	print_args(args3);
	i = compare_args(args, args3);
	if(i == 1){
		printf("Son iguales\n");
	} else {
		printf("No son iguales\n");
	}
	printf("\n");
	
	finish_args(args5);
	
	SYMTAB *tabla_simbolos = init_sym_tab();
	if(!tabla_simbolos) {
		printf("Ha ocurrido un error al reservar memoria para la tabla\n");
	}
	
	SYM *simbolo1 = init_sym();
	if(!simbolo1) {
		printf("Ha ocurrido un error al reservar memoria para el simbolo\n");
	}
	
	SYM *simbolo2 = init_sym();
	if(!simbolo2) {
		printf("Ha ocurrido un error al reservar memoria para el simbolo\n");
	}
	
	SYM *simbolo3 = init_sym();
	if(!simbolo3) {
		printf("Ha ocurrido un error al reservar memoria para el simbolo\n");
	}
	
	simbolo1->dir = 0;
	simbolo1->tipo = 0;
	strcpy(simbolo1->id, "x");
	simbolo1->args = args;
	simbolo1->num = 6;
	simbolo1->var = 0;
	
	simbolo2->dir = 4;
	simbolo2->tipo = 4;
	strcpy(simbolo2->id, "y");
	simbolo2->args = args1;
	simbolo2->num = 6;
	simbolo2->var = 1;
	
	simbolo3->dir = 8;
	simbolo3->tipo = 2;
	strcpy(simbolo3->id, "kjh");
	simbolo3->args = args3;
	simbolo3->num = 6;
	simbolo3->var = 3;
	
	append_sym(tabla_simbolos, simbolo1);
	append_sym(tabla_simbolos, simbolo2);
	append_sym(tabla_simbolos, simbolo3);
	
	SSTACK *pila = init_sym_tab_stack();
	if(!pila) {
		printf("Ha ocurrido un error al reservar memoria para la pila\n");
	}
	
	SYMTAB *tabla_simbolos2 = init_sym_tab();
	clear_sym_tab(tabla_simbolos2);
	SYMTAB *tabla_simbolos3 = init_sym_tab();
	clear_sym_tab(tabla_simbolos3);
	SYMTAB *tabla_simbolos4 = init_sym_tab();
	clear_sym_tab(tabla_simbolos4);
	
	push_st(pila, tabla_simbolos);
	push_st(pila, tabla_simbolos2);
	push_st(pila, tabla_simbolos3);
	push_st(pila, tabla_simbolos4);
	printf("PILA\n");
	print_stack(pila);
	
	SYMTAB p = pop_st(pila);
	printf("\nPila despues de pop\n");
	print_stack(pila);
	
	//char id[4] = "kjh";
	//char id[2] = "x";
	char id[2] = "y";
	
	printf("\n------------------------------------------\n");
	int b = getDir(tabla_simbolos, id);
	if(b >= 0){
		printf("La direccion es: %d\n", b);
	} else {
		printf("No se ha encontrado el id\n");
	
	}
	b = getTipo(tabla_simbolos, id);
	if(b >= 0){
		printf("El tipo es es: %d\n", b);
	} else {
		printf("No se ha encontrado el id\n");
	
	}
	b = getVar(tabla_simbolos, id);
	if(b >= 0){
		printf("La variable es: %d\n", b);
	} else {
		printf("No se ha encontrado el id\n");
	
	}
	b = getNumArgs(tabla_simbolos, id);
	if(b >= 0){
		printf("El numero de argumentos es: %d\n", b);
	} else {
		printf("No se ha encontrado el id\n");
	
	}
	printf("------------------------------------------\n");
	
	clear_sym_tab(tabla_simbolos);
	printf("Pila despues de clear_sym_tab\n");
	print_stack(pila);
}
