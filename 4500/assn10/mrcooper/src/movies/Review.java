package movies;  

public class Review{
    private String author;
    private String comments;
    private String time;

    public Review(String author, String comments, String time){
	this.author = author;
  	this.comments = comments;
 	this.time = time;
    }	

    public String getAuthor(){
	return author;
    }
    public String getComments(){
	return comments;
    }
    public String getTime(){
	return time;
    }


}
