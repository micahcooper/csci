//
// A control class to implement the 'Create club' use case
//
//

package model.ctrl;

import java.util.*;

import except.*;
import model.entity.*;
import persist.*;


public class CtrlCreateClub {

  public static long createClub( String club_name, String club_addr )

    throws ClubsException

  { 
    PersistenceModule 	pm = null;
    Date 		estab = null;
    Club 		club  = null;
    long		clubid = 0;
    Iterator 		cit = null;


    pm = PersistenceModuleFactory.createPersistenceModule();

    // retrieve all Club objects
    //
    cit = pm.restoreClubs();

    while( cit.hasNext() ) {

      club = (Club) cit.next();
      if( club.get_Name().equalsIgnoreCase( club_name ) )
	throw new ClubsException( "A club with this name already exists: " + club_name );

    }

    estab = new Date();		// mark it as created now
    club = ModelFactory.createClub( club_name, club_addr, estab );
    clubid = pm.storeClub( club );

    return clubid;
  }

};

