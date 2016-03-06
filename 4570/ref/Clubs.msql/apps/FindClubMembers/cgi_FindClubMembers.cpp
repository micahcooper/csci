#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include "cgipp.h"

#include "cgi_FindClubMembers.h"
#include "ctrl_FindClubMembers.h"
#include "ctrl_FindAllClubs.h"
#include "Person.h"
#include "Club.h"
#include "HTMLTemplate.h"

int
cgi_FindClubMembers::FindClubMembers( ostream &os, const char *club_name )
{
  cgidata 	     data;
  vector<Person*>    sv;
  HTMLTemplate       templ( "/web/kochut/public_html/FindClubMembers-Result.html" );
  Person	    *p;
  char		    *subs[2][2];
  strstream	     persons;
  int i;

  if ( club_name == NULL || club_name[0] == '\0' ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindClubMembers-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = "Club name unspecified.";

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  
  try {

    sv = ctrl_FindClubMembers::FindClubMembers( club_name );

    for( i = 0; i < sv.size(); i++ ) {

      p = (Person*) sv[ i ];
      persons << "<li>" << *p << "</li>";

    }

    subs[0][0] = "%CLUB%";
    subs[0][1] = (char*) club_name;
    subs[1][0] = "%MEMBERS%";
    if ( persons.str() == NULL )
      subs[1][1] = "No current members";
    else
      subs[1][1] = persons.str();

    templ.Instantiate( cout, subs, 2 );

  }
  catch( ClubsException ce ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindClubMembers-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = ce.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  catch( HTMLTemplateException te ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindClubMembers-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = te.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }

  return 0;

}


int
cgi_FindClubMembers::ListAllClubs( ostream &os )
{
  vector<Club*>        sv;
  HTMLTemplate         templ( "/web/kochut/public_html/FindClubMembers-Clubs.html" );
  Club		      *c;
  char		      *subs[1][2];
  strstream	       clubs;
  int i;

  try {

    // get clubs
    //
    sv = ctrl_FindAllClubs::FindAllClubs();

    for( i = 0; i < sv.size(); i++ ) {

      c = (Club*) sv[ i ];
      clubs << "<option>"
	<< c->get_Name() 
	<< "</option>\n";

    }

    subs[0][0] = "%CLUBS%";
    if ( clubs.str() == NULL )
      subs[0][1] = "No Defined Clubs";
    else
      subs[0][1] = clubs.str();

    templ.Instantiate( cout, subs, 1 );

  }
  catch( ClubsException ce ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindClubMembers-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = ce.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  catch( HTMLTemplateException te ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindClubMembers-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = te.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }

  return 1;

}
