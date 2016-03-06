<?php
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
