%{
unsigned charCount = 0;
unsigned wordCount = 0;
unsigned lineCount = 0;

void fatal( char *, char * );
%}

word	[^ \t\n\r]+
eol	\n

%%

{word}	{ wordCount++; charCount += yyleng; }
{eol}	{ charCount++; lineCount++; }
.	charCount++;

%%

int
main( int argc, char **argv )
{
  if ( argc > 1 ) {

    yyin = fopen( argv[1], "r" );

    if ( yyin == NULL )
      fatal( argv[0], "cannot open input file" );
  }

  while( yylex() );

  if ( argc > 1 )
    printf( "%8d%8d%8d %s\n", lineCount, wordCount, charCount, argv[1] );
  else
    printf( "%8d%8d%8d\n", lineCount, wordCount, charCount );
  
  return 0;
}

void 
fatal( char *pgm, char *msg )
{
  fprintf( stderr, "%s: %s\n", pgm, msg );
  fflush( stderr );
  exit(1);
}
