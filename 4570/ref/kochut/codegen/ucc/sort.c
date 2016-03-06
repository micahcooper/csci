/*
 * a sample program #1
 */

int scanf( char *fmt, ... );
int printf( char *fmt, ... );

void
print( int b[] )
{
  int i;

  i = 0;
  while (i < 5) {
    printf( "value %d ", i+1 );
    printf( " = %d\n", b[i] );
    i = i + 1;
  }
}

void
sort( int c[] )
{
  int i, j, temp;

  i = 0;
  while ( i < 4 ) {
    j = i + 1;
    while (j < 5) {
      if ( c[i] > c[j] ) {
	temp = c[i];
	c[i] = c[j];
	c[j] = temp;
      }
      j = j + 1;
    }
    i = i + 1;
  }
}

int
main( void )
{
  int a[10];
  int i;

  printf("Please enter 5 integers for sorting.\n\n");

  i = 0;
  while (i < 5) {
    printf( "enter an integer for sorting: " );
    scanf( "%d", &a[i] );
    i = i + 1;
  }

  printf( "the original input:\n" );
  print( a );
  sort( a );
  printf( "the sorted numbers:\n");
  print(a);
}
