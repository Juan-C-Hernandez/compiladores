#include "tipos.h"

/*
* Recibe dos tipos , cada uno es indice hacia la tabla de tipos en la cima de la pila
* retorna el indice de mayor dimension
*/
int max(int t1, int t2) {
	return getTam(pila_tabla_tipo->top, t1) > getTam(pila_tabla_tipo->top, t2) ? t1 : t2;
}

/*
* Recibe dos tipos , cada uno es indice hacia la tabla de tipos en la cima de la pila
* retorna el indice de menor dimension
*/
int min(int t1, int t2) {
	return getTam(pila_tabla_tipo->top, t1) < getTam(pila_tabla_tipo->top, t2) ? t1 : t2;
}
