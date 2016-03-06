
package movies;

import javax.xml.bind.JAXBElement;
import javax.xml.bind.annotation.XmlElementDecl;
import javax.xml.bind.annotation.XmlRegistry;
import javax.xml.namespace.QName;


/**
 * This object contains factory methods for each 
 * Java content interface and Java element interface 
 * generated in the movies package. 
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

    private final static QName _GetMovieCatalogResponse_QNAME = new QName("http://cs4300/", "getMovieCatalogResponse");
    private final static QName _RegisterMovieResponse_QNAME = new QName("http://cs4300/", "registerMovieResponse");
    private final static QName _RegisterMovie_QNAME = new QName("http://cs4300/", "registerMovie");
    private final static QName _GetMovieCatalog_QNAME = new QName("http://cs4300/", "getMovieCatalog");

    /**
     * Create a new ObjectFactory that can be used to create new instances of schema derived classes for package: movies
     * 
     */
    public ObjectFactory() {
    }

    /**
     * Create an instance of {@link RegisterMovie }
     * 
     */
    public RegisterMovie createRegisterMovie() {
        return new RegisterMovie();
    }

    /**
     * Create an instance of {@link GetMovieCatalogResponse }
     * 
     */
    public GetMovieCatalogResponse createGetMovieCatalogResponse() {
        return new GetMovieCatalogResponse();
    }

    /**
     * Create an instance of {@link RegisterMovieResponse }
     * 
     */
    public RegisterMovieResponse createRegisterMovieResponse() {
        return new RegisterMovieResponse();
    }

    /**
     * Create an instance of {@link GetMovieCatalog }
     * 
     */
    public GetMovieCatalog createGetMovieCatalog() {
        return new GetMovieCatalog();
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetMovieCatalogResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://cs4300/", name = "getMovieCatalogResponse")
    public JAXBElement<GetMovieCatalogResponse> createGetMovieCatalogResponse(GetMovieCatalogResponse value) {
        return new JAXBElement<GetMovieCatalogResponse>(_GetMovieCatalogResponse_QNAME, GetMovieCatalogResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link RegisterMovieResponse }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://cs4300/", name = "registerMovieResponse")
    public JAXBElement<RegisterMovieResponse> createRegisterMovieResponse(RegisterMovieResponse value) {
        return new JAXBElement<RegisterMovieResponse>(_RegisterMovieResponse_QNAME, RegisterMovieResponse.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link RegisterMovie }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://cs4300/", name = "registerMovie")
    public JAXBElement<RegisterMovie> createRegisterMovie(RegisterMovie value) {
        return new JAXBElement<RegisterMovie>(_RegisterMovie_QNAME, RegisterMovie.class, null, value);
    }

    /**
     * Create an instance of {@link JAXBElement }{@code <}{@link GetMovieCatalog }{@code >}}
     * 
     */
    @XmlElementDecl(namespace = "http://cs4300/", name = "getMovieCatalog")
    public JAXBElement<GetMovieCatalog> createGetMovieCatalog(GetMovieCatalog value) {
        return new JAXBElement<GetMovieCatalog>(_GetMovieCatalog_QNAME, GetMovieCatalog.class, null, value);
    }

}
