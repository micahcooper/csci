#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include "cgipp.h"

#include "cgi_CreateClub.h"
#include "ctrl_CreateClub.h"
#include "HTMLTemplate.h"




int
cgi_CreateClub::CreateClub( ostream &os, char *name, char *addr )
{
  cgidata 	     data;
  HTMLTemplate       templ( "/web/kochut/public_html/CreateClub-Result.html" );
  char		    *subs[1][2];
  int i;

  try {

    ctrl_CreateClub::CreateClub( name, addr );

    subs[0][0] = "%CLUB%";
    subs[0][1] = name;

    templ.Instantiate( os, subs, 1 );

  }
  catch( ClubsException ce ) {

    HTMLTemplate         templ( "/web/kochut/public_html/CreateClub-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = ce.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  catch( HTMLTemplateException te ) {

    HTMLTemplate         templ( "/web/kochut/public_html/CreateClub-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = te.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }

  return 0;

}
