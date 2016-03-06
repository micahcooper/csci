#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "y.tab.h"

extern char *yytext;
extern int *yylineno;
extern FILE *yyin;
extern int *lineno;

int main( int argc, char **argv  )
{
	int tok;
	int paren_count = 0;
	char *file;

	if( argc == 1 )
	{
		printf( "Usage: %s 'filename.p'\n\n", argv[0] );
		exit( -1 );
	}

	if( argc > 1 )
	{
		file = calloc( strlen( argv[1] )+1, sizeof( char ) );
		file = strstr( argv[1], ".p" );
		
		if( file == NULL )
		{
			printf( "Usage: %s 'filename.p'\n\n", argv[0] );
			exit( -1 );
		}
		yyin = fopen( argv[1], "r" );
		if( yyin == NULL )
		{
			printf( "Cannot open file\n\n" );
			exit( -1 );
		}
	}

	while( tok = yylex() )
	{
		switch( tok )
		{
			case IGNORE: ;
				break;
			case LETTER: printf( "Letter: %s\n", yytext );
				break;
			case DIGIT: printf( "Digit: %s\n", yytext );
				break;
			case LPAR: 
				printf( "Left Parenthesis\n" );
				paren_count++;	
				break;
			case RPAR: 
				if( paren_count > 0 )
				{
					paren_count--;
					printf( "Right Parenthesis\n" );
				}
				else
				{
					printf( "Line %d: Unmatched parenthesis\n", lineno );
				}
				break;
			case IDENT: printf( "Identifier: %s\n", yytext );
				break;
			case UNSIGNED_INT: 
				printf( "Unsigned int: %s\n", yytext );
				break;
			case FLOAT: printf( "Float: %s\n", yytext );
				break;
			case EXP: printf( "Exponent: %s\n", yytext );
				break;
			case OPERATOR: printf( "Operator: %s\n", yytext );
				break;
			case STRING: printf( "String: %s\n", yytext );
				break;
			case COMMENT: printf( "Comment: %s\n", yytext );
				break;
			case PROCEDURE: printf( "\"procedure\" \n" );
				break;
			case BGN:	printf( "\"begin\" \n" );
				break;
			case VAR: printf( "\"var\" \n" );
				break;
			case IF: printf( "\"if\" \n" );
				break;
			case WHILE: printf( "\"while\" \n" );
				break;
			case REPEAT: printf( "\"repeat\" \n" );
				break;
			case UNTIL: printf( "\"until\" \n" );
				break;
			case THEN: printf( "\"then\" \n" );
				break;
			case ELSE: printf( "\"else\" \n" );
				break;
			case END: printf( "\"End\" \n" );
				break;
			case PROGRAM_END: printf( "\"EOF\" \n" );
				break;
			case PROGRAM: printf( "\"program\" \n" );
				break;
			case SEMI: printf( "\"SEMI\" \n" );
				break;
			case NEWLINE: 
				break;
			case ERROR: 
				printf( "Line %d: Illegal input, %s\n",lineno,yytext );
				break;
		}
	}
}
