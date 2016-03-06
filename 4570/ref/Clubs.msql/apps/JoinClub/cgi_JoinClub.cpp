#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include "cgipp.h"

#include "ctrl_JoinClub.h"
#include "ctrl_FindAllPersons.h"
#include "ctrl_FindAllClubs.h"
#include "cgi_JoinClub.h"
#include "Person.h"
#include "Club.h"
#include "HTMLTemplate.h"


int
cgi_JoinClub::JoinClub( ostream &os, char *ssn, char *club )
{
  HTMLTemplate    templ( "/web/kochut/public_html/JoinClub-Result.html" );
  char		 *subs[2][2];

  if ( ssn == NULL || club == NULL ) {

    HTMLTemplate         templ( "/web/kochut/public_html/JoinClub-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = "Insufficient data was specified.";

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  
  try {

    // person with 'ssn' joins 'club'
    //
    ctrl_JoinClub::JoinClub( ssn, club );
      
    subs[0][0] = "%SSN%";
    subs[0][1] = ssn;
    subs[1][0] = "%CLUB%";
    subs[1][1] = club;

    templ.Instantiate( cout, subs, 2 );

  }
  catch( ClubsException ce ) {

    HTMLTemplate         templ( "/web/kochut/public_html/JoinClub-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = ce.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  catch( HTMLTemplateException te ) {

    HTMLTemplate         templ( "/web/kochut/public_html/JoinClub-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = te.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }

  return 1;

}

int
cgi_JoinClub::ListAllPersonsClubs( ostream &os )
{
  vector<Person*>     svp;
  vector<Club*>       svc;
  HTMLTemplate         templ( "/web/kochut/public_html/JoinClub-PersonsClubs.html" );
  Person	      *p;
  Club		      *c;
  char		      *subs[2][2];
  strstream	       persons;
  strstream	       clubs;
  int i;

  try {

    // get persons
    //
    svp = ctrl_FindAllPersons::FindAllPersons();

    for( i = 0; i < svp.size(); i++ ) {

      p = (Person*) svp[ i ];

      persons << "<option value=\"" << p->get_SSN() << "\">"
	<< p->get_LastName() << ", "
	<< p->get_FirstName()
	<< "</option>\n";

    }

    subs[0][0] = "%PERSONS%";
    subs[0][1] = persons.str();

    // get clubs
    //
    svc = ctrl_FindAllClubs::FindAllClubs();

    for( i = 0; i < svc.size(); i++ ) {

      c = (Club*) svc[ i ];
      clubs << "<option>"
	<< c->get_Name() 
	<< "</option>\n";

    }

    subs[1][0] = "%CLUBS%";
    subs[1][1] = clubs.str();

    templ.Instantiate( cout, subs, 2 );

  }
  catch( ClubsException ce ) {

    HTMLTemplate         templ( "/web/kochut/public_html/JoinClub-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = ce.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  catch( HTMLTemplateException te ) {

    HTMLTemplate         templ( "/web/kochut/public_html/JoinClub-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = te.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }

  return 1;

}
