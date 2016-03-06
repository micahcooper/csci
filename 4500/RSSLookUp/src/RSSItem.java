package mrcooper;

public class RSSItem{

    private String title;
    private String story; 
    private String date;

    public RSSItem(String title, String story, String pubDate){
	this.title = title;
	this.story = story;
	this.date = date;
    }

    public String getTitle(){
	return title;
    }

    public String getStory(){
	return story;
    }

    public String getDate(){
	return date;
    }

}
