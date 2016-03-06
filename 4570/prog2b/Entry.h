#include <iostream>
#include <string>

#include "value.h"

using namespace std;

/********************************************
 * the main entry class 											
 *******************************************/
class Entry
{
  public:
	Entry() {;}
	enum EntryType
	{
		variable, 
		procedure, 
		type, 
		program,
		parameter,
		unknown
	};
	char *name;
	virtual EntryType getType()=0;

	virtual char* toString()
	{
		return "Entry";
	};

  private:

};

/********************************************
 * the type class											
 *******************************************/
class type: public Entry
{
	public:
		type(int tp) {ident_type=tp;}
		
		int ident_type;

		int getIdentType(){ return ident_type; }
		EntryType getType(){ return Entry::type; }
};
/********************************************
 * the variable class											
 *******************************************/
class variable: public Entry
{
	public:
		variable(int tp) {type=tp;}
		char* name;
		int type;
		char* toString(){ return "variable"; }
		EntryType getType(){ return Entry::variable; }
};
/********************************************
 * the program class 											
 *******************************************/
class program: public Entry
{
	public:
		program(char* program_name) {name=program_name;}
		char* name;
		EntryType getType(){ return Entry::program; }
};
/********************************************
 * the class parameter 					
 *******************************************/
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
		EntryType getType(){ return Entry::parameter; }
};
/********************************************
 * the class procedure											
 *******************************************/
class procedure: public Entry
{
	public:
		procedure(){;}
		procedure(int p_count, int convention)
		{
			param_no=p_count;
			ppc = convention;
		}

		int param_no;
		int ppc;

		vector<Param*>* param_vector;
		EntryType getType(){ return Entry::procedure; }
};

class unknown: public Entry
{
	public:
		unknown(){;}
		int tp;
		EntryType getType(){ return Entry::unknown; }
};
	//int kind;
	//int tp;
	//int ppc;//0-by value, 1-by ref
	//int no_param;
	//int *param_type-->vector
	//int *param_ppc-->vector
