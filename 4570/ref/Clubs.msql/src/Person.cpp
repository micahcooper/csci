// Gnu Emacs C++ mode:  -*- C++ -*-
//
// Class: Person
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

#include "Person.h"
#include "ClubsException.h"


// Constructors
//
Person::Person()
	: p_FirstName(""),
	  p_LastName(""),
	  p_SSN(""),
	  p_Address("")
{
  p_Age = -1;
}

Person::Person( const char *ssn, const char *fn, const char *ln,
	        const char *addr, int age )
	: p_SSN(ssn),
	  p_FirstName(fn),
	  p_LastName(ln),
	  p_Address(addr)
{
  p_Age = age;
}


// This constructor is used in creating a proxy object in core
// The dbid is the id of the object in the database
//
Person::Person( unsigned int dbid,
	        const char *ssn, const char *fn, const char *ln,
	        const char *addr, int age )
	: DBObject( dbid ),
	  p_SSN(ssn),
	  p_FirstName(fn),
	  p_LastName(ln),
	  p_Address(addr)
{
  p_Age = age;
}


/*
// isEqual -- required for non-trivial classes
// Test two objects for equality
//
bool
Person::isEqual(const RWCollectable* prsn) const
{
  const Person *p = (const Person *) prsn; // cast to a Person pointer

  return
    p_SSN == p->p_SSN &&
    p_LastName == p->p_LastName &&
    p_FirstName == p->p_FirstName &&
    p_Address == p->p_Address &&
    p_Age == p->p_Age;
}


// hash() -- required for various collections
// If two objects are equal (i.e., isEqual) they must have
// the same hash;
// this is just an example; should be replaced by a better rule here
//
unsigned
Person::hash() const
{
  return p_SSN[0] + p_SSN[1] + p_FirstName[0] + p_Age;
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
Person::compareTo(const RWCollectable* prsn) const
{
  const Person *p = (const Person *) prsn; // cast to a Person pointer
  int lc, fc, sc;
  
  if ( !(lc = p_LastName.compareTo( p->p_LastName) ) )
    if ( !(fc = p_FirstName.compareTo( p->p_FirstName ) ) )
      return 0;
    else
      return fc;
  else
    return lc;
}
*/

// *************************
//
// mSQL persistence methods
//
// *************************

// retrieve a person with the specified dbid identifier
// DBHandle it the mSQL database access handle.
//
Person *
Person::DBRead( unsigned int dbid, int DBhandle )
     throw (ClubsException)
{
  ostrstream 	query;
  m_result 	*result;
  m_row	   	row;
  Person	*np;


  // create a query to retrieve the required Person's data (a tuple)
  //
  query << "SELECT * FROM Person WHERE Id = " << dbid << '\0';

  // run the query
  //
  if ( msqlQuery( DBhandle, query.str() ) == -1 )
    throw ClubsException( msqlErrMsg );

  // save the result
  //
  result = msqlStoreResult();

  // fetch the nex row of the result
  //
  if ( (row = msqlFetchRow(result)) == NULL ) // if NULL, problems
    throw ClubsException( "No such Person: ", dbid );
  else {

    // now, since wie have the Person tuple, recreate
    // the C++ proxy object
    //
    np = new Person( row[0] == NULL ? 0 : atoi( row[0] ), 	// Id
		     row[1] == NULL ? " " : row[1],		// SSN
		     row[2] == NULL ? " " : row[2],		// FirstName
		     row[3] == NULL ? " " : row[3],		// LastName
		     row[4] == NULL ? " " : row[4],		// Address
		     row[5] == NULL ? -1 : atoi( row[5] ) );	// Age

    // free the result structure
    //
    msqlFreeResult( result );

    // return the proxy Person object
    //
    return np;
  }
  return NULL;			// just in case...
}


// retrieve a Person with the specified SSN
// DBhandle it the mSQL database access handle.
//
// the sequence of steps is precisely the same as above;
// the only difference is the query
//
Person *
Person::DBRead( string &ssn, int DBhandle )
     throw (ClubsException)
{
  ostrstream 	query;
  m_result 	*result;
  m_row	   	row;
  Person	*np;

  query << "SELECT * FROM Person WHERE SSN = '" << ssn << "'" << '\0';

  if ( msqlQuery( DBhandle, query.str() ) == -1 )
    throw ClubsException( msqlErrMsg );

  result = msqlStoreResult();

  if ( (row = msqlFetchRow(result)) == NULL )
    throw ClubsException( "No such Person: ", ssn.data() );
  else {
    np = new Person( row[0] == NULL ? 0 : atoi( row[0] ), 	// Id
		     row[1] == NULL ? " " : row[1],		// SSN
		     row[2] == NULL ? " " : row[2],		// FirstName
		     row[3] == NULL ? " " : row[3],		// LastName
		     row[4] == NULL ? " " : row[4],		// Address
		     row[5] == NULL ? -1 : atoi( row[5] ) );	// Age

    msqlFreeResult( result );

    return np;
  }

  return NULL;			// just in case...
}



// Write this Person object to the database
// DBhandle it the mSQL database access handle.
//
bool
Person::DBWrite( int DBhandle )
     throw (ClubsException)
{
  ostrstream 	query;
  unsigned int 	dbid;
  ostrstream 	seqquery;
  m_result 	*result;
  m_row	   	row;

  // if this object has the DBid == 0 then it has never been
  // written to the database
  //
  if ( get_DBid() == 0 ) {		// write this object for the first time

    // get a new DBid for this object
    //
    seqquery << "SELECT _seq FROM Person" << '\0';

    if ( msqlQuery( DBhandle, seqquery.str() ) == -1 )
      throw ClubsException( msqlErrMsg );
    result = msqlStoreResult();

    if ( (row = msqlFetchRow(result)) != NULL )
      p_DBid = dbid = atoi( row[0] );
    else
      throw ClubsException( "Cannot get a new DBid for this Person object" );

    msqlFreeResult( result );
    
    // Now, formulate the INSERT SQL request
    //
    query << "INSERT INTO Person VALUES";
    query << "(";
    query << dbid << ",";
    query << "'" << get_SSN() << "',";
    query << "'" << get_FirstName() << "',";
    query << "'" << get_LastName() << "',";
    query << "'" << get_Address() << "',";
    query << get_Age();
    query << ")" << '\0';
  }
  else {

    // this is when the object has already been written
    // i.e. it exists in the database.
    // it will be updated
    //
    query << "UPDATE Person SET";
    query << "SSN=" << "'" << get_SSN() << "',";
    query << "FirstName=" << "'" << get_FirstName() << "',";
    query << "LastName=" << "'" << get_LastName() << "',";
    query << "Address=" << "'" << get_Address() << "',";
    query << "Age=" << get_Age();
    query << "WHERE Id = " << get_DBid() << '\0';
  }

  // now, run the query
  //
  if ( msqlQuery( DBhandle, query.str() ) == -1 )
    throw ClubsException( msqlErrMsg );
  else
    return true;

}

