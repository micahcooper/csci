#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include "cgipp.h"

#include "ctrl_JoinClub.h"


int
main( int argc, char **argv )
{
  cgidata 	       data;

  cout << "Content-type: text/html" << endl << endl;

  ctrl_JoinClub::FindAllClubs( cout );

  return 0;

}
