//
// A control class to implement the 'Join club' use case
//
//

#include "ClubsException.h"



class cgi_JoinClub {

public:

  static int JoinClub( ostream &os, char *ssn, char *club );

  static int ListAllPersonsClubs( ostream &os );

};

