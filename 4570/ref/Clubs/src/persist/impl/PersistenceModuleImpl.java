// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	PersistenceModuleImpl
//
// K.J. Kochut
//
//
//

package persist.impl;


import java.util.*;
import java.sql.*;

import persist.*;
import model.entity.*;
import except.*;

public class PersistenceModuleImpl 

  implements PersistenceModule

{

  private Connection p_conn = null;

  private Statement  p_stmt = null;

  public PersistenceModuleImpl( String url, String user, String pass )

    throws ClubsException

  {
    try {

      // create the driver for MySQL
      Class.forName("com.mysql.jdbc.Driver").newInstance();

      // establish the databse connection
      p_conn = DriverManager.getConnection( url, user, pass );

      // create a statement
      p_stmt = p_conn.createStatement();

    }
    catch( Exception e ) {	// just in case...
      e.printStackTrace();
    }
  }

  public Club restoreClub( long id )

    throws ClubsException

  {
    String sql = "select Id, Name, Address, Established from Club where id = " + id;
    long   q_Id = 0;
    String q_Name = null;
    String q_Address = null;
    java.util.Date   q_Established = null;
	    
    try {

      // retrieve the persistent Club object
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	// we will use only the first row!
	//
	while( r.next() ) {

	  // retrieve all column values
	  q_Id = r.getLong( 1 );
	  q_Name = r.getString( 2 );
	  q_Address = r.getString( 3 );
	  q_Established = r.getDate( 4 );
	  
	  return ModelFactory.createClub( q_Id, q_Name, q_Address, q_Established );
	}
      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( e );
    }

    throw new ClubsException( "Could not retrieve persistent Club object with id: " + id );
  }

  public Club restoreClub( String name )

    throws ClubsException

  {
    String sql = "select Id, Name, Address, Established from Club where Name = '" + name +"'";
    long   q_Id = 0;
    String q_Name = null;
    String q_Address = null;
    java.util.Date   q_Established = null;
	    
    try {

      // retrieve the persistent Club object
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	// we will use only the first row!
	//
	while( r.next() ) {

	  // retrieve all column values
	  q_Id = r.getLong( 1 );
	  q_Name = r.getString( 2 );
	  q_Address = r.getString( 3 );
	  q_Established = r.getDate( 4 );
	  
	  return ModelFactory.createClub( q_Id, q_Name, q_Address, q_Established );
	}
      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( e );
    }

    throw new ClubsException( "Could not retrieve persistent Club object with name: " + name );
  }

  public Iterator restoreClubs()

    throws ClubsException

  {
    String sql = "select Id, Name, Address, Established from Club";
	    
    try {

      // retrieve the persistent Club objects
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	return new ClubIteratorImpl( r );

      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( e );
    }

    throw new ClubsException( "Could not retrieve persistent Club objects" );
  }

  public long storeClub( Club c )

    throws ClubsException

  {
    java.sql.Date estab = new java.sql.Date( c.get_Established().getTime() );
    String sql = "insert into Club ( Name, Address, Established ) values ( " +
                                    "'" + c.get_Name() + "', " +
                                    "'" + c.get_Address() + "', " +
                                    "'" + estab + "' )";
    int    inscnt = 0;
    long   clubid = 0;
	    
    try {

      // store a new persistent Club object
      //
      inscnt = p_stmt.executeUpdate( sql );
      if( inscnt == 1 ) {
	sql = "select last_insert_id()";
	if( p_stmt.execute( sql ) ) { // statement returned a result

	  // retrieve the result
	  ResultSet r = p_stmt.getResultSet();

	  // we will use only the first row!
	  //
	  while( r.next() ) {

	    // retrieve the last insert auto_increment value
	    clubid = r.getLong( 1 );
	    if( clubid > 0 ) {
	      c.set_id( clubid );
	      c.set_isProxy();
	      return clubid;
	    }
	  }
	}
      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( e );
    }

    throw new ClubsException( "Could not store Club object" );
  }

  public Person restorePerson( long id )

    throws ClubsException

  {
    String sql = "select Id, FirstName, LastName, Address, Phone, Age from Person where id = " + id;
    long   q_Id = 0;
    String q_FirstName = null;
    String q_LastName = null;
    String q_Address = null;
    String q_Phone = null;
    int    q_Age = 0;
	    
    try {

      // retrieve the persistent Person object
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	// we will use only the first row!
	//
	while( r.next() ) {

	  // retrieve all column values
	  q_Id = r.getLong( 1 );
	  q_FirstName = r.getString( 2 );
	  q_LastName = r.getString( 3 );
	  q_Address = r.getString( 4 );
	  q_Phone = r.getString( 5 );
	  q_Age = r.getInt( 6 );
	  
	  return ModelFactory.createPerson( q_Id, q_FirstName, q_LastName, q_Address, 
					    q_Phone, q_Age );
	}
      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Could not restore persistent Person object with id: " + id + " Root cause: " + e );
    }

    throw new ClubsException( "Could not restore persistent Person object with id: " + id );
  }

  public Person restorePerson( String fname, String lname )

    throws ClubsException

  {
    String sql = "select Id, FirstName, LastName, Address, Phone, Age from Person " +
                 "where FirstName = '" + fname + "' and LastName = '" + lname + "'";
    long   q_Id = 0;
    String q_FirstName = null;
    String q_LastName = null;
    String q_Address = null;
    String q_Phone = null;
    int    q_Age = 0;
	    
    try {

      // retrieve the persistent Person object
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	// we will use only the first row!
	//
	while( r.next() ) {

	  // retrieve all column values
	  q_Id = r.getLong( 1 );
	  q_FirstName = r.getString( 2 );
	  q_LastName = r.getString( 3 );
	  q_Address = r.getString( 4 );
	  q_Phone = r.getString( 5 );
	  q_Age = r.getInt( 6 );
	  
	  return ModelFactory.createPerson( q_Id, q_FirstName, q_LastName, q_Address, 
					    q_Phone, q_Age );
	}
      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Could not restore persistent Person object with name: " + 
				fname + " " + lname + "; Root cause: " + e );
    }

    throw new ClubsException( "Could not restore persistent Person object with name: " +
			      fname + " " + lname );
  }

  public Iterator restorePersons()

    throws ClubsException

  {
    String sql = "select Id, FirstName, LastName, Address, Phone, Age from Person";
	    
    try {

      // retrieve the persistent Person objects
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	return new PersonIteratorImpl( r );

      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Could not restore persistent Person objects; root cause: " + e );
    }

    throw new ClubsException( "Could not restore persistent Person objects" );
  }

  public long storePerson( Person p )

    throws ClubsException

  {
    String sql = "insert into Person ( FirstName, LastName, Address, Phone, Age ) values ( " +
                                       "'" + p.get_FirstName() + "', " +
                                       "'" + p.get_LastName() + "', " +
                                       "'" + p.get_Address() + "', " +
                                       "'" + p.get_Phone() + "', " +
                                       p.get_Age() + " )";
    int    inscnt = 0;
    long   personid = 0;
	    
    try {

      // store a new persistent Person object
      //
       inscnt = p_stmt.executeUpdate( sql );
       if( inscnt == 1 )
      if( inscnt == 1 ) {
	sql = "select last_insert_id()";
	if( p_stmt.execute( sql ) ) { // statement returned a result

	  // retrieve the result
	  ResultSet r = p_stmt.getResultSet();

	  // we will use only the first row!
	  //
	  while( r.next() ) {

	    // retrieve the last insert auto_increment value
	    personid = r.getLong( 1 );
	    if( personid > 0 ) {
	      p.set_id( personid );
	      p.set_isProxy();
	      return personid;
	    }
	  }
	}
      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Could not store Person object; root cause: " + e );
    }

    throw new ClubsException( "Could not store Person object" );
  }

  public IsMemberOf restoreIsMemberOf( long id )

    throws ClubsException

  {
    String sql = "select p.Id, p.FirstName, p.LastName, p.Address, p.Phone, p.Age, " +
      		         "c.Id, c.Name, c.Address, c.Established, " +
			 "i.Joined " +
                 "from  Club c, Person p, IsMemberOf i " +
                 "where p.Id = i.PersonId and c.Id = i.ClubId and i.Id = " + id;

    long   		pid;
    String 		pfn = null;
    String 		pln = null;
    String 		paddr = null;
    String 		pph = null;
    int    		page = 0;
    long   		cid = 0;
    String 		cname = null;
    String 		caddr = null;
    java.util.Date   	cest = null;
    java.util.Date   	ijoin = null;

    Person		person = null;
    Club		club = null;

    try {

      // retrieve the persistent IsMemberOf object (a single link)
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	// we will use only the first row!
	//
	while( r.next() ) {

	  // retrieve all column values
	  pid = r.getLong( 1 );
	  pfn = r.getString( 2 );
	  pln = r.getString( 3 );
	  paddr = r.getString( 4 );
	  pph = r.getString( 5 );
	  page = r.getInt( 6 );
	  cid = r.getLong( 7 );
	  cname = r.getString( 8 );
	  caddr = r.getString( 9 );
	  cest = r.getDate( 10 );
	  ijoin = r.getDate( 11 );
	  
	  // create a proxy for the Person object on the left side of the link
	  //
	  person = ModelFactory.createPerson( pid, pfn, pln,
						paddr, pph, page );

	  // create a proxy for the Club object on the right side of the link
	  //
	  club = ModelFactory.createClub( cid, cname, caddr, cest );

	  // now, create an return the link
	  //
	  return ModelFactory.createIsMemberOf( id, person, club, ijoin );
	}
      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Could not restore persistent IsMemberOf object with id: " + id + 
				"; root cause: " + e );
    }

    throw new ClubsException( "Could not restore persistent IsMemberOf object with id: " + id );
  }

  public Iterator       restoreIsMemberOfs( Person p )

    throws ClubsException

  {
    String sql = "select i.id, c.Id, c.Name, c.Address, c.Established, i.Joined " +
                 "from  Club c, IsMemberOf i " +
                 "where c.Id = i.ClubId and i.PersonId = " + p.get_id();

	    
    try {

      // retrieve the persistent IsMemberOf objects for a given Person object
      // that is all links connecting a given Person object and some Club object
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	return new Person2IsMemberOfIteratorImpl( p, r );

      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Could not restore persistent IsMemberOf objects for Person with id: " + p.get_id() + 
				"; root cause: " + e );
    }

    throw new ClubsException( "Could not restore persistent IsMemberOf objects for Person with id: " + p.get_id() );
  }

  public Iterator       restoreIsMemberOfs( Club c )

    throws ClubsException

  {
    String sql = "select i.Id, p.Id, p.FirstName, p.LastName, p.Address, p.Phone, p.Age, i.Joined " +
            	 "from  Person p, IsMemberOf i " +
            	 "where p.Id = i.PersonId and i.ClubId = " + c.get_id();
	    
    try {

      // retrieve the persistent IsMemberOf objects for a given Club object
      // that is all links connecting a given Club object and some Person object
      //
      if( p_stmt.execute( sql ) ) { // statement returned a result

	// retrieve the result
	ResultSet r = p_stmt.getResultSet();

	return new Club2IsMemberOfIteratorImpl( c, r );

      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Could not restore persistent IsMemberOf objects for Club with id: " + c.get_id() + 
				"; root cause: " + e );
    }

    throw new ClubsException( "Could not restore persistent IsMemberOf objects for Club with id: " + c.get_id() );
  }

  public long storeIsMemberOf( IsMemberOf i )

    throws ClubsException

  {
    java.sql.Date joined = new java.sql.Date( i.get_Joined().getTime() );
    String sql = "insert into IsMemberOf ( PersonId, ClubId, Joined ) values ( " +
                                    i.get_Person().get_id() + ", " +
                                    i.get_Club().get_id() + ", " +
      				    "'" + joined + "' )";
    int    inscnt = 0;
    long   ismemofid = 0;
	    
    try {

      // store a new persistent IsMemberOf object
      //
      inscnt = p_stmt.executeUpdate( sql );
      if( inscnt == 1 ) {
	sql = "select last_insert_id()";
	if( p_stmt.execute( sql ) ) { // statement returned a result

	  // retrieve the result
	  ResultSet r = p_stmt.getResultSet();

	  // we will use only the first row!
	  //
	  while( r.next() ) {

	    // retrieve the last insert auto_increment value
	    ismemofid = r.getLong( 1 );
	    if( ismemofid > 0 ) {
	      i.set_id( ismemofid );
	      i.set_isProxy();
	      return ismemofid;
	    }
	  }
	}
      }
    }
    catch( Exception e ) {	// just in case...
      throw new ClubsException( "Could not store IsMemberOf object; root cause: " + e );
    }

    throw new ClubsException( "Could not store IsMemberOf object" );
  }

};
