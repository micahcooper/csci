<?php
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
