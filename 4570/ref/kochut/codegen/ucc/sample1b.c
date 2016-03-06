/*
 * a sample program #1-b (floating point arithmetic)
 */

int scanf( char *fmt, ... );
int printf( char *fmt, ... );

int
main( void )
{
  float x, z;
  int   y;

  scanf( "%f", &x );                      /* get x */
  z = 9 + x * 8;                          /* assign to z (mixed types) */
  y = 9 + x * 8;                          /* assign to y */
  printf( "Result (int) is %d\n", y );    /* print y */
  printf( "Result (float) is %f\n", z );  /* print z */
}
