package mrcooper;
//Micah Cooper
//CSCI 4300, project 9

import junit.framework.*;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.io.IOException;
import java.util.ArrayList;

public class TestRSSLookUp extends TestCase{
    ArrayList<RSSItem> items;
    RSSLookUp test;
    private Connection conn;
    private Statement stmt;
    
    /**
    * Provides the necessary resources for the tested class.
    *
    */
    protected void setUp(){
	//basically nothing or maybe set the database?

  	try{
	    Class.forName("com.mysql.jdbc.Driver").newInstance();
	    conn = DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");
	}
	catch(Exception e){
	
	}
    }

    /**
    * Tests results based only on entire keyword in the title.
    */
    public void testKeywordInTitle(){
	try{
	    test = new RSSLookUp();
	    test.setSearchCriterion("loves");
	    items = test.getItems();

	    assertEquals(1, items.size());
	}
	catch(Exception e){
	    fail("Unexecptected behaviour "+e.getClass().getName());
	}
    }

    /**
    * Test RSSLookUp for keyword that occurs in Title and body.
    */
    public void testKeywordInTitleBody(){
	try{
	    test = new RSSLookUp();    
	    test.setSearchCriterion("JDBC");
	    items = test.getItems();

	    assertEquals(2, items.size());
	}
	catch(Exception e){
	    fail("Unexecpected behaviour "+e.getMessage());
	}
    }
	
    /**
    * Test RSSLookUp results from a multiword search.
    */
    public void testMultiKeyword(){
	try{
	    test = new RSSLookUp();    
	    test.setSearchCriterion("JDBC ice");
	    items = test.getItems();

	    assertEquals(3, items.size());
	}
	catch(Exception e){
	    fail("Unexecpected behaviour "+e.getMessage());
	}
    }

    /**
    * Test RSSLookUp results from an unsuccessful search.
    */
    public void testUnsuccessfulSearch(){
	try{
	    test = new RSSLookUp();    
	    test.setSearchCriterion("xxxxxxx");
	    items = test.getItems();

	    assertEquals(0, items.size());
	}
	catch(Exception e){
	    fail("Unexecpected behaviour "+e.getMessage());
	}
    }
} 
