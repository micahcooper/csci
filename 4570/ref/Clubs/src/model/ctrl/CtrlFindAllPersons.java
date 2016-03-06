//
// A control class to implement the 'List all persons' use case
//
//


package model.ctrl;



import java.util.*;

import except.*;
import model.entity.*;
import persist.*;


public class CtrlFindAllPersons {

  public static Vector findAllPersons()

    throws ClubsException

  {
    PersistenceModule 	pm = null;
    Vector   		sv  = null;
    Iterator 		pit = null;
    Person     		p = null;

    sv = new Vector();

    pm = PersistenceModuleFactory.createPersistenceModule();

    // retrieve all Person objects
    //
    pit = pm.restorePersons();

    while( pit.hasNext() ) {

      p = (Person) pit.next();
      sv.add( p );

    }

    return sv;
  }
}
