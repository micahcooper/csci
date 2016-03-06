// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	MembershipIterator
//
//		interface
//
// K.J. Kochut
//
//
//


#ifndef MEMBERSHIPITERATOR_H
#define MEMBERSHIPITERATOR_H



#include "DBObjectIterator.h"

#include "Person.h"
#include "Club.h"


enum Direction {
  Right,			// from Person to Club
  Left				// from Club to Person
};

// This class is used to iterate over Membership links stored in
// the database.
//
// An instance of this class is created to iterate over
// all links in the database (the first constructor), or
// Person objects linked to a specific
// Club object (the second constructor), or
// Club objects linked to a specific
// Person object (the third second constructor)
//
class MembershipIterator: public DBObjectIterator {

protected:

  Direction  p_Dir;
  Person    *p_Person;		// used iff p_Dir == Right
  Club	    *p_Club;		// used iff p_Dir == Left

public:

  // Start enumerating all Membership objects in the database
  // -- not really used.
  //
  MembershipIterator( int DBHandle )
    : DBObjectIterator( DBHandle, "Membership" )
      { p_Dir = Right; p_Person = NULL; p_Club = NULL; }

  // Start enumerating all Membership objects in the database
  // all having a specific Person object
  //
  MembershipIterator( Person *, int DBHandle )
    throw (ClubsException);

  // Start enumerating all Membership objects in the database
  // all having a specific Club object
  //
  MembershipIterator( Club *, int DBHandle )
    throw (ClubsException);

  // Get the next Membership object from the database, but already 
  // instantiated as a C++ proxy object
  //
  DBObject *GetNext();

};



#endif
