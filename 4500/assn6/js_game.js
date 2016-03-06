<script type='test/javascript' src='sarissa.js'></script>
function start(){
    object = new XMLHttpRequest();

    object.onreadystatechange = new_function;
    object.open("GET","http://zion.cs.uga.edu,true","nathan","nathan");
    object.sent(null);
}

function new_function(){
    alert("found again");
}
