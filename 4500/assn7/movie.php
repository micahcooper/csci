<?php
    session_start();
?>
<html>
    <head>
    	<META http-equiv="Content-Type" content="text/html; charset=utf-8">
	<title>Search Reviews</title>
	<link rel="stylesheet" href="http://www.cs.uga.edu/~cooper/4300/assn7/movie.css">
    </head>

    <body>
<?
    /*********************************************************************
    *
    *********************************************************************/


    /*********************************************************************
    * Displays a compilation of reviews based on 'movieTitle'.
    *
    * Input(s): movieTitle - CGI variable(name of movie)
    *
    * Error(s): if no movie found based on 'movieTitle', prints message
    *********************************************************************/
    if($_REQUEST["movieTitle"]){
 	$movie = addslashes($_REQUEST["movieTitle"]);

	//normalize movie title
	$movie = mb_convert_case($movie, MB_CASE_TITLE, "UTF-8");

	//connect to and selct database	
	$link = mysql_connect("localhost","mrcooper","") or die(mysql_error());
	mysql_select_db("mrcooper") or die(mysql_error());

	//get unique id if 'movieTitle' exists in 'movieTable'
	$find = "SELECT title_id FROM movieTable WHERE movieTitle='$movie'";
	$result = mysql_query($find) or die(mysql_error());
	$movie_id = mysql_fetch_row($result);

	//find rows in table 'moveReviews' with '$movie_id'
	$find = "SELECT userName,comments FROM movieReviews WHERE title_id='$movie_id[0]'";
	$result = mysql_query($find) or die(mysql_error());

	//print, if any, found reviews and the user
	$movie = stripslashes($movie);
	print "<h3>$movie Reviews</h3>\n";
	while($row = mysql_fetch_assoc($result)){
	//print one review and one reviewer
	    print "Review: ".$row['comments']."<br/>\n";
	    print "BY - ".$row['userName']."<br/><br/>\n";
	}

    }
    /*********************************************************************
    * Displays a list of movies based on their genre.
    *
    * Input(s): genre - CGI variable 
    *
    * Error(s): none
    *********************************************************************/
    if($_REQUEST["genre"]){
	//connect to and select a database
	$link = mysql_connect("localhost", "mrcooper","") or die(mysql_error());
	mysql_select_db("mrcooper") or die(mysql_error());

	//find rows in table 'movieTable' with '$genre'
	$find = "SELECT movieTitle FROM movieTable WHERE genre='$genre'";
	$result = mysql_query($find) or die (mysql_error());

	//print movie found by genre, if they exist
	print "<h3>$genre Movies</h3><ol>\n";
	while($row = mysql_fetch_assoc($result)){
	//print one movie
	    $addr = str_replace(" ", "+", $row["movieTitle"]);
	    print "<li><a href=movie.php?movieTitle=$addr";
	    print ">".$row['movieTitle']."</a></li>\n";
	}
	print "</ol>\n";
    }
    /*********************************************************************
    *
    *********************************************************************/
    /*********************************************************************
    * Displays search form.  
    *
    * Input(s): none
    * Error(s): none
    *********************************************************************/
    else if(!$_REQUEST["movieTitle"]){
        print "<h3>Search Movie Reviews</h3>\n";
        print "<form name=searchByTitle method=post>\n";
        print "<span>Movie Title:</span><br/>\n";
        print "<input type=text name=movieTitle size=20>\n";
        print "<input type=submit value=SEARCH>\n";
        print "</form><br/>\n";
        print "<form name=searchByGenre method=post>\n";
        print "<span>Genre:</span><br/>\n";
        print "<select name=genre>\n";
        print    "<option value=Action>Action</option>\n";
        print	 "<option value=Comedy>Comedy</option>\n";
        print	 "<option value=Documentary>Documentary</option>\n";
        print	 "<option value=Drama>Drama</option>\n";
        print	 "<option value=Horror>Horror</option>\n";
        print     "</select>\n";
        print     "<input type=submit value='Get Movies!'>\n";
        print "</form>\n";
    }
?>
    </body>
</html>
