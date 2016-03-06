// Gnu Emacs C++ mode:  -*- Java -*-
//
// Interface:	IsMemberOf
//
// K.J. Kochut
//
//
//

package model.entity;

import java.util.Date;


public interface IsMemberOf

  extends Entity

{

  // operations
  
  // Readers
  //  
  public Person	get_Person();
  public Club	get_Club();
  public Date	get_Joined();

  // Writers
  //
  public void	set_Person( Person p );
  public void	set_Club( Club c );
  public void	set_Joined( Date joined );

};


