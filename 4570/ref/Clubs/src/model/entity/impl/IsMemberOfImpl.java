// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	IsMemberOfImpl
//
// K.J. Kochut
//
//
//

package model.entity.impl;


import java.util.*;
import model.entity.*;


public class IsMemberOfImpl

  implements IsMemberOf

{

  // Entity attributes
  //
  private long 	   p_id;
  private boolean  p_written;

  // IsMemberOf attributes
  //
  private Person   p_Person;
  private Club     p_Club;
  private Date     p_Joined;


  // Constructors
  
  // these two will be used to create a new object
  //
  public IsMemberOfImpl()  // required to create an empty "shell" object
  { 
    p_id = 0;
    p_written = false;
    p_Person = null;
    p_Club = null;
    p_Joined = new Date(0);
  }

  // when creating a new IsMemberOf object (i.e. a link)
  //
  public IsMemberOfImpl( Person p, Club c, Date j ) 
  { 
    p_id = 0;
    p_written = false;
    p_Person = p;
    p_Club = c;
    p_Joined = j;
  }

  // when retrieving from a data store -- it has dbid -- the db identifier
  //
  public IsMemberOfImpl( long dbid, Person p, Club c, Date j ) 
  { 
    p_id = dbid;
    p_written = true;
    p_Person = p;
    p_Club = c;
    p_Joined = j;
  }

  // Entity methods
  //
  public boolean  get_isProxy()
    { return p_written; }

  public void  set_isProxy() 
    { p_written = true; }

  public long  get_id()
    { return p_id; }

  public void  set_id( long id ) 
    { p_id = id; }


  // IsMemberOf methods

  // Readers
  //
  public Person	get_Person() { return p_Person; }
  public Club	get_Club() { return p_Club; }
  public Date	get_Joined() { return p_Joined; }

  // Writers
  //  
  public void	set_Person( Person p ) { p_Person = p; }
  public void	set_Club( Club c ) { p_Club = c; }
  public void	set_Joined( Date joined ) { p_Joined = joined; }

};


