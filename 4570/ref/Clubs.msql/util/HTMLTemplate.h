// GNU Emacs C++ mode: -*- C++ -*-
//
// a simple HTML template class
//

#ifndef HTMLTEMPLATE_H
#define HTMLTEMPLATE_H


#include <iostream.h>




const int BufferSize = 65536;



class HTMLTemplateException {

private:
    
  char *p_Msg;

public:

  HTMLTemplateException( const char *m );

  HTMLTemplateException( const char *m1, const char *m2 );

  char *get_Msg() const { return p_Msg; }

};




class HTMLTemplate {

private:

  char *p_TemplateFileName;

  char *a_buffer;
  char *b_buffer;

  char *replace( char *curr_buffer,
		 char *old_patt, char *new_patt );
  
  char *apply( char *in_buffer, 
	       char *subs[][2], int nosubs );

public:

      HTMLTemplate( const char *fn )
  	throw (HTMLTemplateException);

      ~HTMLTemplate();

  int Instantiate( ostream &os, char *sub[][2], int nosub )
  	throw (HTMLTemplateException);

};


#endif
