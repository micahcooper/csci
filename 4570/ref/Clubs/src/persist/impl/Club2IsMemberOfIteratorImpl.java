// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	Club2IsMemberOfIteratorImpl
//
// K.J. Kochut
//
//
//

package persist.impl;


import java.util.*;
import java.sql.*;

import model.entity.*;


public class Club2IsMemberOfIteratorImpl

  implements Iterator

{

  // Private attributes
  //
  ResultSet p_rs = null;
  boolean   p_more = false;

  Club      p_Club = null;


  // Constructors
  
  // these two will be used to create a new object
  //
  public Club2IsMemberOfIteratorImpl( Club c, ResultSet rs )
  { 
    p_Club = c;
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
    java.util.Date   q_Joined = null;
    String q_FirstName = null;
    String q_LastName = null;
    String q_Address = null;
    String q_Phone = null;
    int    q_Age = 0;
    Person q_Person = null;

    try {

      if( p_more ) {

	q_Id = p_rs.getLong( 1 );
	q_PersonId = p_rs.getLong( 2 );
	q_FirstName = p_rs.getString( 3 );
	q_LastName = p_rs.getString( 4 );
	q_Address = p_rs.getString( 5 );
	q_Phone = p_rs.getString( 6 );
	q_Age = p_rs.getInt( 7 );
	q_Joined = p_rs.getDate( 8 );
	
	p_more = p_rs.next();

	// create a proxy for the Person object on the "other end" of the link
	//
	q_Person = ModelFactory.createPerson( q_PersonId, q_FirstName, q_LastName,
					      q_Address, q_Phone, q_Age );

	// create a proxy for the link itself and return it to the caller
	//
	return ModelFactory.createIsMemberOf( q_Id, q_Person, p_Club, q_Joined );
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
