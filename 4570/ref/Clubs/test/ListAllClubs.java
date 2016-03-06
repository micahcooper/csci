//
// A test program to list all clubs
//




import java.util.*;

import model.ctrl.*;
import model.entity.*;
import except.*;


public class ListAllClubs
{
  public static void main( String args[] )
  {
    Vector rv = null;
    Club   c  = null;

    // create and write to database a few Person objects
    //
    try {

      rv = CtrlFindAllClubs.findAllClubs();


      System.out.println( "Existing Clubs:" );
      System.out.println( "---------------" );

      for( int i = 0; i < rv.size(); i++ ) {
	c = (Club) rv.get( i );
	System.out.println( c.get_id() + "\t" + c.get_Name() + "\t" + c.get_Address() + "\t" + c.get_Established() );

      }

    }
    catch ( ClubsException ce ) {
      System.err.println( ce );
      ce.printStackTrace();
    }
  }  
}
