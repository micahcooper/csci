#include <map>
#include <vector>

#include "Entry.h"
/* end-header */

using namespace std;

class symtab{

  public:
	symtab();
	void install(char *, Entry*);
	void open_scope();
	void close_scope();
	Entry::EntryType lookup( char* key );
	int scope_level;
	void update_proc( procedure*, Param* );
	int lookupIdentType(char* ident);
	Entry* lookupBinding(char*);
	type* lookupType(char*);
	void installPredefinedIdents();

  private:
	map<char*, Entry*> * currentMap;
	vector< map<char*, Entry*>* > theStack;
};
