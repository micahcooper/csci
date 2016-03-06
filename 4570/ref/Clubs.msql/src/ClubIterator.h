// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	ClubIterator
//
//		interface
//
// K.J. Kochut
//
//
//


#ifndef CLUBITERATOR_H
#define CLUBITERATOR_H

#include "DBObjectIterator.h"

#include "Club.h"



// This class is used to iterate over Club objects stored in
// the database
// An instance of this class is either created to iterate over
// all Club objects in the database (the first constructor),
// or Club objects found as participating in links to a specific
// Person object (the second constructor).
//
class ClubIterator: public DBObjectIterator {

public:

  // Start enumerating all Club objects in the database
  //
  ClubIterator( int DBHandle )
    : DBObjectIterator( DBHandle, "Club" ) {}

  // Iterate over Club objects which are the result of
  // an MSQL query Club objects satisfying certain criteria,
  // e.g. those linked to a specific Person object.
  //
  ClubIterator( m_result *result )
    : DBObjectIterator( result ) {}

  // Get the next Club object from the database, but already 
  // instantiated as a C++ proxy object
  //
  DBObject *GetNext();

};



#endif
