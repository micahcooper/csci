// GNU Emacs C++ mode: -*- C++ -*-
//
// Class:	MembershipIterator
//
//		implementation
//
// K.J. Kochut
//
//
//


#include "MembershipIterator.h"
#include "Membership.h"


MembershipIterator::MembershipIterator( Club *club, int DBhandle )
   throw (ClubsException)
      : DBObjectIterator( DBhandle ),
	p_Dir( Left ),
	p_Club( club )
{
  unsigned int  ClubDBid = club->get_DBid();

  if ( ClubDBid == 0 )		// not a written object yet
    throw ClubsException( "The Club object has not been written yet: ",
			  ClubDBid );

  p_Query << "SELECT Person.Id, \
		   Person.SSN, \
 		   Person.FirstName, \
		   Person.LastName, \
		   Person.Address, \
		   Person.Age, \
		   Membership.joined \
            FROM  Person, Membership \
            WHERE Person.Id = Membership.personid and \
		  Membership.clubid = " << ClubDBid << '\0';

}


MembershipIterator::MembershipIterator( Person *person, int DBhandle )
   throw (ClubsException)
      : DBObjectIterator( DBhandle ),
	p_Dir( Right ),
	p_Person( person )
{
  unsigned int  PersonDBid = person->get_DBid();
  m_result 	*result;
  int		no;

  if ( PersonDBid == 0 )		// not a written object yet
    throw ClubsException( "The Person object has not been written yet: ",
			  PersonDBid );

  p_Query << "SELECT Club.Id, \
		   Club.Name, \
		   Club.Address, \
		   Club.Established, \
		   Membership.joined \
            FROM  Club, Membership \
            WHERE Club.Id = Membership.clubid and \
		  Membership.personid = " << PersonDBid << '\0';

}

// Return the next object
//
DBObject *
MembershipIterator::GetNext()
{
  Person        *np;
  Club   	*nc;
  Membership 	*nm;
  struct tm	*UnixDate;
  time_t	UnixTime;
  char		*msqlDate;
  time_t	time;
  
  if ( !p_Ready )		// was the query sent and the result received?
    return NULL;
  
  if ( (p_Row = msqlFetchRow(p_Result)) == NULL ) // no data received back
    return NULL;

  // Now we have the next row (tuple) from database.
  // Create a C++ proxy for the database object.
  //
  if ( p_Dir == Left ) {	// i.e. from Club to Person

    np = new Person( p_Row[0] == NULL ? 0 : atoi( p_Row[0] ), 	// Id
		     p_Row[1] == NULL ? " " : p_Row[1],		// SSN
		     p_Row[2] == NULL ? " " : p_Row[2],		// FirstName
		     p_Row[3] == NULL ? " " : p_Row[3],		// LastName
		     p_Row[4] == NULL ? " " : p_Row[4],		// Address
		     p_Row[5] == NULL ? -1 : atoi( p_Row[5] ) );// Age

    UnixTime = msqlDateToUnixTime( p_Row[6] );
    time = UnixTime;

    nm = new Membership( np, p_Club, time );

    return nm;

  }
  else {

    UnixTime = msqlDateToUnixTime( p_Row[3] );
    time = UnixTime;

    nc = new Club( p_Row[0] == NULL ? 0 : atoi( p_Row[0] ), 	// Id
		   p_Row[1] == NULL ? " " : p_Row[1],		// Name
		   p_Row[2] == NULL ? " " : p_Row[2],		// Address
		   time );					// Established

    UnixTime = msqlDateToUnixTime( p_Row[4] );
    time = UnixTime;

    nm = new Membership( p_Person, nc, time );

    return nm;

  }

}

