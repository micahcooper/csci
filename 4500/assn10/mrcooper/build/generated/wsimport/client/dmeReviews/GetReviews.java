
package dmeReviews;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for getReviews complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="getReviews">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="movie_id" type="{http://www.w3.org/2001/XMLSchema}int"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "getReviews", propOrder = {
    "movieId"
})
public class GetReviews {

    @XmlElement(name = "movie_id")
    protected int movieId;

    /**
     * Gets the value of the movieId property.
     * 
     */
    public int getMovieId() {
        return movieId;
    }

    /**
     * Sets the value of the movieId property.
     * 
     */
    public void setMovieId(int value) {
        this.movieId = value;
    }

}
