/*
 *   Recursive factorial calculation
 *   using void function;
 *   n! is returned as the second parameter
 */

int scanf( char *, ... );
int printf( char *, ... );

void factorial( int, int * );

int
main( void )
{
  int n, fact;

  printf( "Enter an integer: " );
  scanf( "%d", &n );       /* get i */
  factorial( n, &fact );   /* call factorial */
  printf( "Factorial of %d ", n );
  printf( "is %d\n", fact );
}

void
factorial( int n, int *fact )
{
  int aux;

  if ( n <= 1 )
    *fact = 1;
  else {
    aux = n - 1;
    factorial( aux, fact );
    *fact = *fact * n;
  }
}
