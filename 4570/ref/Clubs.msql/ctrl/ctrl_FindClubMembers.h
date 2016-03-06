//
// A control class to implement the 'Find club members' use case
//
//

#include <vector>
#include "Person.h"
#include "ClubsException.h"



class ctrl_FindClubMembers {

public:

  static vector<Person*> FindClubMembers( const char *club_name )
    throw (ClubsException);

};

