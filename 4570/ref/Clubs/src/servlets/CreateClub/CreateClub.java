// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	CreateClub
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


// Servlet class CreateClub
//
// doPost starts the execution of the Create Club Use Case
//
//   parameters:
//
//	club_name    string
//	club_address string
//
public class CreateClub

  extends HttpServlet 

{
  static  String         templateDir = "WEB-INF/templates";
  static  String         resultTemplateName = "CreateClub-Result.ftl";

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
    String	   club_name = null;
    String	   club_addr = null;
    long	   club_id = 0;


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
    club_addr = req.getParameter( "club_address" );

    if( club_name == null || club_addr == null ) {
      ClubsError.error( cfg, toClient, "Unspecified club name or club address" );
      return;
    }

    try {
      club_id = CtrlCreateClub.createClub( club_name, club_addr );
    } 
    catch ( Exception e ) {
      ClubsError.error( cfg, toClient, e );
      return;
    }
    
    // Setup the data-model
    //
    Map root = new HashMap();

    // Build the data-model
    //
    root.put( "club_name", club_name );
    root.put( "club_id", new Long( club_id ) );

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

