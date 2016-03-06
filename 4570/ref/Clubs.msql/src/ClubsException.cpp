#include <strstream.h>
#include <string.h>

#include "ClubsException.h"


ClubsException::ClubsException( const char *m )
{
  ostrstream msg;
  
  msg << "ClubsException: " << m << '\0';

  p_Msg = strdup( msg.str() );
}

ClubsException::ClubsException( const char *m, int val )
{
  ostrstream msg;
  
  msg << "ClubsException: " << m << " " << val << '\0';

  p_Msg = strdup( msg.str() );
}

ClubsException::ClubsException( const char *m, int val1, int val2 )
{
  ostrstream msg;
  
  msg << "ClubsException: " << m << " " << val1 << " " << val2 << '\0';

  p_Msg = strdup( msg.str() );
}

ClubsException::ClubsException( const char *m1, const char *m2 )
{
  ostrstream msg;
  
  msg << "ClubsException: " << m1 << " " << m2 << '\0';

  p_Msg = strdup( msg.str() );
}

ClubsException::ClubsException( const char *m1, const char *m2,
			        const char *m3 )
{
  ostrstream msg;
  
  msg << "ClubsException: " << m1 << " " << m2 << " " << m3 << '\0';

  p_Msg = strdup( msg.str() );
}

