<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%> 
<jsp:useBean id="movieBean" scope="request" class="movies.MoviesHandler" />
<jsp:useBean id="reviewBean" scope="request" class="movies.ReviewsHandler" />
<jsp:setProperty name="movieBean" property="userGenre" />
<jsp:setProperty name="reviewBean" property="movieId" />


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
	        <option value="Action/Adventure">Action/Adventure</option>
	        <option value="Anime">Anime</option>
	        <option value="Documentary">Documentary</option>
	    	<option value="Drama">Drama</option>
	    	<option value="Comedy">Comedy</option>
	    	<option value="Family animated">Family animated</option>
	    	<option value="Foriegn">Foriegn</option>
	    	<option value="Romance">Romance</option>
    	    </select>
	    <input type="Submit" value="Retrieve">
    	</form>
    	</td></tr>
    </table>
    
    <c:if test="${movieBean.userGenre != null}">
        <table>
	    <th>${movieBean.userGenre} Movies</th>
	    <tr><td>
		<form>
	        <c:forEach items="${movieBean.movies}" var="movie">
		    <c:if test="${movie.genre == movieBean.userGenre}">
		    <input name="movieId" type="radio" value="${movie.id}">${movie.title}<br>
		    </c:if>
	    	</c:forEach>
		    <input type="Submit" value="Fetch">
		</form>
	    </td></tr>
    	</table>
    </c:if>

    <c:if test="${reviewBean.movieId != -1}">
	<table>
	    <th>User</th><th>Comments</th><th>Date</th>
	    <tr>
	    	<c:forEach items="${reviewBean.reviews}" var="review">
		    <td>${review.author}</td>
		    <td>${review.comments}</td>
		    <td>${review.time}</td>
		</c:forEach>
	    </tr>
	</table>
    </c:if>
    </body>
</html>
