//
// A control class to implement the 'Find club members' use case
//
//


#include <iostream.h>

#include <unistd.h>
#include <stdlib.h>

#include <string>


#include <ClubIterator.h>
#include "ctrl_FindClubMembers.h"

#include "Person.h"
#include "Club.h"
#include "Membership.h"
#include "MembershipIterator.h"



vector<Person*>
ctrl_FindClubMembers::FindClubMembers( const char *club_name )
    throw (ClubsException)
{
  vector<Person*>  	 sv;
  Person   	 	*p;
  Club     	 	*c;
  Membership 	 	*m;
  MembershipIterator 	*mit;
  int      	  	 handle;


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


  // retrieve a Club object
  //
  string cn = club_name;
  c = Club::DBRead( cn, handle );

  mit = new MembershipIterator( c, handle );
  mit->Reset();

  while ( (m = (Membership*)mit->GetNext()) != NULL )
    if ( m->get_Person() != NULL )
      sv.insert( sv.begin(), m->get_Person() );

  // close the database
  //
  msqlClose( handle );

  return sv;
  
}
