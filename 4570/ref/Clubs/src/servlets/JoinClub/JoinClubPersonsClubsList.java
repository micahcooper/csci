// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	JoinClubPersonsClubsList
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


// Servlet class JoinClubPersonsClubsList
//
// doGet starts the execution of the extension List All Persons and Clubs Use Case
//
//   parameters:
//
//	none
//
public class JoinClubPersonsClubsList

  extends HttpServlet 

{
  static  String         templateDir = "WEB-INF/templates";
  static  String         resultTemplateName = "JoinClubPersonsClubsList-Result.ftl";

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

  public void doGet( 
		    HttpServletRequest  req, 
		    HttpServletResponse res 
		   )

    throws ServletException, IOException

  {
    Template       resultTemplate = null;
    BufferedWriter toClient = null;
    Vector 	   rv = null;
    LinkedList     clubs = null;
    LinkedList     club = null;
    Club   	   c  = null;
    LinkedList     persons = null;
    LinkedList     person = null;
    Person   	   p  = null;


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
    // No parameters here


    // Setup the data-model
    //
    Map root = new HashMap();

    // Build the data-model
    //
    persons = new LinkedList();

    try {
      rv = CtrlFindAllPersons.findAllPersons();
    } 
    catch( Exception e ) {
      ClubsError.error( cfg, toClient, e );
      return;
    }
    
    root.put( "persons", persons );

    for( int i = 0; i < rv.size(); i++ ) {
      p = (Person) rv.get( i );
      person = new LinkedList();
      person.add( new Long( p.get_id() ) );
      person.add( p.get_FirstName() );
      person.add( p.get_LastName() );
      persons.add( person );
    }

    try {
      rv = CtrlFindAllClubs.findAllClubs();
    } 
    catch( Exception e ) {
      ClubsError.error( cfg, toClient, e );
      return;
    }
    
    clubs = new LinkedList();

    root.put("clubs", clubs);

    for( int i = 0; i < rv.size(); i++ ) {
      c = (Club) rv.get( i );
      clubs.add( c.get_Name() );
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

