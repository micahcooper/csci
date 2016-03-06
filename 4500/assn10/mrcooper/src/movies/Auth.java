//Micah Cooper
//Auth.java
package movies;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.security.MessageDigest;

public class Auth{
    private String userName;
    private String password;
    private String passOne;
    private String passTwo;
    private Boolean cleared=false;
    private Boolean added=false;
    private Boolean failedLogin=false;
    private String movieTitle;
    private String movieGenre;
    private String comments;
    private int movie_id;

    /**
    * Default constructor
    */
    public Auth(){
//	userName = "barney";
    }
    /**
    *  Registers a new movie to the movieCatalog web service.
    *
    * @param movieTitle		user supplied title of movie
    * @param movieGenre		supplied by input form
    */
    public void registerMovie(){
	added=false;
	if(cleared && (movieTitle!=null)&&(movieGenre!=null) ){
            try { // Call Web Service Operation
            	movies.MovieCatalogService service = new movies.MovieCatalogService();
            	movies.MovieCatalog port = service.getMovieCatalogPort();
            	int result = port.registerMovie(movieTitle, movieGenre);
	    	System.out.println("Added movie: "+result);
            } catch (Exception ex) {

	    added=false;
        }
	added=true;
       } 
    }
    /**
    *  Adds a review to the local database, mrcooper.
    *
    * @param movie_id 	supplied from the input form
    * @param userName   the user's name
    * @param comments   supplied by the user
    */
    public void addReview(){
 	Connection conn;
     	Statement stmt;
  	
       if(cleared){ 
	    try{
 	    	Class.forName("com.mysql.jdbc.Driver").newInstance();
	    	conn = DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");
	    	stmt = conn.createStatement();	

	    	String query = ("INSERT INTO reviews "+
			   "(id, author, time, comments) "+
			   "VALUES('"+movie_id+"', '"+userName+"', Now(),'"+comments+"')");
	    	stmt.executeUpdate(query);
	    }
	    catch(Exception e){
		System.out.println("Insertion trouble "+e.getMessage());	
	    }
	}
    }
    /**
    * Adds a newly registered user to the database.
    *
    * @param userName	name of the registered user
    * @param cleared	is the user valid?
    * @param password	user's password
    */
    public void addUser(){
	Connection conn;
	Statement stmt;

	try{
	    Class.forName("com.mysql.jdbc.Driver").newInstance();
	    conn = DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");
	    stmt = conn.createStatement();
	   
	    String query = ("INSERT INTO temp_users "+
			    "(login_name, passwd) "+
			    "VALUES('"+userName+"', '"+password+"')");
	
	    stmt.executeUpdate(query);
	}
	catch(SQLException sqle){
	    System.out.println("mrc SQL exception: "+sqle.getMessage());
	}
	catch(Exception e){
	    System.out.println("mrc unexpected error: "+e.getMessage());
   	}

    }	    
    /**
    * Checks existing user's password for what is in the database.
    *
    * @param password	CGI variable
    */
    public void checkCredentials(){
	Connection conn;
	Statement stmt;
   	ResultSet result;
	int i=0;

        try{
	    Class.forName("com.mysql.jdbc.Driver").newInstance();
	    conn = DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");
	    stmt = conn.createStatement();

	    String query = ("SELECT * from temp_users "+
			    "WHERE login_name='"+userName+"'"+
			    " and passwd='"+password+"'");
	
	
	    result = stmt.executeQuery(query);

	    while(result.next()){
		i++;
            }
	    //System.out.println("mrc result "+i);
 	    if(i==1){
		cleared = true;
		failedLogin = false;
	    }
	    else{
		cleared = false;
		failedLogin = true;
	    }	
	}
	catch(Exception e){
	    System.out.println("mrc unexpected error: "+e.getMessage());
	    cleared=false;
	    failedLogin=true;
	}

    }
    /**
    * Checks to make sure passwords are identical
    *
    * @param passOne  	user's password
    * @param passTwo    user's password
    */
    public Boolean checkPassword(){
	if( passOne.equals(passTwo)){
	    password = passOne;
	    return true;
	}
	return false;
    }

    /**
    * Hashes a string into a md5 encryption.
    *
    * @param hashee	the String to convert
    */
    public String hash(String hashee){
	String result="";
	byte[] myBytes = hashee.getBytes();

        try{
	    MessageDigest md5er;   
	
	    md5er = MessageDigest.getInstance("MD5");
	    md5er.update(myBytes);
	    myBytes = md5er.digest();
	    
  	    for(int i=0; i<myBytes.length; i++){
	 	int byte_int = new Integer(myBytes[i]).intValue();
		if(byte_int<0)
		    byte_int +=256;
		result += Integer.toHexString(byte_int);
	    }
	}
	catch(Exception e){
	}
	
	return result;
     }


    //*****GETTER METHODS*****//

    public Boolean getCleared(){
	return cleared;
    }
    public Boolean getFailedLogin(){
	return failedLogin;
    }
    public String getUserName(){
	return userName;
    }


    //******SETTER METHODS*****//

    public void setCleared(Boolean cleared){
	this.cleared = cleared;
    }
    public void setMovieTitle(String movieTitle){
	this.movieTitle = movieTitle;
    }
    public void setMovieGenre(String movieGenre){
	this.movieGenre = movieGenre;
	registerMovie();
    }
    public void setMovie_id(int id){
	movie_id = id;
    }
    public void setComments(String comments){
	this.comments = comments;
	addReview();
    }
    public void setUserName(String userName){
	this.userName = userName;
    }
    public void setPassword(String pass){
	this.password = hash(pass);
	checkCredentials();
    }
    public void setPassOne(String pass){
	this.passOne = hash(pass);
    }
    public void setPassTwo(String pass){
	this.passTwo = hash(pass);
	if(checkPassword())
	    addUser();
    }
}
