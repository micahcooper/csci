<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%> 
<jsp:useBean id="movieBean" scope="session" class="movies.MoviesHandler" />
<jsp:useBean id="reviewHandler" scope="request" class="movies.ReviewsHandler" />
<jsp:setProperty name="movieBean" property="userGenre" value="none"/>
<jsp:setProperty name="reviewBean" property="movieId" value="999"/>


<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<link rel="stylesheet" href="http://www.cs.uga.edu/~cooper/4300/assn10/style.css">
        <title>Movie Bonanza</title>
    </head>
    <body>

    <h1>mrcooper's incredible movie reviews</h1>
    
    <table >
	<tr><td>Select Genre</td>
	<td>
	<form method="post">
	<select name="userGenre">
	    <option value="Action">Action</option>
	    <option value="Drama">Drama</option>
	    <option value="Comedy">Comedy</option>
	    <option value="Foriegn">Foriegn</option>
	    <option value="Romance">Romance</option>
    	</select>
    	    <input type='Submit' value='Retrieve'>
    	</form>
    	</td></tr>
    </table>
    
    <table>
	<th>Movies</th>
    </table>
    </body>
</html>
