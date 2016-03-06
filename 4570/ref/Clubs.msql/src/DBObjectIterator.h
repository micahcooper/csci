// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	DBObjectIterator
//
//		Abstract class
//
//		interface
//
// K.J. Kochut
//
//
//


#ifndef DBOBJECT_ITERATOR_H
#define DBOBJECT_ITERATOR_H


#include <strstream.h>
#include <unistd.h>
#include <stdlib.h>

#include <string>

#include <msql.h>

#include "DBObject.h"



// This is the root class of any classes that iterate over objects
// saved in a database.  This is an abstract class, requiring
// that every derived class provides a method GetNext.
//
// Each DBObjectIterator has a query string, the result structure.
// The p_Ready indicates if the results are pending (the query has
// been sent and process by the MSQL server), i.e. if we can
// start calling GetNext.
//
class DBObjectIterator {

protected:

  ostrstream 	 p_Query;
  m_result 	*p_Result;
  m_row	   	 p_Row;
  int	 	 p_Handle;

  bool		 p_Ready;

public:

  // this constructor is used to start iterating over all of the
  // objects ina particular table
  //
  DBObjectIterator( int DBhandle )
    { p_Handle = DBhandle; }

  // this constructor is used to start iterating over all of the
  // objects ina particular table
  //
  DBObjectIterator( int DBhandle, const char *table );

  // this constructor is used to start iterating over
  // a query result
  //
  DBObjectIterator( m_result *result );

  // destructor
  //
  ~DBObjectIterator();

  // Run the query and store the resulting rows for processing
  // This method sets the p_Ready data member.
  //
  bool Reset();

  // get the next objects;
  // return null if there are no more objects
  //
  virtual DBObject *GetNext() = 0;

};


#endif
