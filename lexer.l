%{
#include <stdio.h>
#include <stdlib.h>
#include "y.tab.h"
%}

digito [0-9]
ent {digito}+
real {ent}?\.{ent}|{ent}\.{ent}?
dreal {real}d
num \-?{ent}|{real}|{dreal}
letra [a-zA-Z]
cadena \"[^\"]*\"|\'[^\']*\'
id {letra}(_|{letra}|{digito})*

%option noyywrap

%%
"estructura"    {return ESTRUCTURA;}
"inicio"    {return INICIO;}
"fin"   {return FIN;}
"ent"   {return ENT;}
"real"  {return REAL;}
"dreal" {return DREAL;}
"car"   {return CAR;}
"sin"   {return SIN;}
"si"    {return SI;}
"entonces"  {return ENTONCES;}
"sino"  {return SINO;}
"mientras"  {return MIENTRAS;}
"hacer" {return HACER;}
"segun" {return SEGUN;}
"escribir"  {return ESCRIBIR;}
"leer"  {return LEER;}
"devolver"  {return DEVOLVER;}
"terminar"  {return TERMINAR;}
"caso"  {return CASO;}
"verdadero" {return VERDADERO;}
"falso" {return FALSO;}
"def"   {return DEF;}
";"	{return PYC;}
","	{return COMA;}
"["	{return CIZQ;}
"]"	{return CDER;}
"("	{return PIZQ;}
")"	{return PDER;}
":"	{return DOSP;}
":="	{return ASIG;}
"."	{return PUNTO;}
"+"	{return SUMA;}
"-"	{return RESTA;}
"/"	{return DIV;}
"*"	{return MULT;}
"%"	{return MOD;}
"<"	{return MENOR;}
">"	{return MAYOR;}
"="	{return IGUAL;}
"<>"	{return DIF;}
"<="	{return MENOI;}
">="	{return MAYOI;}
"y"	{return Y;}
"o"	{return O;}
"no"	{return NO;}
{num}   {return NUM;}
{cadena}    {return CADENA;}
{id}    {return ID;}
[ \t\r\n]+   {}
.      {printf("Error léxico %s\n", yytext);}

%%
