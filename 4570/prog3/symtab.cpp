#include <iostream>
#include <string>

#include "symtab.h"

using namespace std;

map<const char*, Entry*>* temp;
/****************************************************
 * CONSTRUCTOR													
 ***************************************************/
symtab::symtab()
{
	//cout << "Symbol table created..." <<endl;
	//currentMapMap = new map<char*, Entry*>();	
	//entry_scope_level=1;
	open_scope();
	//installPredefinedIdents();
}
/****************************************************
 * Adds a new entry into the map
 ***************************************************/
int symtab::install(const char* key, Entry* value)
{
	map<const char*, Entry*>::iterator it;
	map<const char*, Entry*>* current_scope;
	int offset = 5;

	current_scope = theStack.back();	
	//cout <<"Installing..."<<key<<" in map size "<<(current_scope)->size()<<endl;

	for( it = (current_scope)->begin(); it != (current_scope)->end(); it++ )
	{
		if( (*it).second->getType() == Entry::variable || (*it).second->getType() == Entry::parameter )
		{
//cout<<"increase offset for "<<key<<", with cause of type="<<(*it).second->getType()<<endl;
			offset++;
		}
		if( strcmp( (*it).first, key ) == 0 )
		{
			cout <<key << " identifier already exists"<<endl;
			return 0;
		}
	}
	(current_scope)->insert(pair<const char*, Entry*>(key, value));
	if( value->getType() == Entry::variable )
	{
		((variable*)value)->offset = offset;
//cout<<key<<" offset="<<offset<<endl;
	}
	if( value->getType() == Entry::parameter )
	{
		((parameter*)value)->offset = offset;
//cout<<key<<" offset="<<offset<<endl;
	}
	return 1;

}

/****************************************************
 * Opens a new scope.												
 ***************************************************/
void symtab::open_scope()
{
	currentMap = new map<const char*, Entry*>();
	theStack.push_back(currentMap);
//cout<<" open_scope() to "<<theStack.size()<<endl;
}

/****************************************************
 * Closes the newest scope level.													
 ***************************************************/
void symtab::close_scope()
{
	//obtain the map, and get the first entry
	theStack.pop_back();
//cout <<"close_scope() to "<<theStack.size()<<endl;
}

/****************************************************
 * Searches for an existing identifier.
 ***************************************************/
Entry::EntryType symtab::lookup(const char* key )
{
	map<const char*, Entry*>::iterator map_it;
	vector< map<const char*, Entry*>* >::reverse_iterator stack_it;


	for( stack_it = theStack.rbegin(); stack_it != theStack.rend(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
			if( strcmp( (*map_it).first, key ) == 0 )
				return (*map_it).second->getType();
			
	}
	return Entry::unknown;
}
/****************************************************
 * Searches for an existing identifier.
 ***************************************************/
int symtab::lookup_level(const char* ident )
{
	map<const char*, Entry*>::iterator map_it;
	vector< map<const char*, Entry*>* >::reverse_iterator stack_it;

	entry_scope_level = theStack.size();

	for( stack_it = theStack.rbegin(); stack_it != theStack.rend(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
			if( strcmp( (*map_it).first, ident ) == 0 )
				return entry_scope_level;
			
		entry_scope_level--;
	}
	return entry_scope_level;
}
/****************************************************
 * Adds parameters to a procedure signature.													
 ***************************************************/
void symtab::update_proc( procedure* last_proc, Param* param )
{
	last_proc->param_vector.push_back( param );
}
/****************************************************
 * Returns the type of an indentifier.
 ***************************************************/
int symtab::lookupIdentType(const char* key )
{
	map<const char*, Entry*>::iterator map_it;
	vector< map<const char*, Entry*>* >::reverse_iterator stack_it;
	Entry* temp;
	//scope_level = theStack.size();

	//temp = theStack.back();
	for( stack_it = theStack.rbegin(); stack_it != theStack.rend(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
			if( strcmp( (*map_it).first, key ) == 0 )
			{
				temp = (*map_it).second;
				if( temp->getType() == Entry::type)
				{
					return ((type*)temp)->getIdentType();
				}
				if( temp->getType() == Entry::variable )
				{
					return ((variable*)temp)->type;
				}
			}
	}

}

/****************************************************
 * Returns the binding of an indentifier.	
 ***************************************************/
Entry* symtab::lookupBinding(const char* key )
{
	map<const char*, Entry*>::iterator map_it;
	vector< map<const char*, Entry*>* >::reverse_iterator stack_it;

//cout<<"looking for..."<<key<<endl;
	for( stack_it = theStack.rbegin(); stack_it != theStack.rend(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
		{
			if( strcmp( (*map_it).first, key ) == 0 )
			{
//cout<<" found="<<(*map_it).first<<" in "<<entry_scope_level<<" of "<<theStack.size()<<endl;
				return (*map_it).second;
			}
		}
//cout<<"increase"<<endl;
	}
	//cout <<"did not find binding"<<endl;
	return new unknown(); 

}
/****************************************************
 * looks up the type of a identifier
 ***************************************************/
type* symtab::lookupType(const char* key)
{
	map<const char*, Entry*>::iterator map_it;
	vector< map<const char*, Entry*>* >::reverse_iterator stack_it;

	for( stack_it = theStack.rbegin(); stack_it != theStack.rend(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
			if( strcmp( (*map_it).first, key ) == 0 )
				return (type*)(*map_it).second;
	}
}
int symtab::get_current_scope()
{
	return theStack.size();
}
/****************************************************
 * create the predefined values in micro-pascal
 ***************************************************/
void symtab::installPredefinedIdents()
{
	install( "integer", new type(TYPE_INT) );
	install( "real", new type(TYPE_FLT) );
	install( "write", new procedure(1, BY_VAL, 1  ));
	install( "writeln", new procedure(0, PPC_NONE,2) );
	install( "readln", new procedure(1, BY_REF,3 ));
}
