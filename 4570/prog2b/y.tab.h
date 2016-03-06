/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENT = 258,
     VAR = 259,
     COLON = 260,
     COMMA = 261,
     SEMI = 262,
     LPAR = 263,
     RPAR = 264,
     IF = 265,
     WHILE = 266,
     PROCEDURE = 267,
     BGN = 268,
     ELSE = 269,
     END = 270,
     DO_KEYWORD = 271,
     REPEAT = 272,
     UNTIL = 273,
     THEN = 274,
     ADD_OP = 275,
     MUL_OP = 276,
     REL_OP = 277,
     STRING = 278,
     FLOAT = 279,
     UNSIGNED_INT = 280,
     ASSIGN_OP = 281,
     PROGRAM = 282,
     PROGRAM_END = 283,
     ERROR = 284,
     EXP = 285
   };
#endif
/* Tokens.  */
#define IDENT 258
#define VAR 259
#define COLON 260
#define COMMA 261
#define SEMI 262
#define LPAR 263
#define RPAR 264
#define IF 265
#define WHILE 266
#define PROCEDURE 267
#define BGN 268
#define ELSE 269
#define END 270
#define DO_KEYWORD 271
#define REPEAT 272
#define UNTIL 273
#define THEN 274
#define ADD_OP 275
#define MUL_OP 276
#define REL_OP 277
#define STRING 278
#define FLOAT 279
#define UNSIGNED_INT 280
#define ASSIGN_OP 281
#define PROGRAM 282
#define PROGRAM_END 283
#define ERROR 284
#define EXP 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

