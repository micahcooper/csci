#include <map>
#include <vector>

#include "value.h"
/* end-header */

using namespace std;

class symtab{

  public:
	symtab();
	int current_scope_level;
	int entry_scope_level;

	int lookupIdentType(const char* ident);
	int install(const char *, Entry*);
	int get_current_scope();
	int lookup_level(const char* ident);
	void open_scope();
	void close_scope();
	void update_proc( procedure*, Param* );
	void installPredefinedIdents();
	Entry::EntryType lookup(const char* key );
	Entry* lookupBinding(const char*);
	type* lookupType(const char*);

  private:
	map<const char*, Entry*> * currentMap;
	vector< map<const char*, Entry*>* > theStack;
};
