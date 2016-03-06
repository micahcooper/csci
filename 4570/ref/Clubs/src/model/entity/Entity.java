// Gnu Emacs C++ mode:  -*- Java -*-
//
// Interface:	Entity
//
// K.J. Kochut
//
//
//

package model.entity;



public interface Entity {

  // is this a proxy object, i.e. based on an
  // object already stored in persistent store?
  //
  public boolean  get_isProxy();

  public void     set_isProxy();

  // get this object's persistence (DB) id
  //
  public long  get_id();

  // set this object's persistence (DB) id
  //
  public void  set_id( long id );

};
