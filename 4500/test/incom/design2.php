<?php
  include 'retriever.php'; 

?>
<html>
  <head>
    <link rel=stylesheet href=style2.css>
    <title>BeerSource2</title>
  </head>

  <body>


    <table border=0 class=tablea>
      <tr>
        <td class='log'>
  	  <form method='post' > 
	    <input type='hidden' name='login' value='true' />
            <input type='Submit' value='Log In' class='buttons' />
  	  </form>
  	  <form method='post' > 
	    <input type='hidden' name='newUser' value='true' />
	    <input type='Submit' value='New User' class='buttons'/>
  	  </form>
	</td>
	<td width='600'>
	  <p>Welcome Message</p>
	</td>
      </tr>
      <tr>
	<td class='member'>
	  <p>Member Benefits</p>
<?
          if($_REQUEST['login']){
            print "\t<form method='post'>\n";
            print "\t\t<input type='hidden' name='list'value='true'>\n";
            print "\t\t<input type='submit' value='Retrieve' class='buttons'>\n";
            print "\t</form>\n";
            print "\t<form method='post'>\n";
            print "\t\t<input type='hidden' name='addBeer' value='true'>\n";
            print "\t\t<input type='submit' value='Add' class='buttons'>\n";
            print "\t</form>\n";
          }
?>
	</td>
	<td rowspan='2'>
 	  <p>Beer Information</p>
<?
/*******************************************
*   RETRIEVE BEER LIST
********************************************/
          if($_REQUEST['list']){
  	    $result = find();
            print "\t<form method='post'>\n";
            print "\t\t<select name='beerName'>\n";
	    while($row = mysql_fetch_assoc($result)){
              print "\t\t\t<option>".$row['movieTitle']."</option>\n";
              //print "\t\t\t<option>".$row['name']."</option>\n";
      	    }
            print "\t\t</select>\n";
            print "\t</form>\n";
	  }
/*******************************************
*    NEW USER FORM
*******************************************/
	  if($_REQUEST['newUser']){
            print "\t<form method='post' class='nuForm'>\n";
            print "\t\tUser Name:<input type='text' name='loginName' />\n";
            print "\t\t<br />Password&nbsp&nbsp:<input type='password' name='passone' />\n";
            print "\t\t<br />Password&nbsp&nbsp:<input type='password' name='passtwo' />\n";
            print "\t\t<input type='submit' value='Register!' class='buttons' />\n";
            print "\t</form>\n";
 	  }
/*******************************************
*    ADD A NEW BEER
*******************************************/
	  if($_REQUEST['addBeer']){
            print "\t<form method='post' class='addBeer'>\n";
            print "\t\t<input type='text' name='newBeer' />\n";
            print "\t\t<input type='password' name='passone' />\n";
            print "\t\t<input type='password' name='passtwo' />\n";
            print "\t\t<input type='submit' value='Register!' class='buttons' />\n";
            print "\t</form>\n";
	  }
?>
	</td>
      </tr>
      <tr>
     	<td class='logo'>&nbsp;
	</td>
      </tr>
    </table>

  </body>
</html>
