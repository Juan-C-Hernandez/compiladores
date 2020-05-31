#ifndef SYMTAB_H
#define SYMTAB_H
#include <stdbool.h>
#include "datos.h"


void append_arg(ARGS∗ args, int arg); //Agrega un argumento a l f i n a l
int compare_args(ARGS ∗a1, ARGS ∗a2); //Compara dos l i s t a y devuelve 1 s i son iguales , 0 s i son d i fe ren te s
void append_sym(SYMTAB ∗t, SYM s); //Agrega a l f i n a l de la tabla un nuevo simbolo
void clear_sym_tab(SYMTAB ∗t); // Deja vacia la tabla
SYMTAB pop_st(SSTACK ∗s); // Ejecuta un pop sobre la p i la de tablas de simbolos
void push_st(SSTACK ∗s, SYMTAB ∗st); // Ing resa una tabla a la p i la de tablas de simbolos
ARGS∗ init_args(); // Retorna e l apunador a un t ipo ARGS
ARG∗ init_arg (int dato); // Reserva memoria para un t ipo ARG y reto rna e l apuntador
SSTACK∗ init_sym_tab_stack(); // Reserva memoria para la p i la
SYMTAB∗ init_sym tab(); // Reserva memoria para una tabla de simbolos vacia
SYM∗ init_sym(); // Reserva memoria para un simbolo vacio
void finish_sym_tab_stack(SSTACK ∗s); // Libe ra la memoria para la p i la
void finish_sym_tab (SYMTAB ∗st); // Libe ra memoria para una tabla de simbolos
void finish_sym(SYM ∗S); // l ibe ra memoria para un simbolo
void finish_arg(ARG ∗S); // l ibe ra memoria para un arg
void finish_args(ARGS ∗S); // l ibe ra memoria para una l i s t a ARGS
void print_tab(SYMTAB ∗t); // Imprime en pantalla la tabla de simbolos
int getDir(SYMTAB ∗T, char ∗id);
int getTipo(SYMTAB ∗T, char ∗id);
int getVar(SYMTAB ∗T, char ∗id);
ARGS∗ getArgs(SYMTAB ∗T, char ∗id);
int getNumArgs(SYMTAB ∗T, char ∗id);

#endif

