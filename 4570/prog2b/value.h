#define TYPE_BOOL 999
#define TYPE_FLT 1000
#define TYPE_INT 1001
#define BY_VAL 1002
#define BY_REF 1003
#define PPC_ALL_REF 1004
#define PPC_ALL_VAL 1005
#define PPC_NONE 1006

#include <list>

using namespace std;


struct Param { int tp; int ppc; };
struct ExprAttr { int tp; int lval; };

typedef struct{


	union
	{
		char* name;
		list< char* >* list_val;		
		list< Param* >* plist;
		list< ExprAttr* >* elist;
		ExprAttr* eattr;
	} val;


}val;
