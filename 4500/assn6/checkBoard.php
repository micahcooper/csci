<?php
    session_start();
    header('Content-type: text/xml');
    print "<?xml version=\"1.0\" ?>\n";

    $board = $_SESSION["board"];
    $current_row = $_REQUEST["row"];
    $current_col = $_REQUEST["col"];

    $new_queen = 0;
    $remove_queen = 0;
    $dead_queen = 0;

    if($board[$current_row][$current_col] != "Queen"){
        $board[$current_row][$current_col] = "Queen";
        $new_queen = $current_row*10+$current_col;
    }
    else{
	unset($board[$current_row][$current_col]);
	$remove_queen = $current_row*10+$current_col;
    }
 	
    $_SESSION["board"] = $board;
?>
<!DOCTYPE move_result [
	<!ELEMENT move_result (remove_queen?,(new_queen|dead_queen)?, attackers?)>
	<!ELEMENT remove_queen (#PCDATA)>
	<!ELEMENT new_queen (#PCDATA)>
	<!ELEMENT dead_queen (#PCDATA)>
	<!ELEMENT attackers (attack1?, attack2?, attak3?, attack4?)>
	<!ELEMENT attack1 (#PCDATA)>
	<!ELEMENT attack2 (#PCDATA)>
	<!ELEMENT attack3 (#PCDATA)>
	<!ELEMENT attack4 (#PCDATA)>
]>
<?
//GAME LOGIC(six conditions to check for)
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
	    $dead_queen = $new_queen;
	    $new_queen = 0;
	    unset($board[$current_row][$current_col]);
	    $_SESSION["board"] = $board;
	}

    print "<move_result>";
    if($remove_queen != 0){
        print "\n\t<remove_queen>";
        print     "$remove_queen";
        print "</remove_queen>\n";
    }

    if($new_queen != 0){
        print "\n\t<new_queen>";
        print     "$new_queen";
        print "</new_queen>\n";
    }
    if($dead_queen != 0){
        print "\n\t<dead_queen>";
        print     "$dead_queen";
        print "</dead_queen>\n";
    }

    if($attack[0] != 0){
        print "\t<attackers>\n";
        print     "\t\t<attack1>$attack[0]</attack1>\n";
	if($attack[1] != 0)
            print  "\t\t<attack2>$attack[1]</attack2>\n";
        if($attack[2] != 0)
            print  "\t\t<attack3>$attack[2]</attack3>\n";
        if($attack[3] != 0)
    	    print  "\t\t<attack4>$attack[3]</attack4>\n";
        print     "\t</attackers>\n";
    }
    print "</move_result>";
?>
