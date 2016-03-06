// Gnu Emacs C++ mode:  -*- Java -*-
//
// Interface:	Club
//
// K.J. Kochut
//
//
//

package model.entity;


import java.util.*;


public interface Club

  extends Entity 

{

  // operations
  
  // Readers
  //  
  public String		get_Name();
  public String		get_Address();
  public Date		get_Established();
  
  // Writers
  //
  public void		set_Name( String name );
  public void		set_Address( String addr );
  public void		set_Established( Date estab);

};
