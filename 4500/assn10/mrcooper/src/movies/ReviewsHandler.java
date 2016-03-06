//Micah Cooper
//CSCI 4300
//
//ReviewsHandler.java

package movies;

import java.util.ArrayList;
import javax.xml.parsers.*;
import org.w3c.dom.*;
import org.w3c.dom.traversal.*;
import org.xml.sax.SAXException;
import java.io.IOException;
import java.io.StringReader;
import java.io.InputStream;
import java.io.StringBufferInputStream;

public class ReviewsHandler {
    private int movieId;
    ArrayList<Review> reviews;
    InputStream xmlStream;

    /** Creates a new instance of ReviewsHandler */
    public ReviewsHandler() {
    }

    //*****************************************************
    /**							  *
    * Retrieves a list of reviews from local database and *
    *     peer web services.				  *
    *							  *
    * @returns reviews	List of Review entities. 	  *
    ******************************************************/
    public ArrayList<Review> getReviews(){
 	reviews = new ArrayList();

        try { // Call Web Service Operation

	    createReviewEntities(dmeReviews());
	    createReviewEntities(mrcReviews());
	    //createReviewEntities(dohcjsReviews());
	    createReviewEntities(alexReviews());
	    createReviewEntities(roiReviews());
	    createReviewEntities(weissReviews());
	    
        } 
        catch (Exception e) {
	   System.out.println("Error collecting reviews "+e.getCause());
	}
	return reviews;
    }

    //*********************************************
    // ADD TO THE ARRAYLIST
    //********************************************
    private void createReviewEntities(InputStream xmlStream){
	String author, comments, time;
	Node node;
	NodeIterator reviewNodes = null;

  	try{
 	    DocumentBuilderFactory factory = DocumentBuilderFactory.newInstance();
	    DocumentBuilder parser = factory.newDocumentBuilder();
	    Document doc = parser.parse(xmlStream);

	    DocumentTraversal traversable = (DocumentTraversal) doc;
	    reviewNodes = traversable.createNodeIterator(doc,1,null,true);

  	}
	catch(Exception e){
	    System.out.println("Review creation problem "+e.getMessage());
 	}
        node = reviewNodes.nextNode();

   	while( node != null){
	    author = "none";
	    comments = new String();
	    time = new String();

	    do{
		if(node.getNodeName().equals("author"))
		    author = node.getFirstChild().getNodeValue();
		if(node.getNodeName().equals("date")) 
		    time =  node.getFirstChild().getNodeValue();
		if(node.getNodeName().equals("comments"))
		    comments = node.getFirstChild().getNodeValue();

		node = reviewNodes.nextNode();
	    }while( (node!=null) && (!(node.getNodeName()).equals("review")) );
	
	    if( !(author.equals("none")) )
		reviews.add(new Review(author, comments, time));
	}
    }



    public InputStream dmeReviews(){
        dmeReviews.ReviewListService service = new dmeReviews.ReviewListService();
        dmeReviews.ReviewList port = service.getReviewListPort();
        xmlStream = new StringBufferInputStream(port.getReviews(movieId));

	return xmlStream;
    }
    public InputStream dohcjsReviews(){
        dohcjsReviews.DohcjsReviewListServiceService service = new dohcjsReviews.DohcjsReviewListServiceService();
        dohcjsReviews.DohcjsReviewListService port = service.getDohcjsReviewListServicePort();
        xmlStream = new StringBufferInputStream(port.getReviews(new Integer(movieId).toString()) );

	return xmlStream;
    }
    public InputStream mrcReviews(){
        mrcService.ReviewsServiceService service = new mrcService.ReviewsServiceService();
        mrcService.ReviewsService port = service.getReviewsServicePort();
        xmlStream = new StringBufferInputStream(port.getReviews(movieId));

	return xmlStream;
	
    }
    public InputStream roiReviews(){
	try{
            roiReview.KsamimReviewListServiceService service = new roiReview.KsamimReviewListServiceService();
            roiReview.KsamimReviewListService port = service.getKsamimReviewListServicePort();
            xmlStream = new StringBufferInputStream(port.getReviews(movieId));
	}
	catch(Exception e){
	    System.out.println("roi error");
	    return (new StringBufferInputStream("<reviews move_id'"+movieId+"'></reviews>"));
	}

	return xmlStream;
    }
    public InputStream alexReviews(){
	try{
        alexReview.AcrononReviewWebServiceService service = new alexReview.AcrononReviewWebServiceService();
        alexReview.AcrononReviewWebService port = service.getAcrononReviewWebServicePort();
        xmlStream = new StringBufferInputStream(port.getReviews(movieId));
	}
	catch(Exception e){
	    System.out.println("cronon error");
	    return (new StringBufferInputStream("<reviews movie_id='"+movieId+"'></reviews>"));
	}

	return xmlStream;

    }
    public InputStream weissReviews(){
            weiss.JweissWebServiceService service = new weiss.JweissWebServiceService();
            weiss.JweissWebService port = service.getJweissWebServicePort();
        xmlStream = new StringBufferInputStream(port.getMovieReviews(movieId));

	return xmlStream;

    }
    public void setMovieId(int movieId){
 	this.movieId = movieId;
    }
    public int getMovieId(){
	return movieId;
    }
    
    public void doNothing(){
        
        try { // Call Web Service Operation
            weiss.JweissWebServiceService service = new weiss.JweissWebServiceService();
            weiss.JweissWebService port = service.getJweissWebServicePort();
        } catch (Exception ex) {
            // TODO handle custom exceptions here
        }
    }
}
