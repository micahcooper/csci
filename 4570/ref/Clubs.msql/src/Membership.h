// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	Membership
//
//		interface
//
// K.J. Kochut
//
//
//



#ifndef MEMBERSHIP_H
#define MEMBERSHIP_H


#include <string>


#include "DBObject.h"
#include "Person.h"
#include "Club.h"
#include "ClubsException.h"


// Class Membership representing a single link between a Person object
// and a Club object from the OMT object model.
// The link is a part of the many-to-many association between
// the Person and Club classes.  The 
// association represents club memberships for a specific Person and
// a specific Club.
//
class Membership: public DBObject {

private:

  // Data members here

  Person   *p_Person;
  Club 	   *p_Club;
  time_t    p_Joined;

public:

  // Constructors

  // these two will be used to create a new object
  // not yet written in the database
  //
  Membership();	// required!
  Membership( Person *p, Club *c, time_t &j );

  // Destructors

  // no need to have a destructor here...

  // Class methods

  // Readers

  Person	*get_Person() const { return p_Person; }
  Club		*get_Club() const { return p_Club; }
  time_t	get_Joined() const { return p_Joined; }


  // Writers
  
  void	set_Person( Person *p ) { p_Person = p; }
  void	set_Club( Club *c ) { p_Club = c; }
  void	set_Joined( time_t &joined ) { p_Joined = joined; }


  // Read/Write --  DBMS dependent!

  // DBhandle is the database communication handle

  // write this Membership object to database
  //
  bool  	   DBWrite( int DBhandle )
    throw (ClubsException);


  /*
  // RWCollectable required methods

  RWBoolean isEqual(const RWCollectable*) const;
  unsigned  hash() const;

  // Operators

  RWBoolean operator== ( const Membership &t ) const
    { return isEqual( &t ); }
  RWBoolean operator!= ( const Membership &t ) const
    { return !isEqual( &t ); }
  */

  friend
  ostream&  operator<< ( ostream &strm, const Membership &p );

};


// Overload the << operator for a Membership
//
inline
ostream&
operator<< ( ostream &strm, const Membership &m )
{
  char date[256];

  cftime(date, "%D", &m.p_Joined);
  strm << *(m.p_Person) << ", " << *(m.p_Club)
       << ", " << date;
  return strm;
}

#endif
