#include <fstream.h>
#include <stdlib.h>
#include <string.h>
#include <strstream.h>
#include <algorithm>
#include "cgipp.h"

#include "ctrl_FindAllPersons.h"
#include "cgi_FindAllPersons.h"
#include "Person.h"
#include "HTMLTemplate.h"

int
cgi_FindAllPersons::FindAllPersons( ostream &os )
{
  cgidata 	       data;
  vector<Person*>      sv;
  HTMLTemplate         templ( "/web/kochut/public_html/FindAllPersons-Result.html" );
  Person	      *p;
  char		      *subs[1][2];
  strstream	       persons;
  int i;

  try {

    sv = ctrl_FindAllPersons::FindAllPersons();
    sort( sv.begin(), sv.end(), CompPersonPtr() );

    for( i = 0; i < sv.size(); i++ ) {

      p = (Person*) sv[ i ];
      persons << "<li>" << *p << "</li>";

    }

    subs[0][0] = "%PERSONS%";
    if ( persons.str() == NULL )
      subs[0][1] = "No persons present in the system";
    else
      subs[0][1] = persons.str();

    templ.Instantiate( cout, subs, 1 );

  }
  catch( ClubsException ce ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindAllPersons-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = ce.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }
  catch( HTMLTemplateException te ) {

    HTMLTemplate         templ( "/web/kochut/public_html/FindAllPersons-Error.html" );

    subs[0][0] = "%REASON%";
    subs[0][1] = te.get_Msg();

    templ.Instantiate( os, subs, 1 );

    return 0;

  }

  return 0;

}
