// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	Person
//
//		interface
//
// K.J. Kochut
//
//
//



#ifndef PERSON_H
#define PERSON_H


#include <string>


#include "DBObject.h"
#include "ClubsException.h"


// Class Person representing the Person class from the OMT object model
// It has a many-to-many association with the Person class.  The
// association represents club memberships.
//
class Person: public DBObject {

private:

  // Data members here
  
  string  p_SSN;
  string  p_FirstName;  
  string  p_LastName;
  string  p_Address;
  int	  p_Age;
  
public:
  
  // Constructors
  
  // these two will be used to create a new object
  // not yet written in the database
  //
  Person();	// required!
  Person( const char *ssn, const char *fn, const char *ln,
	  const char *addr, int age );
  
  // this will be used to create a C++ proxy
  // when retrieving from database -- it has dbid -- the db identifier
  //
  Person( unsigned int dbid,
	  const char *ssn, const char *fn, const char *ln,
	  const char *addr, int age );
  
  // Destructors
  
  // no need to have a destructor here...
  
  // Class methods
  
  // Readers
  
  string	get_SSN() const { return p_SSN; }
  string	get_FirstName() const { return p_FirstName; }
  string	get_LastName() const { return p_LastName; }
  string	get_Address() const { return p_Address; }
  int		get_Age() const { return p_Age; }
  
  // Writers
  
  void	set_SSN(string &ssn) { p_SSN = ssn; }
  void	set_FirstName(string &fn) { p_FirstName = fn; }
  void	set_LastName(string &ln) { p_LastName = ln; }
  void	set_Address(string &addr) { p_Address = addr; }
  void	set_Age(int age) { p_Age = age; }
  
  
  // Read/Write --  DBMS dependent!
  
  // DBhandle is the database communication handle
  
  // bring in an already existing Person object
  // given by its database id
  //
  static  Person    *DBRead( unsigned int dbid, int DBhandle )
    throw (ClubsException);
  
  // bring in an already existing Person object
  // given by SSN
  //
  static  Person    *DBRead( string &ssn, int DBhandle )
    throw (ClubsException);
  
  // write this Person object to database
  //
  bool  	   DBWrite( int DBhandle )
    throw (ClubsException);
  
  
  
  /*
  // RWCollectable required methods
  
  int 	    compareTo(const RWCollectable*) const;
  bool      isEqual(const RWCollectable*) const;
  unsigned  hash() const;
  
  // Operators
  
  bool operator== ( const Person &t ) const
    { return isEqual( &t ); }
  bool operator!= ( const Person &t ) const
    { return !isEqual( &t ); }
  */
  
  friend
  ostream&  operator<< ( ostream &strm, const Person &p );
  
};


// Overload the << operator for a Person
//
inline
ostream&
operator<< ( ostream &strm, const Person &p )
{
  strm << p.p_LastName << ", " << p.p_FirstName
       << ", " << p.p_SSN << ", " << p.p_Age << ", " << p.p_Address;
  return strm;
}

class CompPersonPtr
{
public:
  bool operator() (const Person *l, const Person *r) const 
    { 
      if( l->get_LastName() == r->get_LastName() )
	return l->get_FirstName() == r->get_FirstName(); 
      else
	return l->get_LastName() < r->get_LastName(); 
    }
};


#endif
