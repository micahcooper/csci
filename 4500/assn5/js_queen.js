/************************************************************************
 *   Assigns values to the hidden fields in the movement		*
 *      form on the page supplied from user				*
 *									*
 *									*
 *  Input(s):  	arguments[0] = row value from user input 		*
 *		arguments[1] = column value from user input		*
 *		arguments[2] = reset board value;			*
 *		arguments[3] = change color value			*
 *									*
 *  Error(s): none							*
 ***********************************************************************/
function user_input(){
	document.movement.row.value=arguments[0];
	document.movement.col.value=arguments[1];
	document.movement.redo.value=arguments[2];
	document.movement.color.value=arguments[3];
	document.movement.submit();

}
/************************************************************************
 *  Changes attribues of the 'dead' queen to the original color		*
 *     of the board tile.						*
 *									*
 *  Input(s): id of the 'dead' queen					*
 *									*
 *  Error(s): none							*
 ***********************************************************************/
function remove_queen(target){
    ex_queen = document.getElementById(target).attributes.item(2);
    if(target % 2)
	ex_queen.nodeValue="green";
    else
	ex_queen.nodeValue="grey";
}
/*************************************************************************
 *   Diplays a blinking queen to indicate a wrong move, the attacking    *
 *         queen also blinks for an amount of time			 *
 *									 *
 *   Input(s):dead = the user's bad move for a new queen position	 *
 *            attack X 4 = upto 4 threating queens already on the board	 *
 *									 *
 *   Error(s):none							 *
 ************************************************************************/
function blink_cell(attack1,attack2,attack3,attack4,dead){

    if(attack1 > 0){
    	temp = document.getElementById(attack1).attributes.getNamedItem("class");
	window.setTimeout("temp.nodeValue='queenOFF'",500);
	window.setTimeout("temp.nodeValue='queenON'",1000);
    }
    if(attack2 > 0){
    	temp1 = document.getElementById(attack2).attributes.getNamedItem("class");
	window.setTimeout("temp1.nodeValue='queenOFF'",500);
	window.setTimeout("temp1.nodeValue='queenON'",1000);
    }
    if(attack3 > 0){
    	temp2 = document.getElementById(attack3).attributes.getNamedItem("class");
	window.setTimeout("temp2.nodeValue='queenOFF'",500);
	window.setTimeout("temp2.nodeValue='queenON'",1000);
    }
    if(attack4 > 0){
    	temp3 = document.getElementById(attack4).attributes.getNamedItem("class");
	window.setTimeout("temp3.nodeValue='queenOFF'",500);
	window.setTimeout("temp3.nodeValue='queenON'",1000);
    }
    temp4 = document.getElementById(dead).attributes.getNamedItem("class");
    save = temp4.nodeValue;
    window.setTimeout("temp4.nodeValue='queenON'", 100);
    window.setTimeout("temp4.nodeValue='queenOFF'", 500);
    window.setTimeout("temp4.nodeValue=save", 1000);
}
