
package mrcService;

import javax.jws.WebMethod;
import javax.jws.WebParam;
import javax.jws.WebResult;
import javax.jws.WebService;
import javax.xml.ws.RequestWrapper;
import javax.xml.ws.ResponseWrapper;


/**
 * This class was generated by the JAXWS SI.
 * JAX-WS RI 2.0_01-b59-fcs
 * Generated source version: 2.0
 * 
 */
@WebService(name = "ReviewsService", targetNamespace = "http://movies/")
public interface ReviewsService {


    /**
     * 
     * @param movieId
     * @return
     *     returns java.lang.String
     */
    @WebMethod
    @WebResult(targetNamespace = "")
    @RequestWrapper(localName = "getReviews", targetNamespace = "http://movies/", className = "mrcService.GetReviews")
    @ResponseWrapper(localName = "getReviewsResponse", targetNamespace = "http://movies/", className = "mrcService.GetReviewsResponse")
    public String getReviews(
        @WebParam(name = "movie_id", targetNamespace = "")
        int movieId);

}
