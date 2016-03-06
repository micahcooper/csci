//
// A control class to implement the 'List all clubs' use case
//
//


#include <iostream.h>

#include <unistd.h>
#include <stdlib.h>

#include <string>


#include <ClubIterator.h>
#include "ctrl_CreateClub.h"
#include "Club.h"



void
ctrl_CreateClub::CreateClub( char *club_name, char *club_addr )
    throw (ClubsException)
{
  Club     	 *c;
  ClubIterator 	 *cit;
  int      	  handle;
  time_t	  today;


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


  // check if already exists
  //
  cit = new ClubIterator( handle );
  cit->Reset();

  while( c = (Club*) cit->GetNext() )
    if ( strcmp( c->get_Name().c_str(), club_name ) == 0 )
      throw ClubsException( "Already existing club:", club_name );

  today = time( &today );

  // now create a new Club (and date its creation)
  //
  c = new Club( club_name, club_addr,
	        today );
	       
  // now store it
  //
  c->DBWrite( handle );

  // close the database
  //
  msqlClose( handle );

}
