typedef struct cuad QUAD;

struct cuad{
    char *op;
    char *arg1;
    char *arg2;
    char *res;
    CUAD *next;

};

typedef struct code{
    /* data */
    CUAD *head;
    CUAD *tail;

}CODE;


CUAD *init_quad(); //
void finish_quad(QUAD *c); //

CODE *init_code(); //
void finish_code(CODE *c); //

void append_quad(CODE* C, CUAD *cd);