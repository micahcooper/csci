
package dohcjsReviews;

import java.net.MalformedURLException;
import java.net.URL;
import javax.xml.namespace.QName;
import javax.xml.ws.Service;
import javax.xml.ws.WebEndpoint;
import javax.xml.ws.WebServiceClient;


/**
 * This class was generated by the JAXWS SI.
 * JAX-WS RI 2.0_01-b59-fcs
 * Generated source version: 2.0
 * 
 */
@WebServiceClient(name = "dohcjsReviewListServiceService", targetNamespace = "http://catalog/", wsdlLocation = "http://zion.cs.uga.edu:8081/dohcjsReview/dohcjsReviewListService?wsdl")
public class DohcjsReviewListServiceService
    extends Service
{

    private final static URL DOHCJSREVIEWLISTSERVICESERVICE_WSDL_LOCATION;

    static {
        URL url = null;
        try {
            url = new URL("http://zion.cs.uga.edu:8081/dohcjsReview/dohcjsReviewListService?wsdl");
        } catch (MalformedURLException e) {
            e.printStackTrace();
        }
        DOHCJSREVIEWLISTSERVICESERVICE_WSDL_LOCATION = url;
    }

    public DohcjsReviewListServiceService(URL wsdlLocation, QName serviceName) {
        super(wsdlLocation, serviceName);
    }

    public DohcjsReviewListServiceService() {
        super(DOHCJSREVIEWLISTSERVICESERVICE_WSDL_LOCATION, new QName("http://catalog/", "dohcjsReviewListServiceService"));
    }

    /**
     * 
     * @return
     *     returns DohcjsReviewListService
     */
    @WebEndpoint(name = "dohcjsReviewListServicePort")
    public DohcjsReviewListService getDohcjsReviewListServicePort() {
        return (DohcjsReviewListService)super.getPort(new QName("http://catalog/", "dohcjsReviewListServicePort"), DohcjsReviewListService.class);
    }

}
