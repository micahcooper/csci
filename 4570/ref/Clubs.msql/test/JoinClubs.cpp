//
// An application program to retrieve some Person and CLub objects
// and assign persons to clubs
//


#include <iostream.h>

#include <unistd.h>
#include <stdlib.h>

#include <msql.h>

#include <string>


#include "Person.h"
#include "Club.h"
#include "Membership.h"
#include "ClubsException.h"

int
main()
{
  string SSN1 = "123-45-1001";
  string SSN2 = "123-45-1002";
  string SSN3 = "123-45-1003";
  string SSN4 = "123-45-1004";
  string SSN5 = "123-45-1005";

  string Name1 = "Chess";
  string Name2 = "Bridge";
  string Name3 = "Tennis";

  time_t today;

  Person   	*p;
  Club     	*c;
  Membership 	*m;
  int      	 handle;

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

  // open database 'clubs'
  //
  if ( msqlSelectDB( handle, "clubs" ) == -1 ) {
    cerr << "mSQL error: " << msqlErrMsg << endl;
    cerr << "\nProbable cause: databse clubs does not exist.\n";
    cerr << "\nSolution:       create the database using msqladmin creat clubs\n";
    exit(1);
  }


  // retrieve a Club object
  //
  try {

    c = Club::DBRead( Name1, handle );

    p = Person::DBRead( SSN1, handle );

    m = new Membership( p, c, today );
    m->DBWrite( handle );

    p = Person::DBRead( SSN3, handle );

    m = new Membership( p, c, today );
    m->DBWrite( handle );

    cout << "Added members to club: " << Name1 << endl;


    // retrieve a Club object
    //
    c = Club::DBRead( Name2, handle );

    p = Person::DBRead( SSN2, handle );

    m = new Membership( p, c, today );
    m->DBWrite( handle );

    p = Person::DBRead( SSN3, handle );

    m = new Membership( p, c, today );
    m->DBWrite( handle );

    p = Person::DBRead( SSN5, handle );

    m = new Membership( p, c, today );
    m->DBWrite( handle );

    cout << "Added members to club: " << Name2 << endl;


    // retrieve a Club object
    //
    c = Club::DBRead( Name3, handle );

    p = Person::DBRead( SSN4, handle );

    m = new Membership( p, c, today );
    m->DBWrite( handle );

    p = Person::DBRead( SSN2, handle );

    m = new Membership( p, c, today );
    m->DBWrite( handle );

    p = Person::DBRead( SSN5, handle );

    m = new Membership( p, c, today );
    m->DBWrite( handle );

  }
  catch ( ClubsException &ce ) {
    cerr << ce.get_Msg() << endl;
    exit(1);
  }

  cout << "Added members to club: " << Name3 << endl;


  cout << endl;
  cout << "Club memberships have been written to the database.\n";
  cout << "Closing the database.\n";

  // close the database
  //
  msqlClose( handle );

  return 0;
  
}
