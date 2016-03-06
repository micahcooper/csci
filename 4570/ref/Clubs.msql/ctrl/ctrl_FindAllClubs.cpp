//
// A control class to implement the 'List all clubs' use case
//
//


#include <iostream.h>

#include <unistd.h>
#include <stdlib.h>

#include <string>
#include <vector>


#include <ClubIterator.h>
#include "ctrl_FindAllClubs.h"



vector<Club*>
ctrl_FindAllClubs::FindAllClubs()
    throw (ClubsException)
{
  vector<Club*>   sv;
  ClubIterator   *cit;
  Club     	 *c;
  int      	  handle;


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



  // retrieve all Club objects
  //
  cit = new ClubIterator( handle );
  cit->Reset();

  while( c = (Club*) cit->GetNext() )
    sv.insert( sv.begin(), c );

  // close the database
  //
  msqlClose( handle );

  return sv;
  
}
