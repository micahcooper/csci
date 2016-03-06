#ifndef CLUB_H
#define CLUB_H

 

#include <strstream.h>
#include <unistd.h>
#include <stdlib.h>

#include <msql.h>

#include <string>

#include "ClubsException.h"
#include "DBObject.h"





class Club: public DBObject {

private:


  string  p_Name;  
  string  p_Address;
  time_t  p_Established;

public:

  // Constructors
  
  // these two will be used to create a new object
  // not yet written in the database
  //
  Club();	// required!
  Club( const char *name, const char *addr, time_t &estab );
  
  // this will be used to create a C++ proxy
  // when retrieving from database -- it has dbid -- the db identifier
  //
  Club( unsigned int dbid,
	const char *name, const char *addr, time_t &estab );
  
  // Destructors
  
  // no need to have a destructor here...
  
  // Class methods
  
  // Readers
  
  string	get_Name() const { return p_Name; }
  string	get_Address() const { return p_Address; }
  time_t	get_Established() const { return p_Established; }
  
  // Writers
  
  void	set_Name(string &name) { p_Name = name; }
  void	set_Address(string &addr) { p_Address = addr; }
  void	set_Established(time_t &estab) { p_Established = estab; }
  
  
  // Read/Write --  DBMS dependent!
  
  // DBhandle is the database communication handle
  
  // bring in an already existing Club object
  // given by its database id
  //
  static  Club      *DBRead( unsigned int dbid, int DBhandle )
    throw (ClubsException);
  
  // bring in an already existing Club object
  // given by Name
  //
  static  Club      *DBRead( string &name, int DBhandle )
    throw (ClubsException);
  
  // write this Person object to database
  //
  bool  	   DBWrite( int DBhandle )
    throw (ClubsException);
  
  
  /*
  // comparator methods
  //
  int 	  compareTo(const RWCollectable*) const;
  bool isEqual(const RWCollectable*) const;
  unsigned  hash() const;
  
  // Operators
  
  bool operator== ( const Club &t ) const
    { return isEqual( &t ); }
  bool operator!= ( const Club &t ) const
    { return !isEqual( &t ); }
  */
  
  friend
  ostream&  operator<< ( ostream &strm, const Club &p );
  
};


// Overload the << operator for a Club
//
inline
ostream&
operator<< ( ostream &strm, const Club &p )
{
  char date[256];

  cftime(date, "%D", &p.p_Established);
  strm << p.p_Name << ", " << p.p_Address << ", " 
       << date; 
  return strm;
}


class CompClubsPtr
{
public:
  bool operator() (const Club *l, const Club *r) const 
    { return l->get_Name() < r->get_Name(); }
};



#endif
