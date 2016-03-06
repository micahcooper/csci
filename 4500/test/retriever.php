<?php
  session_start();

  function find(){
    $link = mysql_connect("localhost","mrcooper","") or die(mysql_error());
    //$link = mysql_connect("fdb1.awardspace.com","mrcooper_db","arakis") or die(mysql_error());
    mysql_select_db("mrcooper") or die(mysql_error());
    //mysql_select_db("mrcooper_db") or die(mysql_error());

    $find = "SELECT * FROM movieTable";
    //$find = "SELECT * FROM beerList";
    $result = mysql_query($find) or die(mysql_error());

    mysql_close($link);
    return $result;
  }

  function insertBeer($beerName, $brewer){
    $link = mysql_connect("localhost","mrcooper","") or die(mysql_error());
    //$link = mysql_connect("fdb1.awardspace.com","mrcooper_db","arakis") or die(mysql_error());
    mysql_select_db("mrcooper") or die(mysql_error());
    //mysql_select_db("mrcooper_db") or die(mysql_error());

    $add_review = "INSERT INTO beerList (name, maker) VALUES($beerName, $brewer)";

  }
?>
