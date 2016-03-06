// Gnu Emacs C++ mode:  -*- Java -*-
//
// Interface:	PersistenceModule.java
//
// K.J. Kochut
//
//
//

package persist;


import java.util.*;
import java.sql.*;
import model.entity.*;
import except.*;

public interface PersistenceModule {

  public Club 		restoreClub( long id ) throws ClubsException;
  public Club 		restoreClub( String name ) throws ClubsException;
  public Iterator 	restoreClubs() throws ClubsException;
  public long		storeClub( Club c ) throws ClubsException;

  public Person		restorePerson( long id ) throws ClubsException;
  public Person		restorePerson( String fname, String lname ) throws ClubsException;
  public Iterator 	restorePersons() throws ClubsException;
  public long		storePerson( Person p ) throws ClubsException;

  public IsMemberOf	restoreIsMemberOf( long id ) throws ClubsException;
  public Iterator 	restoreIsMemberOfs( Person p ) throws ClubsException;
  public Iterator 	restoreIsMemberOfs( Club c ) throws ClubsException;
  public long		storeIsMemberOf( IsMemberOf i ) throws ClubsException;

};
