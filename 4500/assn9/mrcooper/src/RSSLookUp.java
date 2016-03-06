package mrcooper;
//Micah Cooper
//CSCI 4300, project 9


import java.util.ArrayList;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Properties;
import java.lang.reflect.InvocationTargetException;

public class RSSLookUp{
    Connection conn;
    Statement stmt;
    ResultSet result;
    String searchCriterion = "qqq";
    String[] searchWord;

    ArrayList<RSSItem> items;

    /**
    * Default constructor.
    */
    public RSSLookUp(){
    }

    /**
    * Searches the mysql table mrcooper.rss_items, for any rows
    *     with the user supplied search string 'crit'.
    *
    * @param String crit the user supplied search string.
    */
    public void search(String crit){
	String query;
	String table; 
	boolean duplicate = false;
	RSSItem current;

	table = getTableName();

	try{
	    items = new ArrayList();
	    Class.forName("com.mysql.jdbc.Driver").newInstance();
	    conn = DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");
	    stmt = conn.createStatement();


	    /*************************************************
	    * Check the rss items' titles for an exact match.*
	    *************************************************/
	    query = ("SELECT * FROM "+table+" WHERE " 
				+"title regexp ('"+searchCriterion+"')");
	    result = stmt.executeQuery(query);
	    while(result.next()){
		//System.out.println(result.getString(1));
		current = new RSSItem(result.getString(1), result.getString(2), result.getString(3));
		//System.out.println(current.getTitle());
		items.add(current);
  	    }
	    /***************************************************
	    * Check the rss item title for any of the keywords.*
	    ***************************************************/
	    for(int i=0; i<searchWord.length; i++){
	    //check a single keyword from a multi keyword search
	        query = ("SELECT * FROM "+table+" WHERE " 
				+"title regexp ('"+searchWord[i]+"')");
	    	result = stmt.executeQuery(query);
	    	while(result.next()){
	    	    duplicate = false;
		    current = new RSSItem(result.getString(1), result.getString(2), result.getString(3));

		    for(int j=0; j<items.size(); j++){
		    //chech one ArrayList element to compare with the current item
		        if( (current.getTitle()).equals(items.get(j).getTitle()) )
			    duplicate = true;
                    }
		    if(!duplicate)
		        items.add(current);		
	         }//end while
  	    }//end for - searchWord
	    /****************************************************
	    * Check the rss item story for any of the keywords. *
	    *****************************************************/
	    for(int i=0; i<searchWord.length; i++){
	    //check a single keyword from a multi keyword search
	        query = ("SELECT * FROM "+table+" WHERE " 
				+"story regexp ('"+searchWord[i]+"')");
	    	result = stmt.executeQuery(query);
	    	while(result.next()){
	            duplicate = false;
		    current = new RSSItem(result.getString(1), result.getString(2), result.getString(3));

		    for(int j=0; j<items.size(); j++){
		    //chech one ArrayList element to compare with the current item
		        if( (current.getTitle()).equals(items.get(j).getTitle()) )
			    duplicate = true;
                    }
		    if(!duplicate)
		        items.add(current);		
	         }//end while
  	    }//end for - searchWord
	}
	catch(Exception e){
	    System.out.println("Trouble with your "+e.getMessage());
    	}
    }

    /**
    * Getter method for results.
    */
    public ArrayList<RSSItem> getItems(){
	return items;
    }

    /**
    * Setter method.
    */
    public void setSearchCriterion(String crit){
	searchCriterion = crit;
  	//split the search string into tokens
 	searchWord = crit.split(" ");	

  	//search rss_items table
	search(searchCriterion);
	
    }
    /**
    * Getter method.
    */
    public String getSearchCriterion(){
	return searchCriterion;
    }

    /**
    * Sets the table to search from.
    */
    public String getTableName(){
	String table;

	try{
	Properties prop = System.getProperties();
	return prop.getProperty("test_db");
	}
	catch(Exception e){return "rss_items";}

    }
    /**
    * Pre-junit testing purposes.
    */
    public static void main(String[] args){
	RSSLookUp x =new RSSLookUp();

	x.setSearchCriterion("JDBC");
    }
}
