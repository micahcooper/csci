<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%> 
<jsp:useBean id="movieBean" scope="request" class="movies.MoviesHandler" />
<jsp:useBean id="reviewBean" scope="request" class="movies.ReviewsHandler" />
<jsp:useBean id="authBean" scope="session" class="movies.Auth" />
<jsp:setProperty name="movieBean" property="userGenre" />
<jsp:setProperty name="reviewBean" property="movieId" />
<jsp:setProperty name="authBean" property="*" />


<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<link rel="stylesheet" href="http://www.cs.uga.edu/~cooper/4300/assn10/style.css">
        <title>Movie Bonanza</title>
    </head>
    <body>

    <h1>mrcooper's <span>incredible</span> movie reviews</h1>
    
    <table>
	<tr>
<%--  LOG IN/OUT BUTTON  --%>
	    <td>
		<form method="post">
		<c:choose>
		    <c:when test="${authBean.cleared}">
		        <input type="hidden" name="cleared" value="false">
		        <input type='Submit' value="Log Out">
		    </c:when>
		    <c:otherwise>
		        <input type="hidden" name="login" value="true">
		        <input type='Submit' value="Log In">
		    </c:otherwise>
		</c:choose>	
		</form>
<%--  NEW USER BUTTON  --%>
		<c:if test="${authBean.cleared != true}">
		<form method="post">
		    <input type="hidden" name="newuser" value="true">
		    <input type='Submit' value="New User">
		</form>
		</c:if>
	    </td>
	    <td>
	    <c:if test="${authBean.failedLogin}">
		<p>Log in attempt failed, please try again.</p>
	    </c:if>
 	    </td>
	</tr>
<%--  SELECT A GENRE  --%>
	<tr><td class="opt3">Select A Genre</td>
	<td>
	<form method="post">
	    <select name="userGenre" title="Select A Genre" size=3>
	        <option value="Action/Adventure">Action/Adventure</option>
	        <option value="Anime">Anime</option>
	    	<option value="Comedy">Comedy</option>
	        <option value="Documentary">Documentary</option>
	    	<option value="Drama">Drama</option>
	    	<option value="Family Animation">Family animated</option>
	    	<option value="Foreign">Foreign</option>
	    	<option value="Romance">Romance</option>
    	    </select>
	    <input type="Submit" value="Select">
    	</form>
    	</td></tr>
<%--  MEMBER BENEFITS  --%>
        <c:if test="${authBean.cleared}">
	    <tr>
		<td>
		<p>Greetings ${authBean.userName}</p>
		</td>
		<td>
		<p>Please enjoy the member benefits below</p>
		</td>
	    </tr>
	    <tr>
	        <td class="opt5">
		<form method="post">
		    <input type="hidden" name="addmovie" value="true">
		    <input type='Submit' value="Enter a new Movie">
		</form></td>
	        <td>
		<form method="post">
		    <input type="hidden" name="addreview" value="true">
		    <input type='Submit' value="Enter a new Review">
		</form>
	        </td>
	     </tr>
   	</c:if>
    </table>
<%--  END USER MENU TABLE --%>
    <br>

<%--   MOVIE LIST BASED ON GENRE --%>    
    <c:if test="${movieBean.userGenre != null}">
        <table>
	    <th>${movieBean.userGenre} Movies</th>
	    <tr><td>
		<form method="post">
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

<%--    REVIEW LIST FOR A MOVIE   --%>
    <c:if test="${param.movieId != null}">
	<table>
	    <th>User</th><th>Comments</th><th>Date</th>
	    	<c:forEach items="${reviewBean.reviews}" var="review">
		<tr>
		    <td>${review.author}</td>
		    <td>${review.comments}</td>
		    <td>${review.time}</td>
		</tr>
		</c:forEach>
	</table>
    </c:if>

<%--   OPTION TO ADD A MOVIE TO THE MOVIE CATALOG  --%>
    <c:if test="${param.addmovie}">
	<form method="post">
	    Title:<input type="text" name="movieTitle" size=20>
	    <select name="movieGenre">
	        <option value="Action/Adventure">Action/Adventure</option>
	        <option value="Anime">Anime</option>
	        <option value="Documentary">Documentary</option>
	    	<option value="Drama">Drama</option>
	    	<option value="Comedy">Comedy</option>
	    	<option value="Family animated">Family animated</option>
	    	<option value="Foreign">Foreign</option>
	    	<option value="Romance">Romance</option>
	    </select>
	    <input type="submit" value="Enter New Movie">
	</form>
    </c:if>

<%--   FORM TO ADD A NEW REVIEW TO LOCAL REVIEWS  --%>
    <c:if test="${param.addreview}">
	<p>Pick a movie to review from the title list.</p>
	<form method="post">
	    Title:<select name="movie_id">
	    <c:forEach items="${movieBean.movies}" var="movie">
		<option value="${movie.id}">${movie.title}</option>
	    </c:forEach>
	    </select>
	    <br>
	    <textarea name="comments" cols="50" rows="8"></textarea>
	    <br>
	    <input type="Submit" value="Enter new Review">
	</form>

    </c:if>

<%--    FORM TO FOR EXISTING MEMBERS TO LOG IN  --%>
    <c:if test="${param.login}">
	<table>
	    <tr>
		<td class=lguide>User Name:<br>Password:</td>
		<td class=lform><form method="post">
	    	    <input type="text" name="userName" size=20><br>
	    	    <input type="password" name="password" size=20><br>
	  	    <input type="hidden" name="login" value="false">
		    <input type="Submit" value="Log In!">
		</form></td>
	    </tr>
	</table> 
    </c:if>

<%--    FORM FOR NEW USERS TO REGISTER  --%>
    <c:if test="${param.newuser}">
	<table>
	    <tr>
		<td class=lguide>User Name:<br>Password<br>Password</td>
		<td class=lform><form method="post">
	    	    <input type="text" name="userName" size=20><br>
	    	    <input type="password" name="passOne" size=20><br>
	    	    <input type="password" name="passTwo" size=20><br>
	  	    <input type="hidden" name="newuser" value="false">
		    <input type="Submit" value="Create Account">
		</td></form>
	</table>
    </c:if>



    </body>
</html>
