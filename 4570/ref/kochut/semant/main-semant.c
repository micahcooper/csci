#include <stdio.h>
#include <stdlib.h>

int yyparse ();

void fatal( char *, char * );
void error( char *, char * );

char *pgm_name;

extern FILE *yyin;
extern int yylineno;

#ifdef YYDEBUG
extern int yydebug;
#endif

int
main( int argc, char **argv )
{
  pgm_name = argv[0];

#ifdef YYDEBUG
  yydebug = 1;
#endif

  if ( argc > 1 ) {

    yyin = fopen( argv[1], "r" );

    if ( yyin == NULL )
      fatal( "Cannot open input file: ", argv[1] );
  }

  yyparse();

  printf( "\nBye.\n" );

  return 0;
}

void 
fatal( char *msg1, char *msg2 )
{
  printf( "%s%s\n", msg1, msg2 );
  exit(1);
}



