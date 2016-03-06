/* Micah Cooper
 * CSCI4300 project ten
 *
 *
 * MoviesHandler.java
 */

package movies;

import java.util.ArrayList;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import org.w3c.dom.traversal.*;
import org.xml.sax.SAXException;
import java.io.IOException;
import java.io.FileNotFoundException;
import java.io.StringReader;
import java.io.InputStream;
import java.io.StringBufferInputStream;

public class MoviesHandler {

    ArrayList<Movie> movies;
    private String userGenre;
    
    /**
     * Creates a new instance of MoviesHandler
     */
    public MoviesHandler() {
        
    }

    //***********************************************
    /**
    * Method to retrieve the movies from the catalog.
    *
    * @returns movies	ArrayList of 'Movie' entities
    *************************************************/
    public ArrayList<Movie> getMovies(){
	movies = new ArrayList();

        try { // Call Web Service Operation
            movies.MovieCatalogService service = new movies.MovieCatalogService();
            movies.MovieCatalog port = service.getMovieCatalogPort();
	    InputStream xmlStream = new StringBufferInputStream(port.getMovieCatalog());

	    DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
	    DocumentBuilder parser = factory.newDocumentBuilder();
	    Document doc = parser.parse(xmlStream);

	    DOMImplementation impl = parser.getDOMImplementation();

	    DocumentTraversal traversable = (DocumentTraversal) doc;
	    NodeIterator movieNodes = traversable.createNodeIterator(doc, 1, null, true);

	    createMovieEntities(movieNodes);

        } 
 	catch(FileNotFoundException fnfe){
	    System.out.println("File problems "+fnfe.toString());
        }
	catch (Exception ex) {
	    //System.out.println("In your "+ex.getClass().getName());
        }
	    return movies;
    }
    //*******************************************************************
    /**									*
    * Creates 'Movie' entities from a Document object.			*
    *									*
    * @param movieNodes 	Document object, in NodeIterator form	*
    ********************************************************************/
    public void createMovieEntities(NodeIterator movieNodes){
	String title, genre, id;
	Node node;

	node = movieNodes.nextNode();

 	while( node != null){
	    title = "none";
	    genre = new String();
	    id = new String();

	    do{
		if(node.getNodeName().equals("movie")){
		    id = node.getAttributes().getNamedItem("id").getNodeValue();
 		}
		if(node.getNodeName().equals("title"))
		    title = node.getFirstChild().getNodeValue();
		if(node.getNodeName().equals("genre"))
		    genre = node.getFirstChild().getNodeValue();

	        node = movieNodes.nextNode();
	    }while( (node!=null) && (!(node.getNodeName()).equals("movie")) );

	    if(!(title.equals("none")) && !(title.equals("NULL")) )
	        movies.add(new Movie(id, title, genre));	    
	}

    }
    
    public void setUserGenre(String genre){
	this.userGenre = genre;
    }
    public String getUserGenre(){
	return userGenre;
    }
    /**
     * Testing purposes.
     */
    public static void main(String[] args){
        System.out.println("Instantiating ReviewsHandler");
    }
}
