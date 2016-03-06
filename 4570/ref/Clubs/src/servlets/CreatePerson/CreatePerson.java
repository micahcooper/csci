// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	CreatePerson
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


// Servlet class CreatePerson
//
// doPost starts the execution of the Create Club Use Case
//
//   parameters:
//
//	first_name	string
//	last_name	string
//	address		string
//	phone		string
//	age		string representing a positive integer
//
public class CreatePerson

  extends HttpServlet 

{
  static  String         templateDir = "WEB-INF/templates";
  static  String         resultTemplateName = "CreatePerson-Result.ftl";

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
    String	   first_name = null;
    String	   last_name = null;
    String	   address = null;
    String	   phone = null;
    String	   age_str = null;
    int		   age = 0;
    long	   person_id = 0;


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
    first_name = req.getParameter( "first_name" );
    last_name = req.getParameter( "last_name" );
    address = req.getParameter( "address" );
    phone = req.getParameter( "phone" );
    age_str = req.getParameter( "age" );

    if( first_name == null ) {
      ClubsError.error( cfg, toClient, "Unspecified first name" );
      return;
    }

    if( last_name == null ) {
      ClubsError.error( cfg, toClient, "Unspecified last name" );
      return;
    }

    if( address == null ) {
      ClubsError.error( cfg, toClient, "Unspecified address" );
      return;
    }

    if( phone == null ) {
      ClubsError.error( cfg, toClient, "Unspecified phone" );
      return;
    }

    if( age_str == null ) {
      ClubsError.error( cfg, toClient, "Unspecified age" );
      return;
    }

    try {
      age = Integer.parseInt( age_str );
    }
    catch( Exception e ) {
      ClubsError.error( cfg, toClient, "Person age should be an integer, but is: " + age_str );
      return;
    }

    if( age <= 0 ) {
      ClubsError.error( cfg, toClient, "Person age should be positive, but is: " + age );
      return;
    }

    try {
      person_id = CtrlCreatePerson.createPerson( first_name, last_name, address, phone, age );
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
    root.put( "first_name", first_name );
    root.put( "last_name", last_name );
    root.put( "person_id", new Long( person_id ) );

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

