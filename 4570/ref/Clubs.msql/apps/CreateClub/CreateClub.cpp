#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include "cgipp.h"

#include "cgi_CreateClub.h"


int
main( int argc, char **argv )
{
  cgidata 	 data;
  char 		*club_name = NULL;
  char		*club_addr = NULL;
  int		 i;


  for ( i=0; i < data.count(); i++) {

    if ( strcmp( data.name(i), "club_name" ) == 0 ) {
      club_name = data.value(i);
    }
    else if ( strcmp( data.name(i), "club_address" ) == 0 )
      club_addr = data.value(i);

  }

  cout << "Content-type: text/html" << endl << endl;

  cgi_CreateClub::CreateClub( cout, club_name, club_addr );

  return 0;

}
