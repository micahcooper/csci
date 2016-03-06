<%@page contentType="text/html"%>
<%@page pageEncoding="UTF-8"%>
<jsp:useBean id="lookUp" scope="request" class="mrcooper.RSSLookUp" />
<jsp:setProperty name="lookUp" property="searchCriterion" />

<%@taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%> 

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN"
   "http://www.w3.org/TR/html4/loose.dtd">

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=UTF-8">
	<link rel="stylesheet" href="http://www.cs.uga.edu/~cooper/4300/assn9/style.css">
        <title>RSS items Warehouse</title>
    </head>
    <body>

    <h1 class=myTitle>mrcooper's RSS Look Up Bonanza</h1>
    <p class=date><%= new java.util.Date() %></p>
    
    <p class=recommend>Recommended search terms: (JDBC *), </p>
    <form class=search method='post'>
	<input type='text' name='searchCriterion'>
	<input type='Submit' value='GO SEARCH'>
    </form>

    <c:if test="${lookUp.items != null}">
    <table border=1>
	<th>Title</th><th>Story</th><th>Date</th>
	<c:catch var="e">
	<c:forEach items="${lookUp.items}" var="story" >
	    <tr>
		<td>${story.title}</td>
		<td>${story.story}</td>
		<td>${story.date}</td>
	    </tr>
	</c:forEach>
	</c:catch>

	<c:if test="${e!=null}">EXCEPTION:
	<c:out value="${e}" />
	</c:if>
    </table>
    </c:if>
    </body>
</html>
