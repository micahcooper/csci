import junit.framework.*;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.io.IOException;

public class TestRSSLookUp extends TestCase{
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

    /*
    public void testInvalidURL(){
	try{
	    testParser1 = new RSSParser("http://www.non-exist.com");	
	}
	catch(Exception e){
	    fail("Unexecptected behaviour opening invalid URL"+e.getClass().getName());
	}
    }
    public void testMissingRSSFeed(){
	try{
	    testParser1 = new RSSParser("http://www.cs.uga.edu/~cooper");
	}
	catch(Exception e){
	    fail("Unexecpected behaviour creating RSSParser with no URL");
	}
    }
    public void testFeed1(){
	ResultSet result=null;
	int rows = 0;
	try{
	    new RSSParser().clearDB();
	    String query = ("SELECT * FROM rss_items");
	    stmt = conn.createStatement();

	    testParser1 = new RSSParser("RSS_test1.xml");
	    result = stmt.executeQuery(query);
	    while(result.next()){rows++;}
	    assertEquals(0, rows);
	}
	catch(Exception e){
	    fail("Unexpected behavior " + e);
	}	
    }
*/
  





    /**
    *
    */
    public void testFeed2(){

    }

    /**
    *
    */
    public void testBothFeeds(){
   
    } 

    /**
    *
    */
    public void testNoNewRecords(){

    }

    /**
    *
    */
    public void testSomeNewRecords(){

    }

} 
