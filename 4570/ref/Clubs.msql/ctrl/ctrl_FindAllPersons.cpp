//
// A control class to implement the 'Find all persons' use case
//
//


#include <iostream.h>

#include <unistd.h>
#include <stdlib.h>

#include <string>
#include <vector>


#include <PersonIterator.h>
#include "ctrl_FindAllPersons.h"




vector<Person*>
ctrl_FindAllPersons::FindAllPersons()
    throw (ClubsException)
{
  vector<Person*>  sv;
  PersonIterator  *pit;
  Person     	  *p;
  int      	   handle;


  // load the specific configuration file
  //
  if ( msqlLoadConfigFile( "/web/kochut/public_html/msql.conf" ) == -1 )
    throw ClubsException( msqlErrMsg );

  // connect to the database server on ajax
  //
  if ( ( handle = msqlConnect( "ajax.cs.uga.edu" ) ) == -1 )
    throw ClubsException( msqlErrMsg );

  // open database 'clubs'
  //
  if ( msqlSelectDB( handle, "clubs" ) == -1 )
    throw ClubsException( msqlErrMsg );



  // retrieve all Person objects
  //
  pit = new PersonIterator( handle );
  pit->Reset();

  while( p = (Person*) pit->GetNext() )
    sv.insert( sv.begin(), p );

  // close the database
  //
  msqlClose( handle );

  return sv;
  
}
