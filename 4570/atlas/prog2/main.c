#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int yyparse();

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
	char *file;

#ifdef YYDEBUG
  yydebug = 1;
#endif

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
/*
  if ( argc > 1 ) {

    yyin = fopen( argv[1], "r" );

    if ( yyin == NULL )
      fatal( "Cannot open input file: ", argv[1] );
  }
*/
  printf( "Result of parsing: %d\n", yyparse() );

  return 0;
}

void 
fatal( char *msg1, char *msg2 )
{
  printf( "%s%s\n", msg1, msg2 );
  exit(1);
}


