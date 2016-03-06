#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include "cgipp.h"

#include "cgi_JoinClub.h"


int
main( int argc, char **argv )
{
  cgidata 	 data;
  char 		*person = NULL;
  char		*ssn = NULL;
  char		*club = NULL;
  int		 i;


  for ( i=0; i < data.count(); i++) {

    if ( strcmp( data.name(i), "person_ssn" ) == 0 ) {
      ssn = data.value(i);
    }
    else if ( strcmp( data.name(i), "club_name" ) == 0 )
      club = data.value(i);

  }

  cout << "Content-type: text/html" << endl << endl;

  cgi_JoinClub::JoinClub( cout, ssn, club );

  return 0;

}
