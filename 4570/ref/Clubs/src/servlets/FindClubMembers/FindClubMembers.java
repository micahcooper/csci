// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	FindClubMembers
//
// Type:	Servlet
//
// K.J. Kochut
//
//
//


import java.io.*;
import java.util.*;

import javax.servlet.*;
import javax.servlet.http.*;

import freemarker.template.*;

import except.*;
import model.ctrl.*;
import model.entity.*;


// Servlet class FindClubMembers
//
// doPost starts the execution of the List Members of a Club Use Case
//
//   parameters:
//
//	club_name   string
//
public class FindClubMembers

  extends HttpServlet 

{
  static  String         templateDir = "WEB-INF/templates";
  static  String         resultTemplateName = "FindClubMembers-Result.ftl";

  private Configuration  cfg;

  public void init() 
  {
    // Prepare the FreeMarker configuration;
    // - Load templates from the WEB-INF/templates directory of the Web app.
    //
    cfg = new Configuration();
    cfg.setServletContextForTemplateLoading(
					    getServletContext(), 
					    "WEB-INF/templates"
	   				   );
  }

  public void doPost( 
		     HttpServletRequest  req, 
		     HttpServletResponse res 
		    )

    throws ServletException, IOException

  {
    Template       resultTemplate = null;
    BufferedWriter toClient = null;
    Vector 	   rv = null;
    LinkedList     persons = null;
    LinkedList     person = null;
    Person   	   p  = null;
    String   	   club_name  = null;


    // Load templates from the WEB-INF/templates directory of the Web app.
    //
    try {
      resultTemplate = cfg.getTemplate( resultTemplateName );
    } 
    catch (IOException e) {
      throw new ServletException( 
         "Can't load template in: " + templateDir + ": " + e.toString());
    }

    // Prepare the HTTP response:
    // - Use the charset of template for the output
    // - Use text/html MIME-type
    //
    toClient = new BufferedWriter(
         new OutputStreamWriter( res.getOutputStream(), resultTemplate.getEncoding() )
	 			 );

    res.setContentType("text/html; charset=" + resultTemplate.getEncoding());


    // Get the parameters
    //
    club_name = req.getParameter( "club_name" );

    if( club_name == null ) {
      ClubsError.error( cfg, toClient, "Unspecified club name or club address" );
      return;
    }

    try {
      rv = CtrlFindClubMembers.findClubMembers( club_name );
    } 
    catch (Exception e) {
      ClubsError.error( cfg, toClient, e );
      return;
    }
    
    // Setup the data-model
    //
    Map root = new HashMap();

    // Build the data-model
    //
    root.put( "club_name", club_name );
    persons = new LinkedList();
    root.put( "persons", persons );

    for( int i = 0; i < rv.size(); i++ ) {
      p = (Person) rv.get( i );
      person = new LinkedList();
      person.add( new Long( p.get_id() ) );
      person.add( p.get_FirstName() );
      person.add( p.get_LastName() );
      person.add( p.get_Address() );
      person.add( p.get_Phone() );
      person.add( new Integer( p.get_Age() ) );
      persons.add( person );
    }

    // Merge the data-model and the template
    //
    try {
      resultTemplate.process( root, toClient );
      toClient.flush();
    } 
    catch (TemplateException e) {
      throw new ServletException( "Error while processing FreeMarker template", e);
    }

    toClient.close();

  }

}

