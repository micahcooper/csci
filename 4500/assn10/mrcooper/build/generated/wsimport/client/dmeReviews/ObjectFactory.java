
package dmeReviews;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the dmeReviews package. 
 * <p>An ObjectFactory allows you to programatically 
 * construct new instances of the Java representation 
 * for XML content. The Java representation of XML 
 * content can consist of schema derived interfaces 
 * and classes representing the binding of schema 
 * type definitions, element declarations and model 
 * groups.  Factory methods for each of these are 
 * provided in this class.
 * 
 */
@XmlRegistry
public class ObjectFactory {

    private final static QName _GetReviewsResponse_QNAME = new QName("http://cs4300/", "getReviewsResponse");
    private final static QName _GetReviews_QNAME = new QName("http://cs4300/", "getReviews");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: dmeReviews
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link GetReviews }
     * 
     */
    public GetReviews createGetReviews() {
        return new GetReviews();
    }

    /**
     * Create an instance of {@link GetReviewsResponse }
     * 
     */
    public GetReviewsResponse createGetReviewsResponse() {
        return new GetReviewsResponse();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetReviewsResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://cs4300/", name = "getReviewsResponse")
    public JAXBElement<GetReviewsResponse> createGetReviewsResponse(GetReviewsResponse value) {
        return new JAXBElement<GetReviewsResponse>(_GetReviewsResponse_QNAME, GetReviewsResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetReviews }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://cs4300/", name = "getReviews")
    public JAXBElement<GetReviews> createGetReviews(GetReviews value) {
        return new JAXBElement<GetReviews>(_GetReviews_QNAME, GetReviews.class, null, value);
    }

}
