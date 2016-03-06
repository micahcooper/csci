//
// A control class to implement the 'List all clubs' use case
//
//

#include <vector>
#include "Club.h"
#include "ClubsException.h"



class ctrl_FindAllClubs {

public:

  static vector<Club*> FindAllClubs()
    throw (ClubsException);

};

