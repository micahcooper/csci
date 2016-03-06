//
// A control class to implement the 'List all clubs' use case
//
//


package model.ctrl;



import java.util.*;

import except.*;
import model.entity.*;
import persist.*;


public class CtrlFindAllClubs {

  public static Vector findAllClubs()

    throws ClubsException

  {
    PersistenceModule 	pm = null;
    Vector   		sv  = null;
    Iterator 		cit = null;
    Club     		c = null;

    sv = new Vector();

    pm = PersistenceModuleFactory.createPersistenceModule();

    // retrieve all Club objects
    //
    cit = pm.restoreClubs();

    while( cit.hasNext() ) {

      c = (Club) cit.next();
      sv.add( c );

    }

    return sv;
  }
}
