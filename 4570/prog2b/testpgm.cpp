#include <iostream>
#include <string>

#include "symtab.h"
/* end-header */

using namespace std;

int main()
{
	cout <<"***********************************************"<<endl;
	symtab test;
	char* key ="one";
	Entry* value = new Entry();

	value->name="one";
	test.install( key, new Entry() );
	test.open_scope();
	test.install("two", new variable(0) );
	test.lookup("two");
	test.close_scope();
	test.close_scope();
	cout <<"scope_level: "<<test.scope_level;
	cout <<"***********************************************"<<endl;
}
