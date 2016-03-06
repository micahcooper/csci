//
// A test program to join club
//




import java.util.*;

import model.ctrl.*;
import model.entity.*;
import except.*;


public class EnrollMembers
{
  public static void main( String args[] )
  {

    long linkid = 0;

    // create and write to database a few Person objects
    //
    try {

      linkid = CtrlJoinClub.joinClub( 6, 4 );

      linkid = CtrlJoinClub.joinClub( 6, 5 );

      linkid = CtrlJoinClub.joinClub( 7, 5 );

      linkid = CtrlJoinClub.joinClub( 7, 6 );

      linkid = CtrlJoinClub.joinClub( 8, 6 );

      linkid = CtrlJoinClub.joinClub( 9, 6 );

      linkid = CtrlJoinClub.joinClub( 10, 6 );


      System.out.println( "Done." );


    }
    catch ( ClubsException ce ) {
      System.err.println( ce );
      ce.printStackTrace();
    }
  }  
}
