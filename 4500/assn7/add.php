assn7/auth_mod.php                                                                                  0000777 0001750 0001750 00000012535 10603040126 013767  0                                                                                                    ustar   cooper                          cooper                                                                                                                                                                                                                 <?php
    session_start();

    if($_SESSION["registered_user"]){
	$loginName = $_SESSION["registered_user"];
 	print "<h3>Welcome $loginName!</h3>\n";
 	print "<p>Please navigate the site with the menu above.</p>\n";
    }
?>
<html>
    <head>
	<link rel="stylesheet" href="http://www.cs.uga.edu/~cooper/4300/assn7/movie.css">
	<script type=text/javascript>
	    function verifyLoginInfo(){
		if( document.register.new_user.value.length < 5){
		    alert("Your login name is too short.\n It must be at least 5 characters long.");
		    return false;
		}
		if( document.register.password1.value.length < 6){
		    alert("The first password is too short.\n It must be at least 6 characters long.");
		    return false;
		}
		if( document.register.password2.value.length < 6){
		    alert("The second password is too short.\n It must be at least 6 characters long.");
		    return false;
		}
		return true;
	    } 
	</script>
    </head>
    
    <body>
<?
    /***************************************************
    * If input information match a registered user 
    *  initialize session variable 'registered_user'.
    *
    * Input(s):  loginName - CGI input 
    *            password - CGI input
    *            movie_users - table in mrcooper database
    *
    * Error(s): none
    ***************************************************/
    if($_REQUEST["loginName"]){
	$loginName = addslashes($_REQUEST["loginName"]);
	$password = md5($_REQUEST["password"]);

	//connect to and selct database
	$link = mysql_connect("localhost","mrcooper","") or die(mysql_error());
	mysql_select_db("mrcooper") or die(mysql_error());
	
	//my query to find existing user
	$query = "select * from temp_users where login_name='$loginName' and passwd='$password'"; 
	$result = mysql_query($query) or die(mysql_error());
	
	if(mysql_num_rows($result)==1){
	    $loginName = stripslashes($loginName);
 	    print "<h3>Welcome $loginName!</h3>\n";
 	    print "<p>Please navigate the site with the menu above.</p>\n";
	    $_SESSION["registered_user"] = $loginName;
	}
	else{
	    print "Login unsuccessful, please try again<br>\n";
	}
    }


    /********************************************************
    * Set session variable 'registered_user' and store in the
    *    mrcooper database table 'movie_users', the new users 
    *    data if 'new_user', 'password1' and 'password2' are 
    *    provided.
    * 
    * Input(s): new_user - CGI input
    *           password1 - CGI input
    *           password2 - CGI input
    *           movie_users - table in mrcooper database
    *
    * Input requirement: 'new_user' - must be 5 char long
    *  	                password1, password2 must match and
    *                   be 6 char long
    *
    * Error(s): none
    ********************************************************/
    if($_REQUEST["new_user"]){
	$new_user = addslashes($_REQUEST["new_user"]);
	$password1 = md5($_REQUEST["password1"]);
	$password2 = md5($_REQUEST["password2"]);

	//check passwords for equality
	$equal = strcmp($password1, $password2);
	if($equal == 0){
	    //connect to select database
	    $link = mysql_connect("localhost","mrcooper","") or die("ConnNew ".mysql_error());
	    mysql_select_db("mrcooper") or die("DataNew ".mysql_error());

	    //check for exiting registered user
	    $find = "select * from temp_users where login_name='$new_user'";
	    $search = mysql_query($find) or die("SearchNew ".mysql_error());
	    if(mysql_num_rows($search)==0){
	        $query = "insert into temp_users set login_name='$new_user', passwd='$password1'";
	        mysql_query($query) or die (mysql_error());
	        $new_user = stripslashes($new_user);
	        $_SESSION["registered_user"] = $new_user;
 	        print "<h3>Welcome $new_user!</h3>\n";
 	        print "<p>Please navigate the site with the menu above.</p>\n";
	    }
	    else{
	        print "Sorry user name already exists, please choose another.<br>\n";
	    }
	}
	else{
	    print "<h4 class=badPass>Passwords did not match!</h4>Please try again.\n";
	}


    }

    /********************************************************
    * PRINT FORMS
    * If session variable 'registered_user' does not exit,
    *    then reshow a form for user login and a new form for
    *    a new user to register.
    *
    * Input(s): none
    *
    * Error(s): none
    ********************************************************/
 
    if(!($_SESSION["registered_user"])){
	print "<h3>Existing Users</h3> ";
	print "<form name='login' method='post'>\n";
	print "User Name:<br/>\n";
	print "<input type=text name=loginName size=20><br/>\n";
	print "Password:<br/>\n";
	print "<input type=password name=password size=20><br/>\n";
	print "<input type=submit value=Login><br/>\n";
	print "</form><br/><br/>\n";

	print "<h3>New User Registration</h3>\n";
	print "<form name='register' method='post' ";
	print "action=auth_mod.php onsubmit='return verifyLoginInfo()'><br/>\n";
	print "Create a login name<br/>(must be at least 5 characters long):<br/>\n";
	print "<input type=text name=new_user size=20 value=";
	print $_REQUEST['new_user']."><br/>\n";
	print "Create a password<br/>(must be 6 characters long)<br/>\n";
	print "<input type=password name=password1 size=20><br/>\n";
	print "Re-type your password<br/>\n";
	print "<input type=password name=password2 size=20><br/>\n";
	print "<input type=submit value=Register!><br/>\n";
	print "</form><br/>\n";
    }
?>
    </body>
</html>
                                                                                                                                                                   assn7/login.php                                                                                     0000777 0001750 0001750 00000001476 10603043704 013306  0                                                                                                    ustar   cooper                          cooper                                                                                                                                                                                                                 <?php
    session_start();
    if($_REQUEST["clear"] == 1)
    	unset($_SESSION["registered_user"]);
?>
<html>
    <head>
	<title>Start Page</title>
    </head>

<body>
    <h2>Movie Reviews Website</h2>
<?
    if(!$_SESSION["registered_user"]){
    	print   "<form name=login method=post action=auth_mod.php>\n";
    	print   "<span>User Name:</span><br/>\n";
    	print   "<input type=text name=loginName size=20><br/>\n";
    	print   "<span>Password:</span><br/>\n";
    	print   "<input type=password name=password size=20>\n";
    	print   "<input type=submit value=Login>\n";
    	print   "</form>\n";
    	print   "<br/>\n";
    	print   "<a href=auth_mod.php target=main>New User Registration</a><br/>\n";
    }
    else
	print "<h4>Already Logged In</h4>Please use menu above to navigate the site\n";
?>
</body>
</html>
                                                                                                                                                                                                  assn7/menu.php                                                                                      0000777 0001750 0001750 00000001006 10603037566 013140  0                                                                                                    ustar   cooper                          cooper                                                                                                                                                                                                                 <html>
    <head>
	<link rel="stylesheet" href="http://www.cs.uga.edu/~cooper/4300/assn7/movie.css">
    <head>

    <body>
	<table class=nav>
	    <tr>
		<td><a href='movie.php' target='main'>Search Movies</a></td>
		<td><a href='add.php' target='main'>Add a Review</a></td>
		<td><a href='add.php?simple=1' target='main'>Add a Movie</a></td>
		<td></td>
		<td><a href='login.php' target='main'>Login</a></td>
		<td><a href='login.php?clear=1' target='main'>Logout</a></td>

	    </tr>
	</table>	
    </body>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          assn7/movie.php                                                                                     0000777 0001750 0001750 00000010000 10603042544 013275  0                                                                                                    ustar   cooper                          cooper                                                                                                                                                                                                                 <?php
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
assn7/README                                                                                        0000777 0001750 0001750 00000000112 10603043404 012324  0                                                                                                    ustar   cooper                          cooper                                                                                                                                                                                                                 To start the php database project, please use the start_here.html page.


                                                                                                                                                                                                                                                                                                                                                                                                                                                      assn7/start_here.html                                                                               0000777 0001750 0001750 00000000336 10602060352 014502  0                                                                                                    ustar   cooper                          cooper                                                                                                                                                                                                                 <html>
    <head>
        <title>MOVIE REVIEWS</title>
    </head>

    <frameset rows="40px,*" border=1>
	<frame src=menu.php name="menu" scrolling=NO>
	<frame src=login.php name="main">
    </frameset>
</html>
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  