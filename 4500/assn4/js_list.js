/* Using the document object from DOM, appends a SPAN element to the
 *  parent object of any ordered or unordered list in the document.  
 *
 * Input(s): none
 *
 * Error(s): If no parent object has no text in the text field dismiss 
 *               and do not add Span element
 */
function listDriver(){
	var ol_list = document.getElementsByTagName("ol");
	var ul_list = document.getElementsByTagName("ul");
	var title_list = new Array();
	var span_list = new Array();
	var close_tag = new Array();
	var counter=0;

	for(i=0; i<ol_list.length; i++){
	//find title of ordered list and create span element
		if(!((ol_list[i].parentNode.firstChild.length <= 5)||(ol_list[i].parentNode.firstChild.length == null))){
			title_list[counter] = ol_list[i].parentNode;
			span_list[counter] = document.createElement("span");
			close_tag[counter] = document.createTextNode("- ");
			addHandler(span_list[counter++]);
		}
	}

	for(i=0; i<ul_list.length; i++){
	//find title of unordered list and create span element
		if(!((ul_list[i].parentNode.firstChild.length <= 5)||(ul_list[i].parentNode.firstChild.length == null))){
			title_list[counter] = ul_list[i].parentNode;
			span_list[counter] = document.createElement("span");
			close_tag[counter] = document.createTextNode("- ");
			addHandler(span_list[counter++]);
		}
	}

	for(i=0; i<title_list.length; i++){
	//append new span element to title and close list
		span_list[i].appendChild(close_tag[i]);
		//setAttribute is supported by Mozilla
		span_list[i].setAttribute("class","tag");
		//style.fontSize is supported by IE
		span_list[i].style.fontSize = "19pt";
		span_list[i].style.color = "red";
		title_list[i].insertBefore(span_list[i], title_list[i].firstChild);
		changeList(span_list[i]);
	}

}
/* Creates an event handler to capture an 'onclick' event, which
 * can occur on the appended SPAN element.
 *
 * Input(s): the SPAN object is passed from changeList()
 *
 * Error(s): object passed is not a SPAN element, checks child
 *            or next sibling(x2) is list element 
 */
function handleClick(event){
	var node_obj = event.target;
	changeList(node_obj);
}
/*Creates a clickHandler object with a handleEvent method,
 *this satisfies the DOM2 event model
 *
 *Input(s): none
 *
 *Error(s): none
 */
function clickHandler(){
	this.handleEvent = handleClick;
}
/* Creates an event handler to capture an 'onclick' event, which
 * can occur on the appended SPAN element.
 *
 * Input(s): the SPAN object is passed from changeList()
 *
 * Error(s): 
 *            
 */
function addHandler(node_obj){
	if(node_obj.addEventListener)
		node_obj.addEventListener("click",new clickHandler(),false);
	else
		node_obj.onclick = IEChangeList;
}
/*Sends the object to the changeList due to IE conficts with with the W3C 
 *   DOM2 event handler.
 *
 *Input(s): none
 *
 *Error(s):none
 */
function IEChangeList(){
	changeList(this);
}
/*Changes the attributes of a parent to a ol/ul list to either collapse or
 *      open the nested list.
 *
 *Input(s): the newly created span object is passed
 *
 *Error(s): method will change attribute in IE/Mozilla
 */
function changeList(node_obj){
	var close="close";
	var open="open";
	
	title = node_obj.nextSibling.nextSibling;


	//checks the span element's text for the minus sign
	if(node_obj.firstChild.nodeValue == "- "){
	 	title.setAttribute("class",close);
	 	title.style.display="none";
		node_obj.firstChild.data="+ ";
	}
	else{
		title.setAttribute("class",open);
		title.style.display="block";
		node_obj.firstChild.data="- ";
	}
}
