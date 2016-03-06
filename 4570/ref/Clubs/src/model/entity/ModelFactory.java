// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	ModelFactory
//
// K.J. Kochut
//
//
//

package model.entity;

import java.util.Date;

import model.entity.impl.*;



public class ModelFactory {

  // Club constructors
  //
  public static Club createClub() 
    { return new ClubImpl(); }

  public static Club createClub( String name, String addr, Date estab )
    { return new ClubImpl( name, addr, estab ); }

  public static Club createClub( long dbid, String name, String addr, Date estab )
    { return new ClubImpl( dbid, name, addr, estab ); }


  // Person constructors
  //
  public static Person createPerson()
    { return new PersonImpl(); }

  public static Person createPerson( String fn, String ln, String addr, 
				     String phone, int age )
    { return new PersonImpl( fn, ln, addr, phone, age ); }

  public static Person createPerson( long dbid, String fn, String ln, 
				     String addr, String phone, int age )
    { return new PersonImpl( dbid, fn, ln, addr, phone, age ); }
  
  // IsMemberOf constructors
  //
  public static IsMemberOf createIsMemberOf()
    { return new IsMemberOfImpl(); }

  public static IsMemberOf createIsMemberOf( Person p, Club c, Date j )
    { return new IsMemberOfImpl( p, c, j ); }

  public static IsMemberOf createIsMemberOf( long dbid, Person p, Club c, Date j )
    { return new IsMemberOfImpl( dbid, p, c, j ); }

};

  
