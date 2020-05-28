/* Sección de declaraciones */
%{
#include <stdio.h>
extern int yylex();
extern char *yytext;
void yyerror(char *s);
%}

%token ESTRUCTURA INICIO FIN
%token ENT REAL DREAL CAR SIN
%token NUM CADENA CARACTER
%token ID
%token DEF
%token SI SINO ENTONCES
%token MIENTRAS SEGUN HACER TERMINAR
%token ESCRIBIR LEER
%token DEVOLVER
%token CASO
%token PRED
%token VERDADERO FALSO

%left SUMA RESTA
%left MULT DIV MOD
%left MENOR MAYOR MENORI MAYORI IGUAL DIF
%left Y O NO
%left ASIG

%nonassoc PYC COMA CIZQ CDER PIZQ PDER DOSP PUNTO

%start programa

%%
/* Seccioón del Esquema de traducción */
programa: declaraciones funciones;

declaraciones: tipo lista_var PYC declaraciones | tipo_registro lista_var PYC declaraciones |;

tipo_registro: ESTRUCTURA INICIO declaraciones FIN;

tipo: base tipo_arreglo;

base: ENT | REAL | DREAL | CAR | SIN;

tipo_arreglo: PIZQ NUM PDER tipo_arreglo | ;

lista_var: lista_var COMA ID | ID;

funciones: DEF tipo ID PIZQ argumentos PDER INICIO declaraciones sentencias FIN funciones | ;

argumentos: lista_arg | SIN;

lista_arg: lista_arg COMA arg | arg;

arg: tipo_arg ID;

tipo_arg: base param_arr;

param_arr: CIZQ CDER param_arr | ;

sentencias: sentencias sentencia | sentencia;

sentencia: SI e_bol ENTONCES sentencia FIN
	| SI e_bol ENTONCES sentencia SINO sentencia FIN
	| MIENTRAS e_bol HACER sentencia FIN
	| HACER sentencia MIENTRAS e_bol PYC
	| SEGUN PIZQ variable PDER HACER casos predeterminado FIN
	| variable ASIG expresion PYC
	| ESCRIBIR expresion PYC
	| LEER variable PYC
	| DEVOLVER PYC
	| DEVOLVER expresion PYC
	| TERMINAR PYC
	| INICIO sentencias FIN;
	
casos: CASO NUM DOSP sentencia casos
	| CASO NUM DOSP sentencia;

predeterminado: PRED DOSP sentencia | ;

e_bol: e_bol O e_bol
	| e_bol Y e_bol
	| NO e_bol
	| relacional
	| VERDADERO
	| FALSO;

relacional: relacional MAYOR relacional
	| relacional MENOR relacional
	| relacional MENORI relacional
	| relacional MAYORI relacional
	| relacional DIF relacional
	| relacional IGUAL relacional
	| expresion;

expresion: expresion SUMA expresion
	| expresion RESTA expresion
	| expresion MULT expresion
	| expresion DIV expresion
	| expresion MOD expresion
	| PIZQ expresion PDER
	| variable
	| NUM | CADENA | CARACTER;
	
variable: ID variable_comp;

variable_comp: dato_est_sim | arreglo | PIZQ parametros PDER;

dato_est_sim: dato_est_sim PUNTO ID| ;

arreglo: CIZQ expresion CDER | arreglo CIZQ expresion CDER;
	
parametros: lista_parm | ;

lista_parm: lista_parm COMA expresion | expresion;

%%
/* Sección de código de usuario */
void yyerror(char *s){
	printf("%s\t%s\n", s, yytext);
}
