// Gnu Emacs C++ mode:  -*- Java -*-
//
// Interface:	Person
//
// K.J. Kochut
//
//
//


package model.entity;


// Interface to Person representing the Person class from the UML object model
//
public interface Person

  extends Entity 

{
  // operations
  
  // Readers
  //
  public String	get_FirstName();
  public String	get_LastName();
  public String	get_Address();
  public String	get_Phone();
  public int	get_Age();
  
  // Writers
  //  
  public void	set_FirstName( String fn );
  public void	set_LastName( String ln );
  public void	set_Address( String addr );
  public void	set_Phone( String phone );
  public void	set_Age( int age );
  
};
