// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	Person2IsMemberOfIteratorImpl
//
// K.J. Kochut
//
//
//

package persist.impl;


import java.util.*;
import java.sql.*;

import model.entity.*;


public class Person2IsMemberOfIteratorImpl

  implements Iterator

{

  // Private attributes
  //
  ResultSet p_rs = null;
  boolean   p_more = false;

  Person    p_Person = null;


  // Constructors
  
  // these two will be used to create a new object
  //
  public Person2IsMemberOfIteratorImpl( Person p, ResultSet rs )
  { 
    p_Person = p;
    p_rs = rs;
    try {
      p_more = rs.next();
    }
    catch( Exception e ) {	// just in case...
      e.printStackTrace();
    }
  }

  public boolean hasNext() 
  { 
    return p_more; 
  }

  public Object next() 
  {
    long   q_Id = 0;
    long   q_PersonId = 0;
    long   q_ClubId = 0;
    java.util.Date   q_Joined = null;
    String q_Name = null;
    String q_Address = null;
    java.util.Date   q_Established = null;
    Club   club = null;


    try {

      if( p_more ) {

	q_Id = p_rs.getLong( 1 );
	q_ClubId = p_rs.getLong( 2 );
	q_Name = p_rs.getString( 3 );
	q_Address = p_rs.getString( 4 );
	q_Established = p_rs.getDate( 5 );
	q_Joined = p_rs.getDate( 6 );
	
	p_more = p_rs.next();

	club = ModelFactory.createClub( q_ClubId, q_Name, q_Address, q_Established );

	return ModelFactory.createIsMemberOf( q_Id, p_Person, club, q_Joined );
      }
      else {
	throw new NoSuchElementException();
      }
    }
    catch( Exception e ) {	// just in case...
      e.printStackTrace();
    }
    return null;
  }

  public void remove()
  {
    throw new UnsupportedOperationException();
  }

};
