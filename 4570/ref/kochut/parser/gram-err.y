/* 
 * %term is another way to declare tokens for YACC 
 */
%token A B C D E

%{

#include <stdio.h>

void yyerror( const char *msg );
void error( const char *msg );
int yylex( void );
extern int yylineno;

%}

/*
   Grammar: 
   
     S  ->  'a'  A   B  'e'
     A  ->   A  'b' 'c'   |   'b'
     B  ->  'd'

*/


%%
s:  A a b E
      |
    A a b error
	{   
	  /* this error is due to a missing 'e' */
	  error( "Expected 'e'" ); 
	  yyclearin;
	  yyerrok;
	}
      |
    error
	{   
	  /* this error is due to the inability of reducing by any of
	     the s-productions */
	  error( "Error in S" );
	  /*
	  yyclearin;
	  yyerrok;
	  */
	}
     ;

a:  a B C
     |
    a B error
	{   
	  /* now we are missing a 'c' */
	  error( "Expected 'c'" );
	  yyclearin;
	  yyerrok;
	}
     |
    a error
	{  
	  /* now we are missing a 'b' */
	  error( "Expected 'b'" );
	  yyclearin;
	  /*
	  yyerrok;
	  */
	}
     |
    B
     |
    error
	{  
	  /* now we cannot parse A */
	  error( "Error in A" );
	  yyclearin;
	  yyerrok;
	}
     ;

b:  D
     ;


%%
#ifdef YYDEBUG
extern int yydebug;
#endif
extern int yylineno;

/*
main (int argc, char **argv)
{

#ifdef YYDEBUG
  if (argc > 1) yydebug = 1;
  else yydebug = 0;
#endif

  printf("Result is %d\n", yyparse());
}
*/
/* this is a "silent" yyerror function */
void
yyerror( const char *msg )
{
/*  printf("Line %d: %s\n", yylineno, msg); */
}

/*
void 
error( const char *msg )
{
  fprintf( stderr, "Line %d: %s\n", yylineno, msg );
  fflush( stderr );
}
*/
