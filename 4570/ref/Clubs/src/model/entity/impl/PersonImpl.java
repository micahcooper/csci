// Gnu Emacs C++ mode:  -*- Java -*-
//
// Class:	PersonImpl
//
// K.J. Kochut
//
//
//


package model.entity.impl;


import model.entity.*;


// Implementation of the Person class from the UML object model
//
public class PersonImpl

  implements Person

{
  // Entity attributes
  //
  private long 	   p_id;
  private boolean  p_written;

  // Person attributes
  //
  private String   p_FirstName;
  private String   p_LastName;
  private String   p_Address;
  private String   p_Phone;
  private int	   p_Age;
  
  
  // Constructors
  
  // these two will be used to create a new object
  //
  public PersonImpl()	 // required to create an empty "shell" object
  {
    p_id = 0;
    p_written = false;
    p_FirstName = "Unknown";
    p_LastName = "Unknown";
    p_Address = "Unknown";
    p_Phone = "Unknown";
    p_Age = 0;
  }


  public PersonImpl( 
		    String fn, 
		    String ln,
		    String addr, 
		    String phone, 
		    int age 
		   )
  {
    p_id = 0;
    p_written = false;
    p_FirstName = fn;
    p_LastName = ln;
    p_Address = addr;
    p_Phone = phone;
    p_Age = age;
  }


  // when retrieving from a data store -- it has dbid -- the db identifier
  //
  public PersonImpl( 
		    long dbid, 
		    String fn, 
		    String ln,
		    String addr, 
		    String phone, 
		    int age 
		   )
  {
    p_id = dbid;
    p_written = true;
    p_FirstName = fn;
    p_LastName = ln;
    p_Address = addr;
    p_Phone = phone;
    p_Age = age;
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

 
  // Person methods

  // Readers
  //
  public String	get_FirstName() { return p_FirstName; }
  public String	get_LastName() { return p_LastName; }
  public String	get_Address() { return p_Address; }
  public String	get_Phone() { return p_Phone; }
  public int		get_Age() { return p_Age; }
  
  // Writers
  //
  public void	set_FirstName( String fn ) { p_FirstName = fn; }
  public void	set_LastName( String ln ) { p_LastName = ln; }
  public void	set_Address( String addr ) { p_Address = addr; }
  public void	set_Phone( String phone ) { p_Phone = phone; }
  public void	set_Age( int age ) { p_Age = age; }

};
