/**
 **    This example can be compiled with either C or C++ compiler
 **/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <search.h>


/*   this is an Entry   */

typedef struct {
  char *name;
  int   val;
} Entry;


/* and its comparison function -- note the explicit casts */

int
Entry_cmp( const void *e1, const void *e2)
{
  return strcmp( ((Entry*)e1)->name, ((Entry*)e2)->name );
}

void printEntry( const void *node, VISIT v, int level )
{
  Entry *e = (*(Entry **)node);

  if( v == postorder || v == leaf )
    printf( "Level: %d, %s: %d\n", level, 
	    e->name, e->val );
}


int
main ()
{
  Entry  *root = NULL;
  Entry  *stack[10];
  Entry **found;
  Entry  *new_entry;
  int     i;

  for( i = 0; i < 10; i++ )
    stack[i] = NULL;
  
  /* create a new Entry */
  new_entry = (Entry*) malloc( sizeof(Entry) );
  new_entry->name = strdup( "b" );
  new_entry->val = 11;

  /* check if already there -- note the necessary explicit cast to void**  */
  printf( "Inserting \"b\"... " );
  fflush( stdout );
  found = (Entry**) tsearch( new_entry, (void**)&root, Entry_cmp );

  /* if what was found is the new entry record, then the entry wasn't 
     there yet */
  if ( *found != new_entry )
    printf("already there\n");
  else
    printf( "done\n" );
  

  /* repeat with a couple more entries */
  new_entry = (Entry*) malloc( sizeof(Entry) );
  new_entry->name = strdup( "a" );
  new_entry->val = 12;
  printf( "Inserting \"a\"... " );
  fflush( stdout );
  found = (Entry**) tsearch( new_entry, (void**)&root, Entry_cmp );
  if ( *found != new_entry )
    printf("already there\n");
  else
    printf( "done\n" );

  new_entry = (Entry*) malloc( sizeof(Entry) );
  new_entry->name = strdup( "c" );
  new_entry->val = 13;
  printf( "Inserting \"c\"... " );
  fflush( stdout );
  found = (Entry**) tsearch( new_entry, (void**)&root, Entry_cmp );
  if ( *found != new_entry )
    printf("already there\n");
  else
    printf( "done\n" );

  /* not try to insert an already existing key */
  new_entry = (Entry*) malloc( sizeof(Entry) );
  new_entry->name = strdup( "a" );
  new_entry->val = 14;
  printf( "Inserting \"a\"... " );
  fflush( stdout );
  found = (Entry**) tsearch( new_entry, (void**)&root, Entry_cmp );

  if ( *found != new_entry )
    printf("already there\n");
  else
    printf( "done\n" );

  /* and now lookup an existing key */
  new_entry = (Entry*) malloc( sizeof(Entry) );
  new_entry->name = strdup( "b" );
  printf( "Looking up \"b\"..." );
  fflush( stdout );
  found = (Entry**) tfind( new_entry, (void**)&root, Entry_cmp );
  if ( found == NULL )
    printf("not there\n");
  else
    printf( "found it: %s val %d\n", (*found)->name, (*found)->val );

  /* and now lookup an non-existing key */
  new_entry = (Entry*) malloc( sizeof(Entry) );
  new_entry->name = strdup( "xxx" );
  printf( "Looking up \"xxx\"..." );
  fflush( stdout );
  found = (Entry**) tfind( new_entry, (void**)&root, Entry_cmp );
  if ( found == NULL )
    printf("not there\n");
  else
    printf( "found it: %s val %d\n", (*found)->name, (*found)->val );

  twalk( root, printEntry );

  return 0;
}
