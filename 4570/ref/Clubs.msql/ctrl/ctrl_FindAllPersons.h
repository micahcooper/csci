//
// A control class to implement the 'Find all persons' use case
//
//

#include <vector>
#include "Person.h"
#include "ClubsException.h"



class ctrl_FindAllPersons {

public:

  static vector<Person*> FindAllPersons()
    throw (ClubsException);

};

