// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	FindClubMembersClubsList
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


// Servlet class FindClubMembersClubsList
//
// doGet starts the execution of the extension List All Clubs Use Case
//
//   parameters:
//
//	none
//
public class FindClubMembersClubsList

  extends HttpServlet 

{
  static  String         templateDir = "WEB-INF/templates";
  static  String         resultTemplateName = "FindClubMembersClubsList-Result.ftl";

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


    try {
      rv = CtrlFindAllClubs.findAllClubs();
    } 
    catch( Exception e ) {
      ClubsError.error( cfg, toClient, e );
      return;
    }
    
    // Setup the data-model
    //
    Map root = new HashMap();

    // Build the data-model
    //
    clubs = new LinkedList();
    root.put( "clubs", clubs );

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

