//
// A test program to join club by name
//




import java.util.*;

import model.ctrl.*;
import model.entity.*;
import except.*;


public class JoinClubByName
{
  public static void main( String args[] )
  {
    String ClubName1 = "Chess";
    String ClubName2 = "Bridge";
    String ClubName3 = "Tennis";
    String PersonFName1 = "Joe";
    String PersonLName1 = "Doe";
    String PersonFName2 = "Mary";
    String PersonLName2 = "Swift";
    String PersonFName3 = "Robert";
    String PersonLName3 = "Wilson";
    String PersonFName4 = "Julie";
    String PersonLName4 = "Hart";
    String PersonFName5 = "Heather";
    String PersonLName5 = "Brooks";
    long linkid = 0;

    try {

      linkid = CtrlJoinClub.joinClub( PersonFName1, PersonLName1, ClubName1 );

      linkid = CtrlJoinClub.joinClub( PersonFName1, PersonLName1, ClubName2 );

      linkid = CtrlJoinClub.joinClub( PersonFName2, PersonLName2, ClubName2 );

      linkid = CtrlJoinClub.joinClub( PersonFName2, PersonLName2, ClubName3 );

      linkid = CtrlJoinClub.joinClub( PersonFName3, PersonLName3, ClubName3 );

      linkid = CtrlJoinClub.joinClub( PersonFName4, PersonLName4, ClubName3 );

      linkid = CtrlJoinClub.joinClub( PersonFName5, PersonLName5, ClubName3 );

      System.out.println( "Done." );


    }
    catch ( ClubsException ce ) {
      System.err.println( ce );
      ce.printStackTrace();
    }
  }  
}
