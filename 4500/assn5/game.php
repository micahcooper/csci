<?php
    session_start(); //must be very first action before any static content!
    if($_REQUEST["redo"] == 1 ){
	unset($_SESSION["board"]);
	$number_of_queens=0;
    }
    $board = $_SESSION["board"];
    $row= $_REQUEST["row"];
    $col= $_REQUEST["col"];
    if($color == null)
	$color = 0;
    else
    	$color = $_REQUEST["color"];
    if($board[$row][$col] == "Queen")
    	$board[$row][$col]="empty";
    else	
    	$board[$row][$col]="Queen";
    $_SESSION["board"]= $board;
    
?>

<html>
    <head>
	<link rel="stylesheet" href="queen.css">
	<title>The Eight Queens Game</title>
	<script language=javascript src="js_queen.js">
	</script>
    </head>

<?
//GAME LOGIC(six conditions to check for)
	$attack_row=array();
	$attack=array(0,0,0,0);
	$counter=0;

    	for($i=1; $i<9; $i++)
	//search one tile in the same row
	    if(($board[$row][$i] == "Queen") && ($col != $i)){
		$attack[$counter++]=($row*10)+$i;
 	    }
	for($i=1; $i<9; $i++)
	//search for a queen in one tile of the same column
	    if(($board[$i][$col] =="Queen") && ($row != $i)){
		$attack[$counter++]=($i*10)+$col;	
	    }
	for($i=1; $i<9; $i++)
	//seach one tile in same diagonal above
	    if(($board[$row-$i][$col-$i] == "Queen")){
		$attack[$counter++] = (($row-$i)*10)+($col-$i);
	    }
	for($i=1; $i<9; $i++)
	//seach one tile in the same Left/Right diagonal from below
	    if(($board[$row+$i][$col+$i] == "Queen")){
		$attack[$counter++]=(($row+$i)*10)+($col+$i);
	    }
	for($i=1; $i<9; $i++)
	//search one tile in the same Right/Left diagonal from above 
	    if(($board[$row-$i][$col+$i] == "Queen")){
	  	$attack[$counter++]=(($row-$i)*10)+($col+$i);
	    }
	for($i=1; $i<9; $i++)
	//search one tile in the same Right/Left diagonal from below
	    if(($board[$row+$i][$col-$i] == "Queen")){
		$attack[$counter++]=(($row+$i)*10)+($col-$i);
	     }
   if($attack[0] > 0){
	$board[$row][$col] = "empty";
        print "<body onload='blink_cell($attack[0],$attack[1],$attack[2],$attack[3],(($row*10)+$col))'>\n";
    }
   else{
        print "<body>\n";
   }
?>
	<h1>Eight Queens Game</h1>
	<p>To play, try to place, by clicking on an empty space, a total of eight queens on the boards without having two or more queens threaten each other.  You can clear the board by clicking 'Reset Board' or by removing a single piece by clicking on an existing queen.</p>

   	<form name=movement method=post>
	<input type=hidden name=row value=0>
	<input type=hidden name=col value=0>
	<input type=hidden name=redo value=>
	<input type=hidden name=color value=0>
	</form>

<?
	print "<h3 onclick='user_input(0,0,1,$color)'>Reset Board</h3>\n";
?>

	<table class=board>
<?php
    if($color % 2){
	$color1 = "red";
	$color2 = "black";
    }
    else{
	$color1 = "grey";
	$color2 = "green";
    }


    for ($row=1;$row<9;$row++){
    //draw one row of the board
     	print "<tr>";
     	for ($col=1;$col<9;$col++)
     	//print a cell
            if ($board[$row][$col] == "Queen"){
		$number_of_queens++; 
              	print "<td class=queenON id=$row$col onclick=user_input($row,$col,0,$color)></td>\n";
	    }
            else if (($row+$col)%2){ 
		if($board[$row][$col] == "empty")
		    print "<td class=$color1 id=$row$col onclick=user_input($row,$col,0,$color)></td>\n";
		else
              	    print "<td class=$color1  onclick=user_input($row,$col,0,$color)></td>\n";
	    }
            else{ 
		if($board[$row][$col] == "empty")
		    print "<td class=$color2 id=$row$col onclick=user_input($row,$col,0,$color)></td>\n";
		else
              	    print "<td class=$color2  onclick=user_input($row,$col,0,$color)></td>\n";
	    }

            print "</tr>\n";
    }//for each row
?>

<?
    if($number_of_queens==8)
	print "<span class=win>You Win!!</span>";	

    print "</table>";
    print "<h3 onclick=user_input(null,null,0,($color+1))>Change Colors</h3>";
?>
    </body>
</html>
