// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	DBObject
//
//		Abstract class
//
//		interface
//
// K.J. Kochut
//
// 
//



#ifndef DBOBJECT_H
#define DBOBJECT_H




// This is the root class of any classes that are saved in
// a database.  This is an abstract class, requiring
// that every derived class provides a method DBWrite.
//
// Each DBObject has a unique (per database table) identifier,
// stored in the member p_DBid.
//
class DBObject {

protected:

  // object id
  
  unsigned int p_DBid;	// only for retrieval from DB
  
public:
  
  // constructors
  
  DBObject( unsigned int dbid = 0 );
  
  
  // Methods
  //
  
  // readers
  //
  unsigned int	get_DBid() const { return p_DBid; }
  
  
  // writers
  
  // no writes -- clients must not write p_DBid directly;
  // p_DBid will be set *only* after the object has been
  // written to database for the first time
  // the p_DBid will be used for this object thereafter
  
  
  // a pure virtual method --
  //      required of all derived classes
  //
  // Write this DBobject to database
  // access by the handle DBhandle
  //
  virtual bool  DBWrite( int DBhandle ) = 0;

};


#endif
