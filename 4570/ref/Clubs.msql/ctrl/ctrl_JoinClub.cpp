//
// A control class to implement the 'List all clubs' use case
//
//


#include <iostream.h>

#include <unistd.h>
#include <stdlib.h>

#include <string>


#include <ClubIterator.h>
#include "ctrl_JoinClub.h"
#include "Person.h"
#include "Club.h"
#include "Membership.h"
#include "MembershipIterator.h"



void
ctrl_JoinClub::JoinClub( const char *person_ssn, const char *club_name )
    throw (ClubsException)
{
  Person	 *p;
  Club     	 *c;
  Membership 	 *m;
  MembershipIterator 	 *mit;
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


  // retrieve the necessary Person and Club objects
  //
  string ps = person_ssn;
  string cn = club_name;

  p = Person::DBRead( ps, handle );
  c = Club::DBRead( cn, handle );

  // check if already a member of this club
  //
  mit = new MembershipIterator( p, handle );
  mit->Reset();

  while ( (m = (Membership*)mit->GetNext()) != NULL )
    if ( m->get_Club() &&
	strcmp( m->get_Club()->get_Name().c_str(), c->get_Name().c_str() ) == 0 )
      throw ClubsException( "Already a member of this club" );

  // the person is not a member yet, so join...
  //
  today = time( &today );
  m = new Membership( p, c, today );
  m->DBWrite( handle );

  // close the database
  //
  msqlClose( handle );

}
