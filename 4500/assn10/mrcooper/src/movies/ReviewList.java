/*
 * ReviewList.java
 *
 * Created on April 28, 2007, 12:45 PM
 *
 * To change this template, choose Tools | Template Manager
 * and open the template in the editor.
 */

package movies;

import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebService;

/**
 *
 * @author gdogg
 */
@WebService()
public class ReviewList {
    /**
     * Web service operation
     */
    @WebMethod
    public String getReviews(@WebParam(name = "movie_id") int movie_id) {
        // TODO implement operation 
        return "<reviews movie_id><review><author>Bareny</author><date>10-11-2001"+
                "</date><comments>Great all around movie</commetns><review></reviews>";
    }
    
}
