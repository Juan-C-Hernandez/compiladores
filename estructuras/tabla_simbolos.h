#ifndef SYMTAB_H
#define SYMTAB_H
#include <stdbool.h>
#include "datos.h"

void append_arg(ARGS args, int arg); //Agrega un argumento al final
int compare_args(ARGS a1, ARGS a2); //Compara dos lista y devuelve 1 si son iguales, 0 si son diferentes
void append_sym(SYMTAB t, SYM s); //Agrega al final de la tabla un nuevo simbolo
void clear_sym_tab(SYMTAB t); // Deja vacia la tabla -------
SYMTAB pop_st(SSTACK s); // Ejecuta un pop sobre la pila de tablas de simbolos
void push_st(SSTACK s, SYMTAB st); // Ingresa una tabla a la pila de tablas de simbolos
ARGS init_args(); // Retorna e l apunador a un t ipo ARGS
ARG init_arg(int dato); // Reserva memoria para un t ipo ARG y retorna el apuntador
SSTACK init_sym_tab_stack(); // Reserva memoria para la pila
SYMTAB init_sym tab(); // Reserva memoria para una tabla de simbolos vacia
SYM init_sym(); // Reserva memoria para un simbolo vacio
void finish_sym_tab_stack(SSTACK s); // Libera la memoria para la pila
void finish_sym_tab(SYMTAB st); // Libe ra memoria para una tabla de simbolos
void finish_sym(SYM s); // libera memoria para un simbolo
void finish_arg(ARG a); // libera memoria para un arg
void finish_args(ARGS a); // libera memoria para una lista ARGS
void print_tab(SYMTAB t); // Imprime en pantalla la tabla de simbolos
int getDir(SYMTAB T, char *id);
int getTipo(SYMTAB T, char *id);
int getVar(SYMTAB T, char *id);
ARGS getArgs(SYMTAB T, char *id);
int getNumArgs(SYMTAB T, char *id);

#endif

