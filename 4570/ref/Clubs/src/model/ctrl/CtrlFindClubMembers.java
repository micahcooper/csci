//
// A control class to implement the 'List club membership' use case
//
//


package model.ctrl;



import java.util.*;

import except.*;
import model.entity.*;
import persist.*;


public class CtrlFindClubMembers {

  public static Vector findClubMembers( long club_id )
    throws ClubsException
  {
    PersistenceModule 	pm = null;
    Club                club = null;

    pm = PersistenceModuleFactory.createPersistenceModule();

    club = pm.restoreClub( club_id );

    return findClubMembers( club );
  }

  public static Vector findClubMembers( String club_name )
    throws ClubsException
  {
    PersistenceModule 	pm = null;
    Club                club = null;

    pm = PersistenceModuleFactory.createPersistenceModule();

    club = pm.restoreClub( club_name );

    return findClubMembers( club );
  }

  private static Vector findClubMembers( Club c )

    throws ClubsException

  {
    PersistenceModule 	pm = null;
    Vector   		sv  = null;
    Iterator 		imoit = null;
    IsMemberOf          imo = null;
    Person     		p = null;

    sv = new Vector();

    pm = PersistenceModuleFactory.createPersistenceModule();

    // retrieve all IsMemberOf links for a club
    //
    imoit = pm.restoreIsMemberOfs( c );

    while( imoit.hasNext() ) {

      imo = (IsMemberOf) imoit.next();
      p = imo.get_Person();
      sv.add( p );

    }

    return sv;
  }
}
