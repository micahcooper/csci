// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	ClubIterator
//
//		implementation
//
// K.J. Kochut
//
//
//


#include "ClubIterator.h"


// Return the next object
//
DBObject *
ClubIterator::GetNext()
{
  Club 		*nc;
  struct tm	*UnixDate;
  time_t	UnixTime;
  char		*msqlDate;
  time_t	time;
  
  
  if ( !p_Ready )		// was the query sent and the result received?
    return NULL;
  
  if ( (p_Row = msqlFetchRow(p_Result)) == NULL ) // no data received back
    return NULL;

  // get the date and time to the right format, ie. from MSQL date format
  // to Unix time and then to RogueWave's RWTime.
  //
  UnixTime = msqlDateToUnixTime( p_Row[3] );
  time = UnixTime;
  
  // Now we have the next row (tuple) from database.
  // Create a C++ proxy for the database object.
  //
  nc = new Club( p_Row[0] == NULL ? 0 : atoi( p_Row[0] ), 	// Id
		 p_Row[1] == NULL ? " " : p_Row[1],		// Name
		 p_Row[2] == NULL ? " " : p_Row[2],		// Address
		 time );					// Established

  return nc;

}
  
