#include <unistd.h>
#include <stdlib.h>

#include <msql.h>

#include "DBObjectIterator.h"

DBObjectIterator::DBObjectIterator( int DBHandle, const char *table )
{
  p_Handle = DBHandle;
  p_Query << "SELECT * FROM " << table << '\0';
  p_Ready = false;
}

DBObjectIterator::DBObjectIterator( m_result *result )
{
  p_Result = result;
  p_Ready = true;
}

DBObjectIterator::~DBObjectIterator()
{
  if ( p_Ready )
    msqlFreeResult( p_Result );
}

bool
DBObjectIterator::Reset()
{
  if ( msqlQuery( p_Handle, p_Query.str() ) == -1 )
    return false;

  p_Result = msqlStoreResult();
  p_Ready = true;

  return true;
}

