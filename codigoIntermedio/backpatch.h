#include "cuadruplas.h"

typedef struct index INDEX;

struct index{
    char *indice;
    INDEX *next;
};

typedef struct list index {
    INDEX *head;
    INDEX *tail;

}LINDEX;

INDEX *init_index();
void finish_index(INDEX *i);

LINDEX *init_list_index(INDEX *i);
void finish_list_index(CODE *c);

void append_index(LINDEX *l, INDEX *i);

LINDEX *combinar(LINDEX l1, LINDEX l2);
void backpath(CODE *c LINDEX l, char *label);