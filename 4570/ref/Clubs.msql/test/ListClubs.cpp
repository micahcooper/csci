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
#include "MembershipIterator.h"


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

  Person   	 *p;
  Club     	 *c;
  Membership 	 *m;
  MembershipIterator *mit;
  int      	  handle;



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


  // create a Membership object connected to the Membership table
  //


  try {

    // retrieve a Club object
    //
    c = Club::DBRead( Name1, handle );

    cout << "Current members of club: " << Name1 << endl << endl;

    mit = new MembershipIterator( c, handle );
    mit->Reset();
    while ( (m = (Membership*)mit->GetNext()) != NULL )
      cout << "\t" << *(m->get_Person()) << endl;

    cout << endl << endl;

    // retrieve a Club object
    //
    c = Club::DBRead( Name2, handle );

    cout << "Current members of club: " << Name2 << endl << endl;

    mit = new MembershipIterator( c, handle );
    mit->Reset();
    while ( (m = (Membership*)mit->GetNext()) != NULL )
      cout << "\t" << *(m->get_Person()) << endl;

    cout << endl << endl;

    // retrieve a Club object
    //
    c = Club::DBRead( Name3, handle );

    cout << "Current members of club: " << Name3 << endl << endl;

    mit = new MembershipIterator( c, handle );
    mit->Reset();
    while ( (m = (Membership*)mit->GetNext()) != NULL )
      cout << "\t" << *(m->get_Person()) << endl;

    cout << endl << endl;


    // retrieve a Person object
    //
    p = Person::DBRead( SSN2, handle );

    cout << "Current club membership of person: " << SSN2 << endl << endl;

    mit = new MembershipIterator( p, handle );
    mit->Reset();
    while ( (m = (Membership*)mit->GetNext()) != NULL )
      cout << "\t" << *(m->get_Club()) << endl;

    cout << endl << endl;

  }
  catch ( ClubsException &ce ) {
    cerr << ce.get_Msg() << endl;
    exit(1);
  }


  cout << "Club memberships have been listed.\n";
  cout << "Closing the database.\n";

  // close the database
  //
  msqlClose( handle );

  return 0;
  
}
