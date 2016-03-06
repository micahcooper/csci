<?php
    session_start();
    $_SESSION["queen"];    
?>
<html>
    <head>
	<link rel="stylesheet" href="../assn5/queen.css">
	<title>The Eight Queens AJAXed</title>
	<script language=javascript src=sarissa.js></script>
	<script language=javascript src=sarissa_ieemu_xpath.js></script>
	<script language=javascript>

	    var object;
	    var permanentBoard = new Array(88);

	    /************************************************************
	    * Creates a XMLHTTPRequest object to open a connection to 
	    *   the game logic page, which will evaluate the current
	    *   move.          
	    *								*
	    * Input(s): row - row of new queen placement		*
	    *								*
	    * Error(s): none						*
	    ************************************************************/
	    function checkMove(row,col){
		var move = "row="+row+"&col="+col;;
		object = new XMLHttpRequest();
		object.onreadystatechange = stateAlert;
		object.open("POST","http://zion.cs.uga.edu/~mrcooper/assn6/checkBoard.php?"+move,true,"nathan","nathan");
		object.send("");
	    }
	    /************************************************************
	    * Handles the state change event of the XMLHTTPRequest `	*
	    *								*
	    * Input(s): none						*
	    *								*
	    * Error(s): none						*
	    *								*
	    ************************************************************/
	    function stateAlert(){
		if(object.readyState == 4){
		    extractInfo(object.responseText);
		}
	    }
	    /************************************************************
	    *								*
	    * Extracts the message from the game logic.                 *
	    *								*
	    * Input(s): xmlText - the xml document from the game logic  *
	    *								*
	    * Error(s): none
	    *								*
	    ************************************************************/
	    function extractInfo(xmlText){
		xmlDoc = Sarissa.getDomDocument();
		xmlDoc = (new DOMParser()).parseFromString(xmlText,"text/xml");
   		//alert(xmlText)
		if(xmlDoc.selectSingleNode("/move_result/new_queen")){
		    new_queen = xmlDoc.selectNodes("/move_result/new_queen");
		    new_queen = new_queen.item(0).firstChild.nodeValue;
		    updateBoard(0,new_queen);
		}
		if(xmlDoc.selectSingleNode("/move_result/remove_queen")){
		    r_queen = xmlDoc.selectNodes("/move_result/remove_queen");
		    r_queen = r_queen.item(0).firstChild.nodeValue;
		    updateBoard(1, r_queen);
		}
		if(xmlDoc.selectSingleNode("/move_result/dead_queen")){
		    var attack1, attack2, attack3, attack4;
		    d_queen = xmlDoc.selectNodes("/move_result/dead_queen");
		    d_queen = d_queen.item(0).firstChild.nodeValue;

		    attack1 = xmlDoc.selectSingleNode("/move_result/attackers/attack1");
		    attack1 = attack1.firstChild.nodeValue;
		    blinkTile(d_queen, attack1)
		}
	
	    }
	    /************************************************************
	    * Adds or removes queens to the board.			*
	    *								*
	    * Input(s): arguments[0]-determins if a new queen is place	*
	    *		arguments[1]-id of the tile in question		*
	    *								*
	    * Error(s):none						*
	    ************************************************************/
	    function updateBoard(){
		    tile = document.getElementById(arguments[1]);
		if(arguments[0] == 0){
		    tile = tile.getAttributeNode("class");
		    tile.nodeValue="queenON";
		}
		if(arguments[0] == 1){
		    tile = tile.getAttributeNode("class");
		    tile.nodeValue=permanentBoard[arguments[1]];
		}

 	    }
	    /************************************************************
	    * Animates the current dead queen and one attacker on the	*
	    *   the board.						*
	    *								*
	    * Input(s): arguments[0]-id of the dead queen		*
	    *		arguments[1]-id of the attacking queen		*
	    *								*
	    * Error(s): none						*
	    ************************************************************/
	    function blinkTile(){
		//alert("In Blink Tile");
		original = permanentBoard[arguments[0]];

		d_queen = document.getElementById(arguments[0]);
		d_queen = d_queen.getAttributeNode("class");
		attacker1 = document.getElementById(arguments[1]);
		attacker1 = attacker1.getAttributeNode("class");

		window.setTimeout("d_queen.nodeValue='queenON'", 100);
		window.setTimeout("d_queen.nodeValue='queenOFF'", 500);
		window.setTimeout("d_queen.nodeValue=original", 1000);

		window.setTimeout("attacker1.nodeValue='queenOFF'", 500);
		window.setTimeout("attacker1.nodeValue='queenON'", 1000);

	    }
	    /************************************************************
	    * Creates a permanent board to keep the original colors.	*
	    *								*
	    * Inputs(s):none								*
	    *								*
	    * Error(s):none								*
	    *								*
	    ************************************************************/
	    function createRecallBoard(){
		var tile_counter=0;

		for(row=1; row<9; row++){
		    for(col=1; col<9; col++){
			if((row+col)%2)
			    permanentBoard[(row*10)+col]="grey";
			else
			    permanentBoard[(row*10)+col]="green";
		    }
		}
	    }		
	</script>
    </head>
    <body onload=createRecallBoard()>
	<table class=board>
<?
    	    for($row=1;$row<9;$row++){
	    //print one row on the board
		print "<tr>";
		for($col=1;$col<9;$col++){
		//print one tile of the current column on the board
		    if(($row+$col)%2)
			print "<td class=grey id=$row$col onclick=checkMove($row,$col)></td>\n";
		    else
			print "<td class=green id=$row$col onclick=checkMove($row,$col)></td>\n";
		}
 	    }
?>
	</table>
    </body>
</html>
