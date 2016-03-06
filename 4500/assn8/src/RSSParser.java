/*
*  RSSParser Class
*
*
*/
import javax.xml.parsers.*;
import org.w3c.dom.*;
import org.w3c.dom.traversal.*;
import org.xml.sax.SAXException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;

public class RSSParser{
    private NodeIterator my_items;
    private String url;
 
    /**
    * Default RSSParser  constructor.
    */
    public RSSParser(){

    }

    /**
    * Reads from an RSS feed news items.  This constructor parses
    *     the information into a DOM document using a NodeFilter.
    *
    * @param location - the RSS feed location
    */
    public RSSParser(String location){
	url = location;

	try{
	    DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
	    DocumentBuilder parser = factory.newDocumentBuilder();

	    DOMImplementation impl = parser.getDOMImplementation();
	    if(!impl.hasFeature("traversal", "2.0")){
		System.out.println("DOM implementation requires traversal feature");
		return;
	    }

	    Document doc = parser.parse(url);

	    //create a NodeIterator to search tree
	    DocumentTraversal traversable = (DocumentTraversal) doc;
	    my_items = traversable.createNodeIterator(doc, 1, new RSSFilter(), true);

	    storeItem();
		
	}
	catch(SAXException sae){
	    System.err.println(sae);
	    System.err.println(url + " is not well-formed");
	}
	catch(IOException ioe){
	  //  System.out.println("IOError, parser could not check " + url);
	}
	catch(FactoryConfigurationError fce){
	    System.out.println("Could not locate factory used");
	}
	catch(ParserConfigurationException pce){
	    System.out.println("Could not locate a JAXP parser");
	}
    }

    /**
    *  Adds unique news items to the 'rss_items' table, in a database.
    *      Returns the number of new items stored.
    *
    * @param my_items - NodeIterator of nodes meeting the new items qualifications.
    *			  The node's parent must be a named 'items'.
    *
    * @return int num_stored - the number of new unique items added to table
    */
    public int storeItem(){
	Connection conn;
	Statement stmt;
	int rows_inserted=0;
	Node node;
	String title,date,desc;
	
	node = my_items.nextNode();

	while( node != null){
	    title = new String();
	    date = new String();
	    desc = new String();

	    do{
	        if(node.getNodeName().equals("title")){
		    title = node.getFirstChild().getNodeValue();
	 	}
	        if(node.getNodeName().equals("pubDate")){
		    date = node.getFirstChild().getNodeValue();
		}
	        if(node.getNodeName().equals("description")){
		    if(node.getFirstChild().getNodeType() == Node.CDATA_SECTION_NODE){
			CDATASection data = (CDATASection)(node.getFirstChild());
			desc = data.getData();
		    }
		    else
		    	desc = node.getFirstChild().getNodeValue();
		}
		
		node = my_items.nextNode();
	    }while( (node!=null) && (!(node.getNodeName()).equals("title")) );

	    //System.out.println("Title: "+title+"\nPubDate: "+pubDate+"\n"+description);
	    desc = addSlashes(desc);
	    //System.out.println(desc);

	    try{
	        Class.forName("com.mysql.jdbc.Driver").newInstance();
	        conn = DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");
	        stmt = conn.createStatement();
		if(title.length()<=0 || desc.length()<=0)
		    throw(new IOException());
	        String query = ("INSERT INTO rss_test "+
				"(title, story, pubDate) "+
   				"VALUES('"+title+"', '"+desc+"','"+date+"')");
	        rows_inserted = stmt.executeUpdate(query) + rows_inserted;
	    }
	    catch(ClassNotFoundException cnfe){
	        System.err.println(cnfe);
	        System.out.println("Can't load driver");
	    }
	    catch(SQLException sqle){
	       // System.out.println("SQL Exception: "+sqle.getMessage());
	    }
	    catch(Exception e){
		System.out.println("Unexpected error in storeItems() " +e);	
	    }
	}//end outside while loop
	System.out.println("RSS parser inserted " +rows_inserted+" new items");
	return rows_inserted;
    }
    /**
    * Deletes all rows from the table 'rss_items' in databe 'mrcooper'.
    *
    *
    */
    public void clearDB(){
	Connection conn;
	Statement stmt;

	    try{
	        Class.forName("com.mysql.jdbc.Driver").newInstance();
	        conn = DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");
	        stmt = conn.createStatement();
	        String query = ("DELETE FROM rss_items");
	        stmt.executeUpdate(query);
	    }
	    catch(ClassNotFoundException cnfe){
	        System.err.println(cnfe);
	        System.out.println("Can't load driver");
	    }
	    catch(SQLException sqle){
	        System.out.println("SQL Exception while deleting rows: "+sqle.getMessage());
	    }
	    catch(Exception e){
		System.out.println("Unexpected error in storeItems() " +e);	
	    }
    }
	
    
    /**
    *  Adds in slashes before apostrophes to a string input.
    *
    *   @param  s  string to modify.
    */

    public String addSlashes(String s)
    {

	s = s.replace("\'", "\\'");

	return s;
    }

   /**
   * Main method to create a new RSSParser object.
   *
   * @param args[0] - the url which contains the RSS feed
   *
   */

   public static void main(String[] args){

	if(args.length <= 0){
	    System.out.print("Usage: java RSSParser URL\n");
	    return;
        }
	new RSSParser(args[0]);
    }
}
