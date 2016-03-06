//
// An application program to create a number of objects and
// popluate the database
//


#include <iostream.h>

#include <unistd.h>
#include <stdlib.h>

#include <msql.h>

#include <string>


#include "Person.h"
#include "Club.h"


int
main()
{
  char *SSN1 = "123-45-1001";
  char *SSN2 = "123-45-1002";
  char *SSN3 = "123-45-1003";
  char *SSN4 = "123-45-1004";
  char *SSN5 = "123-45-1005";

  char *Name1 = "Chess";
  char *Name2 = "Bridge";
  char *Name3 = "Tennis";

  Person   *p;
  Club     *c;
  int      handle;

  time_t   today;

  today = time( &today );

  // load the specific configuration file
  //
  if ( msqlLoadConfigFile( "/web/kochut/public_html/msql.conf" ) == -1 ) {
    cerr << "mSQL error: " << msqlErrMsg << endl;
    cerr << "\nProbable cause: SQL server is not running.\n";
    cerr << "\n                or server miscunfiguration in msql.conf.\n";
    cerr << "\nSolution:       Reconfigure/Restart the server\n";
    exit(1);
  }

  // connect to the database server on ajax
  //
  if ( ( handle = msqlConnect( "ajax.cs.uga.edu" ) ) == -1 ) {
    cerr << "mSQL error: " << msqlErrMsg << endl;
    cerr << "\nProbable cause: SQL server is not running.\n";
    cerr << "\nSolution:       Restart the server\n";
    exit(1);
  }

  // open databse clubs
  //
  if ( msqlSelectDB( handle, "clubs" ) == -1 ) {
    cerr << "mSQL error: " << msqlErrMsg << endl;
    cerr << "\nProbable cause: databse clubs does not exist.\n";
    cerr << "\nSolution:       create the database using msqladmin creat clubs\n";
    exit(1);
  }


  // create and write to database a few Person objects
  //
  try {
    p = new Person( SSN1, "Joe", "Doe",
		    "133 Maple St., Big Town, AZ. 87888", 55 );

    p->DBWrite( handle );
  
    p = new Person( SSN2, "Mary", "Swift",
		    "14 Oak Dr., Small Town, TX. 77888", 24 );

    p->DBWrite( handle );

    p = new Person( SSN3, "Robert", "Wilson",
		    "33 Cedar Cr., Middle Town, NV. 81888", 34 );

    p->DBWrite( handle );
    
    p = new Person( SSN4, "Julie", "Hart",
		    "99 Magnolia St., Splash Town, NY. 21888", 29 );

    p->DBWrite( handle );

    p = new Person( SSN5, "Heather", "Brooks",
		    "1 Pine Ave., Boom Town, GA. 30688", 18 );

    p->DBWrite( handle );


    // create and write to database a few Club objects
    //
    // the creation date for each club defaults to today...
    //
    c = new Club( Name1, "33 Leaf St., Blossom, OR. 88888", today );

    c->DBWrite( handle );

    c = new Club( Name2, "734 Pine Straw Dr., Bloom, KY. 48878",  today );

    c->DBWrite( handle );

    c = new Club( Name3, "333 Wide St., Flower, RI. 17345", today );

    c->DBWrite( handle );

  }
  catch ( ClubsException &ce ) {
    cerr << ce.get_Msg() << endl;
    exit(1);
  }

  cout << "Objects have been written to the database.\n";
  cout << "Closing the database.\n";

  // close the database
  //
  msqlClose( handle );

  return 0;
  
}
