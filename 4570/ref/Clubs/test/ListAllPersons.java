//
// A test program to list all persons
//




import java.util.*;

import model.ctrl.*;
import model.entity.*;
import except.*;


public class ListAllPersons
{
  public static void main( String args[] )
  {
    Vector rv = null;
    Person p  = null;

    try {

      rv = CtrlFindAllPersons.findAllPersons();


      System.out.println( "Existing Persons:" );
      System.out.println( "-----------------" );

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
