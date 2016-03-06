#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>


#include "cgi_FindAllPersons.h"


int
main( int argc, char **argv )
{

  cout << "Content-type: text/html" << endl << endl;

  cgi_FindAllPersons::FindAllPersons( cout );

  return 0;

}
