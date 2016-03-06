//
// A control class to implement the 'Create club' use case
//
//

#include "ClubsException.h"



class ctrl_CreateClub {

public:

  static void CreateClub( char *club_name, char *club_addr )
    throw (ClubsException);

};

