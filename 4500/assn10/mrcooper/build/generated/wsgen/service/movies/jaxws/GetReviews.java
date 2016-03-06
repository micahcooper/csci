
package movies.jaxws;

import javax.xml.bind.annotation.XmlAccessType;
import javax.xml.bind.annotation.XmlAccessorType;
import javax.xml.bind.annotation.XmlElement;
import javax.xml.bind.annotation.XmlRootElement;
import javax.xml.bind.annotation.XmlType;

@XmlRootElement(name = "getReviews", namespace = "http://movies/")
@XmlAccessorType(XmlAccessType.FIELD)
@XmlType(name = "getReviews", namespace = "http://movies/")
public class GetReviews {

    @XmlElement(name = "movie_id", namespace = "")
    private int movie_id;

    /**
     * 
     * @return
     *     returns int
     */
    public int getMovie_id() {
        return this.movie_id;
    }

    /**
     * 
     * @param movie_id
     *     the value for the movie_id property
     */
    public void setMovie_id(int movie_id) {
        this.movie_id = movie_id;
    }

}
