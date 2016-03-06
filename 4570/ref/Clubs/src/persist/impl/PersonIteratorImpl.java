// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	PersonIteratorImpl
//
// K.J. Kochut
//
//
//

package persist.impl;


import java.util.*;
import java.sql.*;

import except.*;
import model.entity.*;


public class PersonIteratorImpl

  implements Iterator

{

  // Private attributes
  //
  ResultSet p_rs = null;
  boolean   p_more = false;


  // Constructors
  
  // these two will be used to create a new object
  //
  public PersonIteratorImpl( ResultSet rs )	
    throws ClubsException
  { 
    p_rs = rs;
    try {
      p_more = rs.next();
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Cannot create Person iterator; root cause: " + e );
    }
  }

  public boolean hasNext() 
  { 
    return p_more; 
  }

  public Object next() 
  {
    long   q_Id = 0;
    String q_FirstName = null;
    String q_LastName = null;
    String q_Address = null;
    String q_Phone = null;
    int    q_Age = 0;

    if( p_more ) {

      try {

	q_Id = p_rs.getLong( 1 );
	q_FirstName = p_rs.getString( 2 );
	q_LastName = p_rs.getString( 3 );
	q_Address = p_rs.getString( 4 );
	q_Phone = p_rs.getString( 5 );
	q_Age = p_rs.getInt( 6 );

	p_more = p_rs.next();

      }
      catch( Exception e ) {	// just in case...
	throw new NoSuchElementException( "No next Person object; root cause: " + e );
      }

      return ModelFactory.createPerson( q_Id, q_FirstName, q_LastName, q_Address, 
					q_Phone, q_Age );
    }
    else {
      throw new NoSuchElementException( "No next Club object" );
    }
  }

  public void remove()
  {
    throw new UnsupportedOperationException();
  }

};
