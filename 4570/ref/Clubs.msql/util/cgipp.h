// cgipp is designed by Jason Morris and protected by copyright.

#if !defined(H_CGIPP_H)
#define H_CGIPP_H

class varlist {
public:
	varlist(); // Constructor
	~varlist(); // Destructor
	char *getvalue(); // Get the value
	char *getname(); // Get the name
	varlist *getnext(); // Get pointer to next
	void setvalue(char *newvalue); // Set the value
	void setname(char *newname); // Set the name
	void setnext(varlist *newnext); // Set the pointer next
private:
	char *name; // Name of this variable
	char *value; // Value of this variable
	varlist *next; // Pointer to next variable in list
};

class cgidata {
public:
	cgidata(); // Obtain PUT and GET CGI information
	~cgidata(); // Delete the varlist
	int count(); // Number of variables in the list
	int count(char *varname); // Number of variables in list with name varname
	char *name(int index); // Name of variable X
	char *value(int index); // Value of variable X
	char *value(char *varname, int index); // Value of Xth variable with name varname
private:
	varlist *variables; // List of variables
  void parse(char *input, int booldecode); // put a query string into a varlist
	char *urldecode(char *in); // Remove URLEncoding
	char hextochar(char *in); // Change hexcoding unurlencode
};

#endif // H_CGIPP_H
