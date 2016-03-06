//
package movies;

import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebService;
import javax.xml.parsers.*;
import javax.xml.transform.*;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.Statement;
import java.sql.DriverManager;
import java.sql.SQLException;

@WebService()
public class ReviewsService {
    /**
     * Web service operation
     */
    @WebMethod
    public String getReviews(@WebParam(name = "movie_id") int movie_id) {
	Connection conn;
	Statement stmt;
	String query;
	ResultSet result;
	
	try{
	    //Class.forName("com.mysql.jdbc.Driver").newInstace();
	    conn=DriverManager.getConnection("jdbc:mysql://localhost/mrcooper","mrcooper","");
	    stmt = conn.createStatement();

	    query =("SELECT * FROM reviews WHERE id="+movie_id); 
	    //System.out.println(query);
	    result=stmt.executeQuery(query);

	    query = "<reviews movie_id='"+movie_id+"'>";
	    while(result.next()){
	 	query += "<review>"+
			 "<author>"+result.getString(2)+"</author>"+
			 "<date>"+result.getString(3)+"</date>"+
			 "<comments>"+result.getString(4)+"</comments>"+
			 "</review>";
	    }
	    query +="</reviews>";

  	}
	catch(Exception e){
	    return "</reviews movie_id='"+movie_id+"'></reviews>";

 	}
        
	return query;

    }
    





}
