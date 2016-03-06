/*******************************************************
 * author: Micah Cooper
 * file: Entry.h
 * date:04/29/2008
 *******************************************************/
#ifndef ENTRY_H
#define ENTRY_H

#include <iostream>
#include <list>
#include <vector>

using namespace std;

struct Param { int tp; int ppc; };
struct ExprAttr { int tp; int lval; };

//+++++++++++++++++++++++++++++++++++++++++++++
// this represents the parent class of all entry types 											
//+++++++++++++++++++++++++++++++++++++++++++++
class Entry
{
  public:
	Entry() {;}
	enum EntryType{variable, procedure, type, program, parameter, unknown};

	char *name;

	virtual EntryType getType()=0;
	virtual const char* toString(){ return "Entry"; };
};
//+++++++++++++++++++++++++++++++++++++++++++++
//this class represents the binding of variable
//+++++++++++++++++++++++++++++++++++++++++++++
class variable: public Entry
{
	public:
		variable(int tp) {type=tp;}

		char* name;
		int type;
		int offset;

		EntryType getType(){ return Entry::variable; }
		const char* toString(){ return "variable"; }
};
//+++++++++++++++++++++++++++++++++++++++++++++
// this represent the binding class of a procedure
//+++++++++++++++++++++++++++++++++++++++++++++
class procedure: public Entry
{
	public:
		procedure(){already_defined=0;}
		procedure(int p_no, int pass, int which)
		{
			already_defined = 1;
			proc_id = which;
			param_no=p_no;
			ppc = pass;
			Param* param = new Param();
			param->tp = TYPE_ANY;
			param->ppc = pass;
			param_vector.push_back( param );
		}

		int param_no;// = param_vector.size();
		int ppc;
		int already_defined;
		int unique_id;
		int proc_id;
		char* label_name;
		vector<Param*> param_vector;

		int get_no_of_params()
		{ 
			if( already_defined )
				return param_no;
			else
				return param_vector.size(); 
		}

		EntryType getType(){ return Entry::procedure; }
		const char* toString(){ return "procedure"; }
};
//+++++++++++++++++++++++++++++++++++++++++++++
// this represent the binding class of a type(real/integer)
//+++++++++++++++++++++++++++++++++++++++++++++
class type: public Entry
{
	public:
		type(int tp) 
		{
			//cout<<"installed..."+tp<<endl;
			ident_type=tp;
		}
		
		int ident_type;

		int getIdentType(){ return ident_type; }
		EntryType getType(){ return Entry::type; }
		const char* toString(){ return "type"; }
};
//+++++++++++++++++++++++++++++++++++++++++++++
// this represents the binding class of type program
//+++++++++++++++++++++++++++++++++++++++++++++
class program: public Entry
{
	public:
		program(char* program_name) {name=program_name;}
		char* name;
		EntryType getType(){ return Entry::program; }
		const char* toString(){ return "program"; }
};
//+++++++++++++++++++++++++++++++++++++++++++++
// this class represents the binding of a parameter 					
//+++++++++++++++++++++++++++++++++++++++++++++
class parameter: public Entry
{
	public:
		parameter(int tp, int convention)
		{
			type = tp;
			ppc = convention;
		}

		int type;
		int ppc;
		int offset;

		EntryType getType(){ return Entry::parameter; }
		const char* toString(){ return "parameter"; }
};
//+++++++++++++++++++++++++++++++++++++++++++++
//this is a psuedo class which represents and undefined entry
//+++++++++++++++++++++++++++++++++++++++++++++
class unknown: public Entry
{
	public:
		unknown(){;}
		int tp;
		EntryType getType(){ return Entry::unknown; }
		const char* toString(){ return "unknown"; }
};

#endif
