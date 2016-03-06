<?php
	//$file=fopen("new.txt","r") or die("Unable");
	if($_FILES["file"]["error"] > 0)
	{
	echo "Error: " . $_FILES["files"]["error"]."<br/>";
	}
	else
	{
	echo "Upload: " . $_FILES["file"]["name"] ."<br/>";
	echo "Type: " . $_FILES["file"]["type"] ."<br/>";
	print "Size: " . ($_FILES["file"]["size"] )." bytes<br/>";
	print "Stored in: " .$_FILES["file"]["tmp_name"];
	}

?>
<html>
	<head>
	</head>

	<body>
	
		<form action="test.php" method="POST" enctype="multipart/form-data">
		<label for="file">FileName:</label>
		<input type="file" name="file" id="file"/>
		<br/>
		<input type="submit" name="submit" value="Submit">
	</body>
</html>
