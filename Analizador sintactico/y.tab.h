/* A Bison parser, made by GNU Bison 3.6.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ESTRUCTURA = 258,              /* ESTRUCTURA  */
    INICIO = 259,                  /* INICIO  */
    FIN = 260,                     /* FIN  */
    ENT = 261,                     /* ENT  */
    REAL = 262,                    /* REAL  */
    DREAL = 263,                   /* DREAL  */
    CAR = 264,                     /* CAR  */
    SIN = 265,                     /* SIN  */
    NUM = 266,                     /* NUM  */
    CADENA = 267,                  /* CADENA  */
    CARACTER = 268,                /* CARACTER  */
    ID = 269,                      /* ID  */
    DEF = 270,                     /* DEF  */
    SI = 271,                      /* SI  */
    SINO = 272,                    /* SINO  */
    ENTONCES = 273,                /* ENTONCES  */
    MIENTRAS = 274,                /* MIENTRAS  */
    SEGUN = 275,                   /* SEGUN  */
    HACER = 276,                   /* HACER  */
    TERMINAR = 277,                /* TERMINAR  */
    ESCRIBIR = 278,                /* ESCRIBIR  */
    LEER = 279,                    /* LEER  */
    DEVOLVER = 280,                /* DEVOLVER  */
    CASO = 281,                    /* CASO  */
    PRED = 282,                    /* PRED  */
    VERDADERO = 283,               /* VERDADERO  */
    FALSO = 284,                   /* FALSO  */
    SUMA = 285,                    /* SUMA  */
    RESTA = 286,                   /* RESTA  */
    MULT = 287,                    /* MULT  */
    DIV = 288,                     /* DIV  */
    MOD = 289,                     /* MOD  */
    MENOR = 290,                   /* MENOR  */
    MAYOR = 291,                   /* MAYOR  */
    MENORI = 292,                  /* MENORI  */
    MAYORI = 293,                  /* MAYORI  */
    IGUAL = 294,                   /* IGUAL  */
    DIF = 295,                     /* DIF  */
    Y = 296,                       /* Y  */
    O = 297,                       /* O  */
    NO = 298,                      /* NO  */
    ASIG = 299,                    /* ASIG  */
    PYC = 300,                     /* PYC  */
    COMA = 301,                    /* COMA  */
    CIZQ = 302,                    /* CIZQ  */
    CDER = 303,                    /* CDER  */
    PIZQ = 304,                    /* PIZQ  */
    PDER = 305,                    /* PDER  */
    DOSP = 306,                    /* DOSP  */
    PUNTO = 307                    /* PUNTO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ESTRUCTURA 258
#define INICIO 259
#define FIN 260
#define ENT 261
#define REAL 262
#define DREAL 263
#define CAR 264
#define SIN 265
#define NUM 266
#define CADENA 267
#define CARACTER 268
#define ID 269
#define DEF 270
#define SI 271
#define SINO 272
#define ENTONCES 273
#define MIENTRAS 274
#define SEGUN 275
#define HACER 276
#define TERMINAR 277
#define ESCRIBIR 278
#define LEER 279
#define DEVOLVER 280
#define CASO 281
#define PRED 282
#define VERDADERO 283
#define FALSO 284
#define SUMA 285
#define RESTA 286
#define MULT 287
#define DIV 288
#define MOD 289
#define MENOR 290
#define MAYOR 291
#define MENORI 292
#define MAYORI 293
#define IGUAL 294
#define DIF 295
#define Y 296
#define O 297
#define NO 298
#define ASIG 299
#define PYC 300
#define COMA 301
#define CIZQ 302
#define CDER 303
#define PIZQ 304
#define PDER 305
#define DOSP 306
#define PUNTO 307

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
