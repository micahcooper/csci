package mrcooper;

import java.util.ArrayList;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;

public class RSSLookUp{
    Connection conn;
    Statement stmt;
    ResultSet result;

    ArrayList<RSSItem> items;

    public RSSLookUp(){
/*
	try{
	    Class.forName("com.mysql.jdbc.Driver").newInstance();
	    conn = DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");

	    stmt = conn.createStatement();
	    String query = "SELECT * FROM rss_items";
	    result = stmt.executeQuery(query);
	    
	    while(result.next()){
		System.out.println(result.getString(1));
  	    }
	}
	catch(Exception e){
	    System.out.println("Trouble with your "+e.getMessage());
    	}
*/
    }
    public static void main(String[] args){
	new RSSLookUp();
    }
}
