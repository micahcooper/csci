
package movies;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlType;


/**
 * <p>Java class for registerMovie complex type.
 * 
 * <p>The following schema fragment specifies the expected content contained within this class.
 * 
 * <pre>
 * &lt;complexType name="registerMovie">
 *   &lt;complexContent>
 *     &lt;restriction base="{http://www.w3.org/2001/XMLSchema}anyType">
 *       &lt;sequence>
 *         &lt;element name="movieTitle" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *         &lt;element name="movieGenre" type="{http://www.w3.org/2001/XMLSchema}string" minOccurs="0"/>
 *       &lt;/sequence>
 *     &lt;/restriction>
 *   &lt;/complexContent>
 * &lt;/complexType>
 * </pre>
 * 
 * 
 */
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "registerMovie", propOrder = {
    "movieTitle",
    "movieGenre"
})
public class RegisterMovie {

    protected String movieTitle;
    protected String movieGenre;

    /**
     * Gets the value of the movieTitle property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMovieTitle() {
        return movieTitle;
    }

    /**
     * Sets the value of the movieTitle property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMovieTitle(String value) {
        this.movieTitle = value;
    }

    /**
     * Gets the value of the movieGenre property.
     * 
     * @return
     *     possible object is
     *     {@link String }
     *     
     */
    public String getMovieGenre() {
        return movieGenre;
    }

    /**
     * Sets the value of the movieGenre property.
     * 
     * @param value
     *     allowed object is
     *     {@link String }
     *     
     */
    public void setMovieGenre(String value) {
        this.movieGenre = value;
    }

}
