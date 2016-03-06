// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	PersonIterator
//
//		interface
//
// K.J. Kochut
//
//
//


#ifndef PERSONITERATOR_H
#define PERSONITERATOR_H


#include "DBObjectIterator.h"

#include "Person.h"


// This class is used to iterate over Person objects stored in
// the database
// An instance of this class is either created to iterate over
// all Person objects in the database (the first constructor),
// or Person objects found as participating in links to a specific
// Club object (the second constructor).
//
class PersonIterator: public DBObjectIterator {

public:

  // Start enumerating all Person objects in the database
  //
  PersonIterator( int DBHandle )
    : DBObjectIterator( DBHandle, "Person" ) {}

  // Iterate over Person objects which are the result of
  // an MSQL query Person objects satisfying certain criteria,
  // e.g. those linked to a specific Club object.
  //
  PersonIterator( m_result *result )
    : DBObjectIterator( result ) {}

  // Get the next Person object from the database, but already 
  // instantiated as a C++ proxy object
  //
  DBObject *GetNext();

};



#endif
