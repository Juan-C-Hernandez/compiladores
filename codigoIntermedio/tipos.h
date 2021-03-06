#ifndef TIPOS_H
#define TIPOS_H

#include "cuadruplas.h"

#if defined(_WIN32)
#include "..\estructuras\tabla_tipos.h"
#define OS 0
#elif defined(__linux__) || defined(__unix__)
#include "../estructuras/tabla_tipos.h"
#define OS 1
#endif

extern TSTACK *pila_tabla_tipo;

/*
*Recibe dos t ipo s , cada uno es su indice hacia la tabla de tipos en la cima de la pila
* Si el primero es mas grande que el segundo genera la cuadrupla
* para realizar la reduccion del t ipo .
* Retorna la nueva di reccion generada por la reduccion
* o la di reccion original en caso de que no se realice
*/

char *ampliar(char *dir, int t1, int t2, CODE *c);

/*
*Recibe dos tipos , cada uno es su indice hacia la tabla de tipos en la cima de la pila
* Si el primero es mas grande que el segundo genera la cuadrupla
* para realizar la reduccion del tipo .
* Retorna la nueva di reccion generada por la reduccion
* o la di reccion original en caso de que no se realice
*/

char *reducir();

/*
* Recibe dos tipos , cada uno es indice hacia la tabla de tipos en la cima de la pila
* retorna el indice de mayor dimension
*/
int max(int t1, int t2);

/*
* Recibe dos tipos , cada uno es indice hacia la tabla de tipos en la cima de la pila
* retorna el indice de menor dimension
*/
int min(int t1, int t2);

#endif
