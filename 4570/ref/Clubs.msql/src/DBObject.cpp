// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	DBObject
//
//		Abstract class
//
//		implementation
//
// K.J. Kochut
//
//
//

// this doesn't really need a separate file at this time...



#include "DBObject.h"
#include "DBObjectIterator.h"


DBObject::DBObject( unsigned int dbid )
     : p_DBid( dbid )
{
}

