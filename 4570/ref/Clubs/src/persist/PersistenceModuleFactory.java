// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	PersistenceModuleFactory
//
// K.J. Kochut
//
//
//

package persist;


import except.*;
import persist.impl.*;


public class PersistenceModuleFactory {

  private static final String url = "jdbc:mysql://localhost:3306/demo";
  private static final String user = "demo";
  private static final String pass = "demo";

  public static PersistenceModule createPersistenceModule() 
    	throws ClubsException
    { return new PersistenceModuleImpl( url, user, pass ); }

};
