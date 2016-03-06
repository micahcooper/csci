//
// A test program to create a number of objects and
// populate the database
//




import java.util.*;

import model.ctrl.*;
import except.*;


public class CreateObjects 
{
  public static void main( String args[] )
  {
    long   p1id  = 0;
    long   p2id  = 0;
    long   p3id  = 0;
    long   p4id  = 0;
    long   p5id  = 0;
    long   c1id  = 0;
    long   c2id  = 0;
    long   c3id  = 0;
    String Name1 = "Chess";
    String Name2 = "Bridge";
    String Name3 = "Tennis";

    // create and write to database a few Person objects
    //
    try {

      // create and write to database a few Person objects
      //
      p1id = CtrlCreatePerson.createPerson( "Joe", "Doe",
					    "133 Maple St., Big Town, AZ. 87888", "333-4456", 55 );

      System.out.println( "New Person id: " + p1id );

      p2id = CtrlCreatePerson.createPerson( "Mary", "Swift",
					    "14 Oak Dr., Small Town, TX. 77888", "444-9876", 24 );

      System.out.println( "New Person id: " + p2id );

      p3id = CtrlCreatePerson.createPerson( "Robert", "Wilson",
					    "33 Cedar Cr., Middle Town, NV. 81888", "567-7788", 34 );

      System.out.println( "New Person id: " + p3id );

      p4id = CtrlCreatePerson.createPerson( "Julie", "Hart",
					    "99 Magnolia St., Splash Town, NY. 21888", "364-7592", 29 );

      System.out.println( "New Person id: " + p4id );

      p5id = CtrlCreatePerson.createPerson( "Heather", "Brooks",
					    "1 Pine Ave., Boom Town, GA. 30688", "339-9923", 18 );

      System.out.println( "New Person id: " + p5id );

      // create and write to database a few Club objects
      //
      c1id = CtrlCreateClub.createClub( Name1, "33 Leaf St., Blossom, OR. 88888" );

      System.out.println( "New Club: name " + Name1 + ";  id: " + c1id );

      c2id = CtrlCreateClub.createClub( Name2, "734 Pine Straw Dr., Bloom, KY. 48878" );

      System.out.println( "New Club: name " + Name2 + ";  id: " + c2id );

      c3id = CtrlCreateClub.createClub( Name3, "333 Wide St., Flower, RI. 17345" );

      System.out.println( "New Club: name " + Name3 + ";  id: " + c3id );

    }
    catch ( ClubsException ce ) {
      System.err.println( ce );
      ce.printStackTrace();
    }

    System.out.println( "Objects have been written to the database." );

  }  
}
