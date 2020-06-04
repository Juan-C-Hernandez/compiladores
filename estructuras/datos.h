typedef struct arg ARG;

struct arg{
    int arg;
    ARG *next;
};

typedef struct args ARGS;

struct args{
    ARG *head;
    ARG *tail;
    int num; // Número de elementos en la lista
};

typedef struct sym SYM;

struct sym{
    int dir; // dirección para la variable
    int tipo; // tipo como indice a la tabla de tipos
    char id[33]; // identificador
    ARGS *args; // lista de argumentos
    int num; // numero de argumentos
    int var; // tipo de variable
    SYM *next; // apuntador al siguiente simvolo
};

typedef struct sys_tab SYMTAB;

struct sys_tab{
    SYM *head;
    SYM *tail;
    int num; // Numero de elementos en la tabla
    SYMTAB *next; //apuntador a la tabla siguiente
};

typedef struct sym_stack{
    SYMTAB *top;
    SYMTAB * tail;
}SSTACK;

typedef struct tipobase{
    int is_est; // 1: es estructura 0: es tipo simple   -1 no tiene tipo base
    union{
        SYMTAB *est;
        int tipo;
    } tipo;
}TB;

typedef struct type TYP;

struct type{
    int id;
    char nombre[12];
    TB tb;
    int tam;
    TYP *next; // apuntador al siguiente tipo en la tabla de tipos
};

typedef struct type_tab TYPTAB;

struct type_tab{
    TYP *head;
    TYP *tail;
    int num; // contador de elementos en la tabla
    TYPTAB *next; // apuntador a la tabla siguiente
};

typedef struct typ_stack{
    TYPTAB *top;
    TYPTAB *tail;
} TSTACK;
