//
// An application program to retrieve all Club objects
//
// This program activates the control class ctrl_FindAllClubs
// directly
//


#include <iostream.h>
#include <algorithm>

#include "ctrl_FindAllClubs.h"


int
main()
{
  vector<Club*>      sv;
  Club 		    *c;
  int i;

  try {

    sv = ctrl_FindAllClubs::FindAllClubs();
    sort( sv.begin(), sv.end(), CompClubsPtr() );

    for( i = 0; i < sv.size(); i++ ) {

      c = (Club*) sv[ i ];
      cout << "Club: " << *c << endl;

    }

  }
  catch( ClubsException ce ) {

    cerr << "Exception: " << ce.get_Msg() << endl;

    return 0;

  }

  return 0;

}
