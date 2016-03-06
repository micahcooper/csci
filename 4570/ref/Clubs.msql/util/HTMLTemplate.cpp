// Gnu Emacs C++ mode:  -*- C++ -*-
//
// Class: Person
//
//	  implementation
//
//
// K.J. Kochut
//
//


#include <fstream.h>
#include <strstream.h>
#include <strings.h>


#include "HTMLTemplate.h"


HTMLTemplateException::HTMLTemplateException( const char *m )
{
  ostrstream msg;
  
  msg << "HTMLTemplateException: " << m;

  p_Msg = strdup( msg.str() );
}

HTMLTemplateException::HTMLTemplateException( const char *m1, const char *m2 )
{
  ostrstream msg;
  
  msg << "HTMLTemplateException: " << m1 << " " << m2;

  p_Msg = strdup( msg.str() );
}



HTMLTemplate::HTMLTemplate( const char *fn )
  	throw (HTMLTemplateException)
{
  p_TemplateFileName = new char[ strlen( fn ) + 1 ];
  strcpy( p_TemplateFileName, fn );

  a_buffer = new char[ BufferSize ];

  if( a_buffer == NULL )
    throw HTMLTemplateException( "Cannot allocate storage for buffers" );

  b_buffer = new char[ BufferSize ];

  if( b_buffer == NULL )
    throw HTMLTemplateException( "Cannot allocate storage for buffers" );

}


HTMLTemplate::~HTMLTemplate()
{
  delete p_TemplateFileName;
  delete a_buffer;
  delete b_buffer;
}

int 
HTMLTemplate::Instantiate( ostream &os, char *subs[][2], int nosubs )
  	throw (HTMLTemplateException)
{
  ifstream   templ;
  char      *in_buffer;
  char      *out_buffer;


  templ.open( p_TemplateFileName );

  if( !templ ) 
    throw HTMLTemplateException( "Cannot open template file:",
				 p_TemplateFileName );

  in_buffer = a_buffer;

  while( templ.getline( in_buffer, BufferSize, '\n' ) ) {

    if ( templ.gcount() >= BufferSize-1 )
      throw HTMLTemplateException( "Line too long in template file:",
				   p_TemplateFileName );
      
    out_buffer = apply( in_buffer, subs, nosubs );
    os << out_buffer << endl;
  }

  return 1;
}

char *
HTMLTemplate::apply( char *in_buffer, char *subs[][2], int nosubs )
{
  char *new_buffer = in_buffer;
  int   i;

  for( i = 0; i < nosubs; i++ )
    new_buffer = replace( new_buffer, subs[i][0], subs[i][1] );

  return new_buffer;
}

char *
HTMLTemplate::replace( char *curr_buffer, char *old_patt, char *new_patt )
{
  char *start = curr_buffer;
  char *stop = curr_buffer;
  int	old_lng = strlen( old_patt );
  int	new_lng = strlen( new_patt );
  char *new_buffer;
  char *out_buffer;

  if ( strstr( stop, old_patt ) == 0 )
    return curr_buffer;

  if ( curr_buffer == a_buffer )
    new_buffer = b_buffer;
  else
    new_buffer = a_buffer;

  new_buffer[0] = '\0';

  out_buffer = new_buffer;

  while( start = strstr( stop, old_patt ) ) {
    strncat( out_buffer, stop, start-stop );
    out_buffer = out_buffer + (start - stop);
    out_buffer[0] = '\0';
    strcat( out_buffer, new_patt );
    out_buffer = out_buffer + new_lng;
    stop = stop + (start - stop) + old_lng;
  }

  strcat( out_buffer, stop );

  return new_buffer;

}

	

