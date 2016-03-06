// Gnu Emacs C++ mode:  -*- C++ -*-
//
// Class:	Club
//
//		implementation
//
// K.J. Kochut
//
//
//


#include <strstream.h>
#include <unistd.h>
#include <stdlib.h>

#include <msql.h>


#include "Club.h"


// Constructors

Club::Club()
	: DBObject( 0 ),
	  p_Name(" "),
	  p_Address(" "),
	  p_Established()
{
}

Club::Club( const char *name, const char *addr, time_t &estab )
	: DBObject( 0 ),
	  p_Name(name),
	  p_Address(addr),
	  p_Established( estab )
{
}

// This constructor is used in creating a proxy object in core
// The dbid is the id of the object in the database
//
Club::Club( unsigned int dbid,
	    const char *name, const char *addr, time_t &estab )
	: DBObject( dbid ),
	  p_Name(name),
	  p_Address(addr),
	  p_Established( estab )
{
}

/*
// isEqual -- required for non-trivial classes
// Test two objects for equality
//
RWBoolean
Club::isEqual(const RWCollectable* clb) const
{
  const Club *c = (const Club *) clb; // cast to a Club pointer

  return
    p_Name == c->p_Name;
}


// hash() -- required for various collections
// If two objects are equal (i.e., isEqual) they must have
// the same hash;
// this is just an example; should be replaced by a better rule here
//
unsigned
Club::hash() const
{
  return p_Name[0] + p_Name[1] + p_Address[0];
}


// Compare two objects.
//
// If *this > p return >0, 
// if *this == p return 0, and
// if *this < p return <0.
//
// Note that we chack if:
// 	same everything (then return 0)
// 	same last names, but different first names
// 	same last and first names, but different middle names
//
// This will work nicely for sorting.
//
int
Club::compareTo(const RWCollectable* clb) const
{
  const Club *c = (const Club *) clb; // cast to a Club pointer
  int lc;
  
  if ( !(lc = p_Name.compareTo( c->p_Name) ) )
    return 0;
  else
    return lc;
}
*/


// *************************
//
// mSQL persistence methods
//
// *************************

// retrieve a club with the specified dbid identifier
// DBHandle it the mSQL database access handle.
//
//
// the sequence of steps is precisely the same as in case of
// reading a person object by DBid (see comments in Person.C)
// the only difference is the query
//
//
Club *
Club::DBRead( unsigned int dbid, int DBhandle )
	  throw (ClubsException)
{
  ostrstream 	query;
  m_result 	*result;
  m_row	   	row;
  Club		*nc;
  struct tm	*UnixDate;
  time_t	UnixTime;
  char		*msqlDate;
  time_t	 time;

  query << "SELECT * FROM Club WHERE Id = " << dbid << '\0';

  if ( msqlQuery( DBhandle, query.str() ) == -1 )
    throw ClubsException( msqlErrMsg );

  result = msqlStoreResult();
  if ( (row = msqlFetchRow(result)) == NULL )
    throw ClubsException( "No such Club: ", dbid );
  else {
    UnixTime = msqlDateToUnixTime( row[3] );
    time = UnixTime;

    nc = new Club( row[0] == NULL ? 0 : atoi( row[0] ), 	// Id
		   row[1] == NULL ? " " : row[1],		// Name
		   row[2] == NULL ? " " : row[2],		// Address
		   time );					// Established

    msqlFreeResult( result );

    return nc;
  }

  return NULL;			// just in case...
}


// retrieve a Club with the specified name.
// DBhandle it the mSQL database access handle.
//
// the sequence of steps is precisely the same as in case of
// reading a person object by SSN (see comments in Person.C)
// the only difference is the query
//
Club *
Club::DBRead( string &name, int DBhandle  )
	  throw (ClubsException)
{
  ostrstream 	query;
  m_result 	*result;
  m_row	   	row;
  Club		*nc;
  struct tm	*UnixDate;
  time_t	UnixTime;
  char		*msqlDate;
  time_t	 time;

  query << "SELECT * FROM Club WHERE Name = '" << name << "'" << '\0';

  if ( msqlQuery( DBhandle, query.str() ) == -1 )
    throw ClubsException( msqlErrMsg );

  result = msqlStoreResult();
  if ( (row = msqlFetchRow(result)) == NULL )
    throw ClubsException( "No such Club: ", name.data() );
  else {
    UnixTime = msqlDateToUnixTime( row[3] );
    time = UnixTime;

    nc = new Club( row[0] == NULL ? 0 : atoi( row[0] ), 	// Id
		   row[1] == NULL ? " " : row[1],		// Name
		   row[2] == NULL ? " " : row[2],		// Address
		   time );					// Established

    msqlFreeResult( result );

    return nc;
  }

  return NULL;			// just in case...

}


// Write this Club object to the database
// DBhandle it the mSQL database access handle.
//
// the sequence of steps is precisely the same as in case of
// writing a person object (see comments in Person.C)
// the only difference is the query
//
// also, note handling of the date
//
bool
Club::DBWrite( int DBhandle )
	  throw (ClubsException)
{
  ostrstream 	query;
  unsigned int 	dbid;
  ostrstream 	seqquery;
  m_result 	*result;
  m_row	   	row;
  struct tm	UnixDate;
  time_t	UnixTime;
  char		*msqlDate;

  msqlDate = msqlUnixTimeToDate( get_Established() );

  if ( get_DBid() == 0 ) {		// store for the first time
    
    seqquery << "SELECT _seq FROM Club" << '\0';
    if ( msqlQuery( DBhandle, seqquery.str() ) == -1 )
      throw ClubsException( msqlErrMsg );
    result = msqlStoreResult();
    if ( (row = msqlFetchRow(result)) != NULL )
      p_DBid = dbid = atoi( row[0] );
    else
      throw ClubsException( "Cannot get a new DBid for this Club object" );

    msqlFreeResult( result );
    
    query << "INSERT INTO Club VALUES";
    query << "(";
    query << dbid << ",";
    query << "'" << get_Name() << "',";
    query << "'" << get_Address() << "',";
    query << "'" << msqlDate << "'";
    query << ")" << '\0';
  }
  else {
    query << "UPDATE Club SET";
    query << "Name=" << "'" << get_Name() << "',";
    query << "Address=" << "'" << get_Address() << "',";
    query << "Established=" << "'" << msqlDate << "'";
    query << "WHERE Id = " << get_DBid() << '\0';
  }

  if ( msqlQuery( DBhandle, query.str() ) == -1 )
    throw ClubsException( msqlErrMsg );
  else
    return true;

}

