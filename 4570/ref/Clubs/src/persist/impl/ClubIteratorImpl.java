// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	ClubIteratorImpl
//
// K.J. Kochut
//
//
//

package persist.impl;


import java.util.*;
import java.sql.*;

import model.entity.*;
import except.*;


public class ClubIteratorImpl

  implements Iterator

{

  // Private attributes
  //
  ResultSet p_rs = null;
  boolean   p_more = false;


  // Constructors
  
  // these two will be used to create a new object
  //
  public ClubIteratorImpl( ResultSet rs )
    throws ClubsException
  { 
    p_rs = rs;
    try {
      p_more = rs.next();
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Cannot create Club iterator; root cause: " + e );
    }
  }

  public boolean hasNext() 
  { 
    return p_more; 
  }

  public Object next() 
  {
    long   q_Id = 0;
    String q_Name = null;
    String q_Address = null;
    java.util.Date   q_Established = null;

    if( p_more ) {

      try {

	q_Id = p_rs.getLong( 1 );
	q_Name = p_rs.getString( 2 );
	q_Address = p_rs.getString( 3 );
	q_Established = p_rs.getDate( 4 );

	p_more = p_rs.next();

      }
      catch( Exception e ) {	// just in case...
	throw new NoSuchElementException( "No next Club object; root cause: " + e );
      }

      return ModelFactory.createClub( q_Id, q_Name, q_Address, q_Established );
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
