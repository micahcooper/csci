// Micah Cooper
// CSCI4300 project10
//
// Movie.class

package movies;

public class Movie{
    private String title;
    private String genre;
    private String id;

    /**
    * Constructor to initialize the movie entity properites.
    *
    * @param title	title of the movie
    * @param genre	genre of the movie
    * @param id		id of the movie
    *
    */
    public Movie(String id, String title, String genre){
	this.id = id;
	this.title = title;
	this.genre = genre;
    }

    public String getTitle(){
	return title;
    }
   
    public String getGenre(){
	return genre;
    }

    public String getId(){
	return id;
    }
}
