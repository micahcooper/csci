#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include "cgipp.h"

#include "cgi_FindClubMembers.h"


int
main( int argc, char **argv )
{
  cgidata 	 data;
  char		*club;
  int		 i;

  for ( i=0; i < data.count(); i++) {

    if ( strcmp( data.name(i), "club_name" ) == 0 )
      club = data.value(i);

  }

  cout << "Content-type: text/html" << endl << endl;

  cgi_FindClubMembers::FindClubMembers( cout, club );

  return 0;

}
