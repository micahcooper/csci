<?php
  include 'retriever.php';
?>
<html>
    <head>
   	<link rel=stylesheet href=style1.css>
  	<title>BeerSource</title>
    </head>

    <body>
<?

  if($_REQUEST["bar"]){
    $foo3 = find($_REQUEST["bar"]);
  }

  print "<table>\n";
  print   "<tr>\n";
  print     "<td colspan=2 class='menuTitle'>\n";
  print       "<p>Brew Reviews</p>\n";
  print     "</td>\n";
  print   "</tr>\n";
  print   "<tr>\n";
  print     "<td>\n";
  print       "<form method='post'>\n";
  print         "<input type='hidden' name='login' value='true'>\n";
  print         "<input type='submit' value='Login' class='buttons'>\n";
  print       "</form>\n";
  print     "</td>\n";
  print     "<td>\n";
  print       "<form method='post'>\n";
  print         "<input type='hidden' name='newUser' value='true'>\n";
  print         "<input type='submit' value='New User' class='buttons'>\n";
  print       "</form>\n";
  print     "</td>\n";
  print   "</tr>\n";
  print   "<tr>\n";
  print     "<td>\n";
  print       "<form method='post'>\n";
  print         "<input type='hidden' name='bar' value='true'>\n";
  print         "<input type='submit' value='Retrieve' class='buttons'>\n";
  print       "</form>\n";
  print     "</td>\n";
  print     "<td>\n";
  print       "<form method='post'>\n";
  print         "<input type='hidden' name=add value='true'>\n";
  print         "<input type='submit' value='Add' class='buttons'>\n";
  print       "</form>\n";
  print     "</td>\n";
  print   "</tr>\n";

  print "</table>\n";

  if($_REQUEST['add']){
    print "<table>\n";
    print   "<tr>\n";
    print     "<td>\n";
    print       "<form method='post'>\n";
    print         "Name<input type='text' size=10 class='texta'>\n";
    print         "Company<select name='company'>\n";
    print           "<option value=>Abita</option>\n";
    print           "<option value=>Red Hook</option>\n";
    print         "</select>\n";
    print         "Rate<select name='rate'>\n";
    print           "<option value=>1</option>\n";
    print           "<option value=>2</option>\n";
    print           "<option value=>3</option>\n";
    print         "</select>\n";
    print       "</form>\n";
    print     "</td>\n";
    print   "</tr>\n";
    print "</table>\n";
  }
     

  if($foo3){
    print "<table>\n";
    print   "<tr>\n";
    print     "<td>\n";
    print       "<form>\n";
    print         "<select>\n";
    while($row = mysql_fetch_assoc($foo3)){
      print         "<option>".$row['movieTitle']."</option>\n";
      //print         "<option>".$row['name']."</option>\n";
    }
    print         "</select>\n";
    print       "</form>\n";
    print     "</td>\n";
    print   "</tr>\n";
    print "</table>\n";
  }

  if($_REQUEST['login']){
    print "<table>\n";
    print    "<tr>\n";
    print      "<td>\n";
    print        "User Name<br>Pass\n";
    print      "</td>\n";
    print      "<td>\n";
    print        "<form method='post'>\n";
    print          "<input type='text' name='userName' size=10 class='texta'>\n";
    print          "<br><input type='password' name='passwd' size=10 class='texta'>\n";
    print        "</form>\n";
    print      "</td>\n";
    print    "</tr>\n";
    print "</table>\n";
  }

  if($_REQUEST['newUser']){
    print "<table>\n";
    print    "<tr>\n";
    print      "<td>\n";
    print      "</td>\n";
    print      "<td>\n";
    print        "<form method='post'>\n";
    print        "</form>\n";
    print      "</td>\n";
    print    "</tr>\n";
    print "</table>\n";
  }
?>

    </body>
</html>
