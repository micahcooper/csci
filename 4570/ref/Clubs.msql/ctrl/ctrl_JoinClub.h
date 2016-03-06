//
// A control class to implement the 'Join club' use case
//
//

#include "ClubsException.h"



class ctrl_JoinClub {

public:

  static void JoinClub( const char *person_ssn, const char *club_name )
    throw (ClubsException);

};

