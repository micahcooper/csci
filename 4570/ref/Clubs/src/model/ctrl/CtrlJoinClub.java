//
// A control class to implement the 'Join a club' use case
//
//


package model.ctrl;



import java.util.*;

import except.*;
import model.entity.*;
import persist.*;


public class CtrlJoinClub {

  public static long joinClub( long person_id, long club_id )
    throws ClubsException
  {
    PersistenceModule 	pm = null;
    Person              person = null;
    Club                club = null;

    pm = PersistenceModuleFactory.createPersistenceModule();

    person = pm.restorePerson( person_id );
    club = pm.restoreClub( club_id );

    return joinClub( pm, person, club );

  }

  public static long joinClub( long person_id, String club_name )
    throws ClubsException
  {
    PersistenceModule 	pm = null;
    Person              person = null;
    Club                club = null;

    pm = PersistenceModuleFactory.createPersistenceModule();

    person = pm.restorePerson( person_id );
    club = pm.restoreClub( club_name );

    return joinClub( pm, person, club );

  }

  public static long joinClub( String person_fn, String person_ln, String club_name )
    throws ClubsException
  {
    PersistenceModule 	pm = null;
    Person              person = null;
    Club                club = null;

    pm = PersistenceModuleFactory.createPersistenceModule();

    person = pm.restorePerson( person_fn, person_ln );
    club = pm.restoreClub( club_name );

    return joinClub( pm, person, club );

  }

  private static long joinClub( PersistenceModule pm, Person person, Club club )

    throws ClubsException

  {
    Vector   		sv  = null;
    Iterator 		imoit = null;
    IsMemberOf          imo = null;
    Person 		p = null;
    Date		join = null;
    long		imoid = 0;

    // retrieve all IsMemberOf links for a club
    //
    imoit = pm.restoreIsMemberOfs( club );

    while( imoit.hasNext() ) {

      imo = (IsMemberOf) imoit.next();
      p = imo.get_Person();
      if( p.get_id() == person.get_id() )
	throw new ClubsException( "Already a member of this club" );

    }

    join = new Date();
    imo = ModelFactory.createIsMemberOf( person, club, join );

    imoid = pm.storeIsMemberOf( imo );

    return imoid;
  }
}
