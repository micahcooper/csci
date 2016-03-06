//
// A test program to list club membership
//




import java.util.*;

import model.ctrl.*;
import model.entity.*;
import except.*;


public class ListClubMembers
{
  public static void main( String args[] )
  {
    Vector rv = null;
    Person p  = null;
    long   ClubId = 6;
    String ClubName = "Tennis";

    // create and write to database a few Person objects
    //
    try {

      rv = CtrlFindClubMembers.findClubMembers( ClubId );

      System.out.println( "Existing Members of club id: " + ClubId );
      System.out.println( "----------------------------" );


      for( int i = 0; i < rv.size(); i++ ) {

	p = (Person) rv.get( i );

	System.out.println( p.get_id() + "\t" + p.get_FirstName() + "\t" + p.get_LastName() + 
			    "\t" + p.get_Address() + "\t" + p.get_Phone() + "\t" + p.get_Age() );

      }

      rv = CtrlFindClubMembers.findClubMembers( ClubName );

      System.out.println( "\n\nExisting Members of club: " + ClubName );
      System.out.println( "----------------------------" );


      for( int i = 0; i < rv.size(); i++ ) {

	p = (Person) rv.get( i );

	System.out.println( p.get_id() + "\t" + p.get_FirstName() + "\t" + p.get_LastName() + 
			    "\t" + p.get_Address() + "\t" + p.get_Phone() + "\t" + p.get_Age() );

      }

    }
    catch ( ClubsException ce ) {
      System.err.println( ce );
      ce.printStackTrace();
    }
  }  
}
