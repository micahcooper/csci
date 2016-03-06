//
// A control class to implement the 'Create person' use case
//
//

package model.ctrl;



import except.*;
import model.entity.*;
import persist.*;


public class CtrlCreatePerson {

  public static long createPerson( String first_name, String last_name, String address,
				   String phone, int age )

    throws ClubsException

  { 
    PersistenceModule 	pm = null;
    Person 		person  = null;
    long   		personid = 0;

    pm = PersistenceModuleFactory.createPersistenceModule();

    person = ModelFactory.createPerson( first_name, last_name, address, phone, age );
    personid = pm.storePerson( person );

    return personid;
  }

};

