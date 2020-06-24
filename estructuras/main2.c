#include "tabla_tipos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_typ(TYP *tipo){
    TYP *tmp = tipo;
    while(tmp){
        printf("ID: %d\nNombre: %s\nTam: %d\nMemoria %p\n\n", tmp->id, tmp->nombre, tmp->tam, tmp);
        tmp = tmp->next;
    }
}

void print_stack_typ(TSTACK *s){
    TYPTAB *tmp = s->top;
    if(!tmp){
        printf("Nada que imprimir\n");
    } else{
        printf("Imprimiendo pila:\n");
        while(tmp != NULL){
        print_tab_typ(tmp);
        tmp = tmp->next;
    }
    }
}


int main(int arc, char **argv){

    // PRUEBA INIT
	TSTACK *pila = init_type_tab_stack();
	if(!pila){
	    printf("Error al crear la pila\n");
	    return -1;
    }

    TYPTAB *tabla = init_type_tab();
    if(!pila){
	    printf("Error al crear la tabla\n");
	    return -1;
    }

    // PRUEBA DE TIPOS
    TYP *tipo1 = init_type();
    TYP *tipo2 = init_type();
    TYP *tipo3 = init_type();

    tipo1->id = 0;
    strcpy(tipo1->nombre, "ent");
    tipo1->tam = 8;
    print_typ(tipo1);

    tipo2->id = 1;
    strcpy(tipo2->nombre, "real");
    tipo2->tam = 8;
    print_typ(tipo2);

    tipo3->id = 2;
    strcpy(tipo3->nombre, "dreal");
    tipo3->tam = 16;
    print_typ(tipo3);
    printf("\n");

    // PRUEBA APPEND TABLAS
    printf("Imprimiendo tabla vacia\n");
    print_tab_typ(tabla);
    printf("\n");

    append_type(tabla, tipo1);
    printf("Se salio de append, la lista tiene ahora %d elementos\n\n", getNum(tabla));

    append_type(tabla, tipo2);
    printf("Se salio de append, la lista tiene ahora %d elementos\n\n", getNum(tabla));

    append_type(tabla, tipo3);
    printf("Se salio de append, la lista tiene ahora %d elementos\n\n", getNum(tabla));

    // PRUEBA IMPRIMIR TABA 
    print_tab_typ(tabla);

    // PRUEBA BUSQUEDAS 
    int id_a_buscar = 2;
    TYP *tipo_busqueda = busca_typ(tabla->head, id_a_buscar);
    printf("Resultado de busqueda de id %d:\n", id_a_buscar);
    if(!tipo_busqueda){
        printf("El id %d no esta en la tabla\n", id_a_buscar);
    } else{
        print_typ(tipo_busqueda);
    }
    char *nombre_id_a_buscar = getNombre(tabla, id_a_buscar);
    if(!nombre_id_a_buscar){
        printf("El nombre de %d no se ha encontrado\n", id_a_buscar);
    } else{
        printf("El nombre de %d es %s\n", id_a_buscar, nombre_id_a_buscar);
    }
    int tam = getTam(tabla, id_a_buscar);
    if(!tam){
        printf("El tamaño de %d no se ha encontrado\n", id_a_buscar);
    } else{
        printf("El tamaño de %d es %d\n", id_a_buscar, tam);
    }
    printf("\n");

    id_a_buscar = 5;
    tipo_busqueda = busca_typ(tabla->head, id_a_buscar);
    printf("Resultado de busqueda de id %d:\n", id_a_buscar);
    if(!tipo_busqueda){
        printf("El id %d no esta en la tabla\n", id_a_buscar);
    } else{
        print_typ(tipo_busqueda);
    }
    char *nombre_id_a_buscar2 = getNombre(tabla, id_a_buscar);
    if(!nombre_id_a_buscar2){
        printf("El nombre de %d no se ha encontrado\n", id_a_buscar);
    } else{
        printf("El nombre de %d es %s\n", id_a_buscar, nombre_id_a_buscar2);
    }
    tam = getTam(tabla, id_a_buscar);
    if(!tam){
        printf("El tamaño de %d no se ha encontrado\n", id_a_buscar);
    } else{
        printf("El tamaño de %d es %d\n", id_a_buscar, tam);
    }
    printf("\n");
    printf("\n");

    // PRUEBA PILA
    printf("Imprimiendo pila vacia\n");
    print_stack_typ(pila);
    printf("\n");

    TYPTAB *tabla2 = init_type_tab(); // INIT FUNCIONA
    TYP *tipo4 = init_type();
    TYP *tipo5 = init_type();
    TYP *tipo6 = init_type();

    tipo4->id = 0;
    strcpy(tipo4->nombre, "int");
    tipo4->tam = 9;

    tipo5->id = 1;
    strcpy(tipo5->nombre, "float");
    tipo5->tam = 15;

    tipo6->id = 2;
    strcpy(tipo6->nombre, "long");
    tipo6->tam = 32;

    append_type(tabla2, tipo4);
    append_type(tabla2, tipo5);
    append_type(tabla2, tipo6);


    TYPTAB *tabla3 = init_type_tab();
    TYP *tipo7 = init_type();
    TYP *tipo8 = init_type();
    TYP *tipo9 = init_type();
    TYP *tipo10 = init_type();

    tipo7->id = 0;
    strcpy(tipo7->nombre, "cadena");
    tipo7->tam = 64;

    tipo8->id = 1;
    strcpy(tipo8->nombre, "arreglo");
    tipo8->tam = 4;

    tipo9->id = 2;
    strcpy(tipo9->nombre, "apuntador");
    tipo9->tam = 2;

    tipo10->id = 3;
    strcpy(tipo10->nombre, "size");
    tipo10->tam = 3;

    append_type(tabla3, tipo7);
    append_type(tabla3, tipo8);
    append_type(tabla3, tipo9);
    append_type(tabla3, tipo10);

    push_st_typ(pila, tabla);
    push_st_typ(pila, tabla2);
    push_st_typ(pila, tabla3);
    printf("Imprimiendo pila\n");
    print_stack_typ(pila);
    printf("\n");

    clear_type_tab(tabla2);
    printf("Imprimiendo pila despues de limpiar tabla %p\n", tabla2);
    print_stack_typ(pila);
    printf("\n");

    printf("Pop a la pila\n");
    TYPTAB popped = pop_st_typ(pila);
    printf("Imprimiendo pila despues de pop\n");
    print_stack_typ(pila);
    printf("\n");
    printf("Elemento eliminado: \n");
    print_tab_typ(&popped);
}
