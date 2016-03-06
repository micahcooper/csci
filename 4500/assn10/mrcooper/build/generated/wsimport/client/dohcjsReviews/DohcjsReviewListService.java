
package dohcjsReviews;

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
@WebService(name = "dohcjsReviewListService", targetNamespace = "http://catalog/")
public interface DohcjsReviewListService {


    /**
     * 
     * @param id
     * @return
     *     returns java.lang.String
     */
    @WebMethod
    @WebResult(targetNamespace = "")
    @RequestWrapper(localName = "getReviews", targetNamespace = "http://catalog/", className = "dohcjsReviews.GetReviews")
    @ResponseWrapper(localName = "getReviewsResponse", targetNamespace = "http://catalog/", className = "dohcjsReviews.GetReviewsResponse")
    public String getReviews(
        @WebParam(name = "id", targetNamespace = "")
        String id);

}
