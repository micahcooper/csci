/*
 *   Recursive factorial calculation
 *   using integer-valued function;
 *   factorial returns n!
 */

int scanf( char *, ... );
int printf( char *, ... );

int factorial( int );

int
main( void )
{
  int n, fact;

  printf( "Enter an integer: " );
  scanf( "%d", &n );       /* get i */
  fact = factorial( n );   /* call factorial */
  printf( "Factorial of %d ", n );
  printf( "is %d\n", fact );
}

int
factorial( int n )
{
  if ( n <= 1 )
    return 1;
  else
    return n * factorial( n - 1 );
}
