#ifndef CLUBSEXCEPTION_H
#define CLUBSEXCEPTION_H


class ClubsException {

private:
    
  char *p_Msg;

public:

  ClubsException( const char *m );

  ClubsException( const char *m, int val );

  ClubsException( const char *m, int val1, int val2 );

  ClubsException( const char *m1, const char *m2 );

  ClubsException( const char *m1, const char *m2, const char *m3 );

  char *get_Msg() const { return p_Msg; }

};


#endif
