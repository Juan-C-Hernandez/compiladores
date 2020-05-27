/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"

#include <stdio.h>
extern int yylex();
extern char *yytext;
void yyerror(char *s);
#line 27 "y.tab.c"

#if ! defined(YYSTYPE) && ! defined(YYSTYPE_IS_DECLARED)
/* Default: YYSTYPE is the semantic value type. */
typedef int YYSTYPE;
# define YYSTYPE_IS_DECLARED 1
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define ESTRUCTURA 257
#define INICIO 258
#define FIN 259
#define ENT 260
#define REAL 261
#define DREAL 262
#define CAR 263
#define SIN 264
#define NUM 265
#define CADENA 266
#define CARACTER 267
#define ID 268
#define DEF 269
#define SI 270
#define SINO 271
#define ENTONCES 272
#define MIENTRAS 273
#define SEGUN 274
#define HACER 275
#define TERMINAR 276
#define ESCRIBIR 277
#define LEER 278
#define DEVOLVER 279
#define CASO 280
#define PRED 281
#define VERDADERO 282
#define FALSO 283
#define SUMA 284
#define RESTA 285
#define MULT 286
#define DIV 287
#define MOD 288
#define MENOR 289
#define MAYOR 290
#define MENORI 291
#define MAYORI 292
#define IGUAL 293
#define DIF 294
#define Y 295
#define O 296
#define NO 297
#define ASIG 298
#define PYC 299
#define COMA 300
#define CIZQ 301
#define CDER 302
#define PIZQ 303
#define PDER 304
#define DOSP 305
#define PUNTO 306
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    1,    1,    1,    5,    3,    6,    6,    6,    6,
    6,    7,    7,    4,    4,    2,    2,    8,    8,   10,
   10,   11,   12,   13,   13,    9,    9,   14,   14,   14,
   14,   14,   14,   14,   14,   14,   14,   14,   14,   17,
   17,   18,   18,   15,   15,   15,   15,   15,   15,   20,
   20,   20,   20,   20,   20,   20,   19,   19,   19,   19,
   19,   19,   19,   19,   19,   19,   16,   21,   21,   21,
   22,   22,   23,   24,   24,   25,   25,
};
static const YYINT yylen[] = {                            2,
    2,    4,    4,    0,    4,    2,    1,    1,    1,    1,
    1,    4,    0,    3,    1,   11,    0,    1,    1,    3,
    1,    2,    2,    3,    0,    2,    1,    5,    7,    5,
    5,    8,    4,    3,    3,    2,    3,    2,    3,    5,
    4,    3,    0,    3,    3,    2,    1,    1,    1,    3,
    3,    3,    3,    3,    3,    1,    3,    3,    3,    3,
    3,    3,    1,    1,    1,    1,    2,    1,    1,    3,
    2,    0,    7,    1,    0,    3,    1,
};
static const YYINT yydefred[] = {                         0,
    0,    7,    8,    9,   10,   11,    0,    0,    0,    0,
    0,    0,    0,    1,   15,    0,    0,    0,    6,    0,
    0,    0,    0,    0,    0,    5,    0,    2,   14,    3,
    0,    0,   12,    0,    0,    0,    0,   21,    0,    0,
   23,    0,    0,   22,    0,    0,   20,   24,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   27,    0,    0,    0,    0,   67,    0,   69,   64,   65,
   66,   48,   49,    0,    0,    0,   63,    0,    0,    0,
    0,    0,   38,    0,    0,   36,    0,    0,   26,    0,
   39,    0,    0,    0,    0,   71,   46,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   34,   35,   37,   16,    0,
    0,   70,    0,   62,    0,   45,   44,    0,    0,   59,
   60,   61,   51,   50,   52,   53,   55,   54,    0,    0,
    0,   33,    0,    0,   28,    0,   30,    0,   31,    0,
    0,    0,    0,    0,   29,    0,    0,    0,   73,    0,
    0,   32,    0,   42,   40,
};
static const YYINT yydgoto[] = {                          7,
    8,   14,    9,   16,   10,   11,   19,   36,   60,   37,
   38,   39,   41,   61,   76,   77,  153,  158,   78,   79,
   66,   67,   68,   94,   95,
};
static const YYINT yysindex[] = {                         4,
 -249,    0,    0,    0,    0,    0,    0, -232, -225, -225,
 -254,    4,  -56,    0,    0, -239, -124, -212,    0, -203,
 -210,    4, -205,    4, -230,    0, -224,    0,    0,    0,
 -254,   79,    0,    0, -198, -215, -201,    0, -163, -194,
    0, -144,  -56,    0, -198,    4,    0,    0,   36,   36,
 -278, -238, -238, -171,   36, -161, -185, -126, -190,  -36,
    0, -162,   23, -185, -185,    0, -133,    0,    0,    0,
    0,    0,    0, -238, -185, -256,    0,   72,   -6, -229,
 -126, -104,    0, -193, -122,    0,   45, -232,    0, -185,
    0, -137,   72, -119, -114,    0,    0, -200,   36, -238,
 -238, -185, -185, -185, -185, -185, -185, -185, -185, -185,
 -185, -185,   36, -117, -238,    0,    0,    0,    0,   50,
  -99,    0, -185,    0, -251,    0,    0, -142, -142,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  -48,  -63,
 -244,    0,  -88,   72,    0,   36,    0,  -54,    0, -185,
  -24,  -29,  -37, -106,    0,  -47,  -43,   -3,    0,   36,
   36,    0,  -54,    0,    0,
};
static const YYINT yyrindex[] = {                         3,
    0,    0,    0,    0,    0,    0,    0,  263,    0,    0,
    5,   30,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    1,    0,    1,    0,    0,    0,    0,    0,    0,
    5,    0,    0, -266,   22,    0,  -12,    0,    0,    0,
    0,    0,    0,    0,   22,   49,    0,    0,    0,    0,
 -165,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   -9,    0, -132,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -44,  -42,    0,
    0,    0,    0,    0,    0,    0,    0,  263,    0,    0,
    0,    0, -204,    0,   -1,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -101,  -75,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -202,    0,    0,    0,    0,    0,    0,
    0,    0,   46,    0,    0,    0,    0,    0,    0,    0,
    0,    0, -247,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   -5,  220,  303,  308,    0,  -10,  289,    0,  271,    0,
  302,    0,  301,  -49,  -53,  -45,  184,    0,  -33,  243,
    0,    0,  227,    0,    0,
};
#define YYTABLESIZE 360
static const YYINT yytable[] = {                         80,
    4,   11,    4,   62,   62,   82,   20,  145,   12,   62,
   89,   41,   85,   89,   62,   99,   28,   62,   30,  146,
   97,   35,   64,   84,   65,   87,   69,   70,   71,   51,
   92,   93,   35,   41,   11,  114,   13,   19,  100,  101,
   49,   98,   15,   72,   73,  113,  126,  127,   18,  125,
  100,  101,   25,   62,  149,   26,  120,   27,   74,   22,
   23,  141,   29,  139,   75,  100,  101,   62,  128,  129,
  130,  131,  132,   31,   69,   70,   71,   51,   32,   69,
   70,   71,   51,  102,  103,  104,  105,  106,   42,  144,
  102,  103,  104,  105,  106,   77,  151,   76,   43,   77,
   62,   76,   40,  124,   44,  116,   72,   45,   86,   72,
  163,  164,   75,   46,   62,   62,  154,   75,   72,   72,
   72,   72,   72,   72,   72,   72,   72,   72,   72,   72,
   72,   81,   72,   72,   72,   90,   72,   83,   72,   68,
   72,   51,   68,  104,  105,  106,  102,  103,  104,  105,
  106,   68,   68,   68,   68,   68,   68,   68,   68,   68,
   68,   68,   68,   68,  121,   68,   68,   68,  115,   68,
   57,   68,   96,   57,   24,   23,  117,  102,  103,  104,
  105,  106,   57,   57,  122,  123,  140,   57,   57,   57,
   57,   57,   57,   57,   57,  159,   58,   57,   57,   58,
   57,   64,   57,    2,    3,    4,    5,    6,   58,   58,
  147,  148,  150,   58,   58,   58,   58,   58,   58,   58,
   58,   50,   88,   58,   58,  152,   58,   56,   58,   47,
   56,   51,   47,   52,  155,  156,   53,   54,   55,   56,
   57,   58,   59,  157,   56,   56,   56,   56,   56,   56,
   56,   56,   47,   47,   56,  162,   47,  160,    4,    4,
    1,  161,   17,    2,    3,    4,    5,    6,    4,    4,
    4,    4,   13,    4,    4,    4,    4,    4,    4,    4,
   50,   91,  107,  108,  109,  110,  111,  112,    4,   25,
   51,   18,   52,   50,   75,   53,   54,   55,   56,   57,
   58,   59,   74,   51,   43,   52,    4,  119,   53,   54,
   55,   56,   57,   58,   59,   21,    4,   17,    4,   33,
   63,    4,    4,    4,    4,    4,    4,    4,  102,  103,
  104,  105,  106,  102,  103,  104,  105,  106,    2,    3,
    4,    5,   34,  118,   47,   48,  165,  143,  142,  133,
  134,  135,  136,  137,  138,  102,  103,  104,  105,  106,
};
static const YYINT yycheck[] = {                         53,
    0,  268,    0,   49,   50,   55,   12,  259,  258,   55,
   60,  259,   58,   63,   60,  272,   22,   63,   24,  271,
   74,   32,  301,   57,  303,   59,  265,  266,  267,  268,
   64,   65,   43,  281,  301,   81,  269,  304,  295,  296,
   46,   75,  268,  282,  283,  275,  100,  101,  303,   99,
  295,  296,  265,   99,  299,  259,   90,  268,  297,  299,
  300,  115,  268,  113,  303,  295,  296,  113,  102,  103,
  104,  105,  106,  304,  265,  266,  267,  268,  303,  265,
  266,  267,  268,  284,  285,  286,  287,  288,  304,  123,
  284,  285,  286,  287,  288,  300,  146,  300,  300,  304,
  146,  304,  301,  304,  268,  299,  272,  302,  299,  275,
  160,  161,  303,  258,  160,  161,  150,  303,  284,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  303,  298,  299,  300,  298,  302,  299,  304,  272,
  306,  268,  275,  286,  287,  288,  284,  285,  286,  287,
  288,  284,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  296,  302,  298,  299,  300,  273,  302,
  272,  304,  306,  275,  299,  300,  299,  284,  285,  286,
  287,  288,  284,  285,  304,  300,  304,  289,  290,  291,
  292,  293,  294,  295,  296,  302,  272,  299,  300,  275,
  302,  301,  304,  260,  261,  262,  263,  264,  284,  285,
  259,  275,  301,  289,  290,  291,  292,  293,  294,  295,
  296,  258,  259,  299,  300,  280,  302,  272,  304,  272,
  275,  268,  275,  270,  259,  265,  273,  274,  275,  276,
  277,  278,  279,  281,  289,  290,  291,  292,  293,  294,
  295,  296,  295,  296,  299,  259,  299,  305,  258,  259,
  257,  305,    0,  260,  261,  262,  263,  264,  268,  269,
  270,  269,  268,  273,  274,  275,  276,  277,  278,  279,
  258,  259,  289,  290,  291,  292,  293,  294,  259,  268,
  268,  304,  270,  258,  304,  273,  274,  275,  276,  277,
  278,  279,  304,  268,  259,  270,  258,   88,  273,  274,
  275,  276,  277,  278,  279,   13,  268,   10,  270,   31,
   50,  273,  274,  275,  276,  277,  278,  279,  284,  285,
  286,  287,  288,  284,  285,  286,  287,  288,  260,  261,
  262,  263,  264,  299,   43,   45,  163,  121,  299,  107,
  108,  109,  110,  111,  112,  284,  285,  286,  287,  288,
};
#define YYFINAL 7
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 306
#define YYUNDFTOKEN 334
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"ESTRUCTURA","INICIO","FIN","ENT",
"REAL","DREAL","CAR","SIN","NUM","CADENA","CARACTER","ID","DEF","SI","SINO",
"ENTONCES","MIENTRAS","SEGUN","HACER","TERMINAR","ESCRIBIR","LEER","DEVOLVER",
"CASO","PRED","VERDADERO","FALSO","SUMA","RESTA","MULT","DIV","MOD","MENOR",
"MAYOR","MENORI","MAYORI","IGUAL","DIF","Y","O","NO","ASIG","PYC","COMA","CIZQ",
"CDER","PIZQ","PDER","DOSP","PUNTO",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : programa",
"programa : declaraciones funciones",
"declaraciones : tipo lista_var PYC declaraciones",
"declaraciones : tipo_registro lista_var PYC declaraciones",
"declaraciones :",
"tipo_registro : ESTRUCTURA INICIO declaraciones FIN",
"tipo : base tipo_arreglo",
"base : ENT",
"base : REAL",
"base : DREAL",
"base : CAR",
"base : SIN",
"tipo_arreglo : PIZQ NUM PDER tipo_arreglo",
"tipo_arreglo :",
"lista_var : lista_var COMA ID",
"lista_var : ID",
"funciones : DEF tipo ID PIZQ argumentos PDER INICIO declaraciones sentencias FIN funciones",
"funciones :",
"argumentos : lista_arg",
"argumentos : SIN",
"lista_arg : lista_arg COMA arg",
"lista_arg : arg",
"arg : tipo_arg ID",
"tipo_arg : base param_arr",
"param_arr : CIZQ CDER param_arr",
"param_arr :",
"sentencias : sentencias sentencia",
"sentencias : sentencia",
"sentencia : SI e_bol ENTONCES sentencia FIN",
"sentencia : SI e_bol ENTONCES sentencia SINO sentencia FIN",
"sentencia : MIENTRAS e_bol HACER sentencia FIN",
"sentencia : HACER sentencia MIENTRAS e_bol PYC",
"sentencia : SEGUN PIZQ variable PDER HACER casos predeterminado FIN",
"sentencia : variable ASIG expresion PYC",
"sentencia : ESCRIBIR expresion PYC",
"sentencia : LEER variable PYC",
"sentencia : DEVOLVER PYC",
"sentencia : DEVOLVER expresion PYC",
"sentencia : TERMINAR PYC",
"sentencia : INICIO sentencias FIN",
"casos : CASO NUM DOSP sentencia casos",
"casos : CASO NUM DOSP sentencia",
"predeterminado : PRED DOSP sentencia",
"predeterminado :",
"e_bol : e_bol O e_bol",
"e_bol : e_bol Y e_bol",
"e_bol : NO e_bol",
"e_bol : relacional",
"e_bol : VERDADERO",
"e_bol : FALSO",
"relacional : relacional MAYOR relacional",
"relacional : relacional MENOR relacional",
"relacional : relacional MENORI relacional",
"relacional : relacional MAYORI relacional",
"relacional : relacional DIF relacional",
"relacional : relacional IGUAL relacional",
"relacional : expresion",
"expresion : expresion SUMA expresion",
"expresion : expresion RESTA expresion",
"expresion : expresion MULT expresion",
"expresion : expresion DIV expresion",
"expresion : expresion MOD expresion",
"expresion : PIZQ expresion PDER",
"expresion : variable",
"expresion : NUM",
"expresion : CADENA",
"expresion : CARACTER",
"variable : ID variable_comp",
"variable_comp : dato_est_sim",
"variable_comp : arreglo",
"variable_comp : PIZQ parametros PDER",
"dato_est_sim : dato_est_sim PUNTO",
"dato_est_sim :",
"arreglo : CIZQ expresion CDER arreglo CIZQ expresion CDER",
"parametros : lista_parm",
"parametros :",
"lista_parm : lista_parm COMA expresion",
"lista_parm : expresion",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 118 "parser.y"

/* Sección de código de usuario */
void yyerror(char *s){
	printf("%s\t%s\n", s, yytext);
}
#line 428 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
