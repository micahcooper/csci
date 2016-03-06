// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	ClubImpl
//
// K.J. Kochut
//
//
//

package model.entity.impl;


import java.util.*;
import model.entity.*;


public class ClubImpl

  implements Club

{

  // Entity attributes
  //
  private long 	   p_id;
  private boolean  p_written;

  // Club attributes
  //
  private  String  p_Name;  
  private  String  p_Address;
  private  Date    p_Established;


  // Constructors
  
  // these two will be used to create a new object
  //
  public ClubImpl()	{ // required to create an empty "shell" object
    p_id = 0;
    p_written = false;
    p_Name = "Unknown";
    p_Address = "Unknown";
    p_Established = new Date(0);
  }

  // when creating a new Club object
  //
  public ClubImpl( String name, String addr, Date estab ) {
    p_id = 0;
    p_written = false;
    p_Name = name;
    p_Address = addr;
    p_Established = estab;
  }
  
  // when retrieving from a data store -- it has dbid -- the db identifier
  //
  public ClubImpl( long dbid, String name, String addr, Date estab ) {
    p_id = dbid;
    p_written = true;
    p_Name = name;
    p_Address = addr;
    p_Established = estab;
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

  
  // Club methods

  // Readers
  //
  public String		get_Name() { return p_Name; }
  public String		get_Address() { return p_Address; }
  public Date		get_Established() { return p_Established; }
  
  // Writers
  //
  public void	set_Name( String name ) { p_Name = name; }
  public void	set_Address( String addr ) { p_Address = addr; }
  public void	set_Established( Date estab) { p_Established = estab; }

};
