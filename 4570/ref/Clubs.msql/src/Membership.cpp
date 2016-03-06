// Gnu Emacs C++ mode:  -*- C++ -*-
//
// Class: Membership
//
//	  implementation
//
//
// K.J. Kochut
//
//


#include <strstream.h>
#include <unistd.h>
#include <stdlib.h>

#include <msql.h>


#include "Membership.h"
#include "ClubsException.h"



// Constructors
//
Membership::Membership()
	: p_Person( NULL ),
	  p_Club( NULL ),
	  p_Joined()
{
}

Membership::Membership( Person *p, Club *c, time_t &joined )
	: p_Person(p),
	  p_Club(c),
	  p_Joined( joined )
{
}


/*
// isEqual -- required for non-trivial classes
// Test two objects for equality
//
RWBoolean
Membership::isEqual(const RWCollectable* memb) const
{
  const Membership *p = (const Membership *) memb; // cast to a Membership pointer

  return
    p_Person == p->p_Person &&
    p_Club == p->p_Club;
}


// hash() -- required for various collections
// If two objects are equal (i.e., isEqual) they must have
// the same hash;
// this is just an example; should be replaced by a better rule here
//
unsigned
Membership::hash() const
{
  return (unsigned)p_Person + (unsigned)p_Club;
}
*/


// *************************
//
// mSQL persistence methods
//
// *************************


// Reading Membership objects will be done only inside
// the MembershipIterator methods.

// Write this Membership object to the database
// DBhandle it the mSQL database access handle.
//
bool
Membership::DBWrite( int DBhandle )
     throw (ClubsException)
{
  unsigned int  PersonDBid = p_Person->get_DBid();
  unsigned int  ClubDBid = p_Club->get_DBid();
  ostrstream 	query;
  ostrstream 	squery;
  m_result 	*result;
  time_t	utctime;
  struct tm	UnixDate;
  time_t	UnixTime;
  char		*msqlDate;
  int           no;

  if ( PersonDBid == 0 )
    throw ClubsException( "The Person object has not been written yet: ",
			  p_Person->get_SSN().data() );

  if ( ClubDBid == 0 )
     throw ClubsException( "The Club object has not been written yet: ",
			   p_Club->get_Name().data() );
    
  utctime = time( &utctime );
  UnixTime = utctime;
  msqlDate = msqlUnixTimeToDate( UnixTime );
    

  // check if such a link already exists
  //
  squery << "SELECT * FROM Membership WHERE ";
  squery << "personid = " << PersonDBid << " and ";
  squery << "clubid = " << ClubDBid << '\0';

  // run the query
  //
  if ( ( no = msqlQuery( DBhandle, squery.str() ) ) == -1 )
    throw ClubsException( msqlErrMsg );

  if ( no > 0 )			// this means that at least one tuple
    throw ClubsException( "Attempt to create duplicate link between: ",
			  p_Person->get_SSN().data(),
			  p_Club->get_Name().data() );

  query << "INSERT INTO Membership VALUES";
  query << "(";
  query << PersonDBid << ",";
  query << ClubDBid << ",";
  query << "'" << msqlDate << "'";
  query << ")" << '\0';

  if ( msqlQuery( DBhandle, query.str() ) == -1 )
    throw ClubsException( msqlErrMsg );

  return true;
  
}

