#include <iostream>
#include <string>

#include "symtab.h"

using namespace std;

map<char*, Entry*>* temp;
/****************************************************
 * CONSTRUCTOR													
 ***************************************************/
symtab::symtab()
{
	//cout << "Symbol table created..." <<endl;
	//currentMapMap = new map<char*, Entry*>();	
	scope_level=0;
	open_scope();
	installPredefinedIdents();
}
/****************************************************
 * Adds a new entry into the map
 ***************************************************/
void symtab::install(char* key, Entry* value)
{
	map<char*, Entry*>::iterator it;

	//cout <<"Installing..."<<key<<endl;

	for( it = currentMap->begin(); it != currentMap->end(); it++ )
	{
		if( strcmp( (*it).first, key ) == 0 )
			cout <<key << " identifier already exists"<<endl;
	}
	currentMap->insert (pair<char*, Entry*>(key, value));

	//it = currentMapMap->find(key);
	//cout <<"Install: " <<(*it).second->toString() <<endl;
}

/****************************************************
 * Opens a new scope.												
 ***************************************************/
void symtab::open_scope()
{
	currentMap = new map<char*, Entry*>();
	theStack.push_back(currentMap);
	//cout <<"open_scope()" <<endl;
}

/****************************************************
 * Closes the newest scope level.													
 ***************************************************/
void symtab::close_scope()
{
	//cout <<"close_scope() and ";
	//obtain the map, and get the first entry
	//cout <<"Removed: " << (*(theStack.back()->begin())).second->toString() <<endl;
	theStack.pop_back();
}

/****************************************************
 * Searches for an existing identifier.													
 ***************************************************/
Entry::EntryType symtab::lookup( char* key )
{
	map<char*, Entry*>::iterator map_it;
	vector< map<char*, Entry*>* >::iterator stack_it;

	scope_level = theStack.size();

	for( stack_it = theStack.begin(); stack_it != theStack.end(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
			if( strcmp( (*map_it).first, key ) == 0 )
				return (*map_it).second->getType();
			
		scope_level--;
	}
}
/****************************************************
 * Adds parameters to a procedure signature.													
 ***************************************************/
void symtab::update_proc( procedure* last_proc, Param* param )
{
	last_proc->param_vector->push_back( param );
}
/****************************************************
 * Returns the type of an indentifier.													
 ***************************************************/
int symtab::lookupIdentType( char* key )
{
	map<char*, Entry*>::iterator map_it;
	vector< map<char*, Entry*>* >::iterator stack_it;

	//scope_level = theStack.size();

	//temp = theStack.back();
	for( stack_it = theStack.begin(); stack_it != theStack.end(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
			if( strcmp( (*map_it).first, key ) == 0 )
				return (*map_it).second->type;
	}

}

/****************************************************
 * Returns the binding of an indentifier.	
 ***************************************************/
Entry* symtab::lookupBinding( char* key )
{
	map<char*, Entry*>::iterator map_it;
	vector< map<char*, Entry*>* >::iterator stack_it;

	for( stack_it = theStack.begin(); stack_it != theStack.end(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
			if( strcmp( (*map_it).first, key ) == 0 )
				return (*map_it).second;
	}
	//cout <<"did not find binding"<<endl;
	return new unknown(); 

}
/****************************************************
 * looks up the type of a identifier
 ***************************************************/
type* symtab::lookupType(char* key)
{
	map<char*, Entry*>::iterator map_it;
	vector< map<char*, Entry*>* >::iterator stack_it;

	for( stack_it = theStack.begin(); stack_it != theStack.end(); stack_it++ )
	{
		currentMap = *stack_it;

		for( map_it = currentMap->begin(); map_it != currentMap->end(); map_it++ )
			if( strcmp( (*map_it).first, key ) == 0 )
				return (type*)(*map_it).second;
	}
}
/****************************************************
 * create the predefined values in micro-pascal
 ***************************************************/
void symtab::installPredefinedIdents()
{
	install( "integer", new type(TYPE_INT) );
	install( "real", new type(TYPE_FLT) );
	install( "write", new procedure(1, PPC_ALL_VAL) );
	install( "writeln", new procedure(0, PPC_NONE) );
	install( "readln", new procedure(1, PPC_ALL_REF) );
}
