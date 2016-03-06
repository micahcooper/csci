#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include <algorithm>
#include "cgipp.h"

#include "cgi_FindAllClubs.h"
#include "ctrl_FindAllClubs.h"
#include "Club.h"
#include "HTMLTemplate.h"




int
cgi_FindAllClubs::FindAllClubs( ostream &os )
{
  cgidata 	     data;
  vector<Club*>      sv;
  HTMLTemplate       templ( "/web/kochut/public_html/FindAllClubs-Result.html" );
  Club 		    *c;
  char		    *subs[1][2];
  strstream	     clubs;
  int i;

  try {

    sv = ctrl_FindAllClubs::FindAllClubs();
    sort( sv.begin(), sv.end(), CompClubsPtr() );

    for( i = 0; i < sv.size(); i++ ) {

      c = (Club*) sv[ i ];
      clubs << "<li>" << *c << "</li>";

    }

    subs[0][0] = "%CLUBS%";
    if ( clubs.str() == NULL )
      subs[0][1] = "No clubs have been defined";
    else
      subs[0][1] = clubs.str();

    templ.Instantiate( os, subs, 1 );

  }
  catch( ClubsException ce ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindAllClubs-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = ce.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  catch( HTMLTemplateException te ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindAllClubs-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = te.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }

  return 0;

}
