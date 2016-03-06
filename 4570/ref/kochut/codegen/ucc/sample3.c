/*
 * a sample program #3
 */

int scanf( char *fmt, ... );
int printf( char *fmt, ... );

int count( int );

int sum;

int
main( void )
{
  int i;

  scanf( "%d", &i);              /* get i */
  count(i);                      /* call count */
  printf( "%d\n", sum );         /* write result */
}

void
count( int n )
{
  int i;

  i = 1;
  sum = 0;
  while ( i <= n ) {
    sum = sum + i;
    i = i + 1;
  }
}
