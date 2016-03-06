// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	PersonIterator
//
//		implementation
//
// K.J. Kochut
//
//
//


#include "PersonIterator.h"


// Return the next object
//
DBObject *
PersonIterator::GetNext()
{
  Person *np;
  
  if ( !p_Ready )		// was the query sent and the result received?
    return NULL;
  
  if ( (p_Row = msqlFetchRow(p_Result)) == NULL ) // no data received back
    return NULL;

  // Now we have the next row (tuple) from database.
  // Create a C++ proxy for the database object.
  //
  np = new Person( p_Row[0] == NULL ? 0 : atoi( p_Row[0] ), 	// Id
		   p_Row[1] == NULL ? " " : p_Row[1],		// SSN
		   p_Row[2] == NULL ? " " : p_Row[2],		// FirstName
		   p_Row[3] == NULL ? " " : p_Row[3],		// LastName
		   p_Row[4] == NULL ? " " : p_Row[4],		// Address
		   p_Row[5] == NULL ? -1 : atoi( p_Row[5] ) );	// Age

  return np;

}
  
