#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include "cgipp.h"

#include "cgi_FindClubMembers.h"


int
main( int argc, char **argv )
{
  cgidata 	       data;

  cout << "Content-type: text/html" << endl << endl;

  cgi_FindClubMembers::ListAllClubs( cout );

  return 0;

}
