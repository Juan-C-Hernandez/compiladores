#ifndef TYPTAB_H
#define TYPTAB_H
#include "datos.h"

void append_type(TYPTAB *TT, TYP *t); // Agrega al final de la tabla un nuevo tipo
void clear_type_tab(TYPTAB *tt); // Deja vacia la tabla

TYPTAB pop_st_typ(TSTACK *s); // Ejecuta un pop sobre la pila de tablas de tipos
void push_st_typ(TSTACK *s, TYPTAB *tt); // ingresa una tabla a la pila de tabla de tipos

TSTACK *init_type_tab_stack(); // Reserva memoria para la pila
TYPTAB *init_type_tab(); // Reserva memoria para una tabla de tipos e inserta los tipos nativos
TYP *init_type(); //Reserva memoria para un tipo

void finish_typ_tab_stack(TSTACK *s); // Libera memoria para la pila
void finish_typ_tab(TYPTAB *tt); // Libera memoria para una tabla de tipos
void finish_typ(TYP *t); // libera memoria para un tipo

int getTam(TYPTAB *t, int id); // Retorna el tamaño de un tipo
TB getTipoBase(TYPTAB *t, int id); //retorna el tipo base
char *getNombre(TYPTAB *t, int id); // Retorna el nombre de un tipo
int getNum(TYPTAB *T);
void print_tab_typ(TYPTAB *t); // imprime en pantalla la tabla de tipos

TYP *busca_typ(TYP *t, int id); // Busca un id en una lista

#endif
