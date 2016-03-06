
package weiss;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the weiss package. 
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

    private final static QName _GetMovieReviews_QNAME = new QName("http://jweiss/", "getMovieReviews");
    private final static QName _GetMovieReviewsResponse_QNAME = new QName("http://jweiss/", "getMovieReviewsResponse");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: weiss
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link GetMovieReviews }
     * 
     */
    public GetMovieReviews createGetMovieReviews() {
        return new GetMovieReviews();
    }

    /**
     * Create an instance of {@link GetMovieReviewsResponse }
     * 
     */
    public GetMovieReviewsResponse createGetMovieReviewsResponse() {
        return new GetMovieReviewsResponse();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetMovieReviews }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://jweiss/", name = "getMovieReviews")
    public JAXBElement<GetMovieReviews> createGetMovieReviews(GetMovieReviews value) {
        return new JAXBElement<GetMovieReviews>(_GetMovieReviews_QNAME, GetMovieReviews.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetMovieReviewsResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://jweiss/", name = "getMovieReviewsResponse")
    public JAXBElement<GetMovieReviewsResponse> createGetMovieReviewsResponse(GetMovieReviewsResponse value) {
        return new JAXBElement<GetMovieReviewsResponse>(_GetMovieReviewsResponse_QNAME, GetMovieReviewsResponse.class, null, value);
    }

}
