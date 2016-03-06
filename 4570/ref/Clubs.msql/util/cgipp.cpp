#include "cgipp.h"
#include <stdlib.h>
#include <string.h>
#include <iostream.h>

// VARLIST OBJECT
// ----------------------------------------------
varlist::varlist()
{
  name = strdup("default"); // set default values of data members
  value = NULL;
  next = NULL;
}

varlist::~varlist()
{
  if (name)
    free(name);  // deallocate space for data members, delete next
  if (value)
    free(value); // in list
  if (next)
    delete next;
}

void varlist::setnext(varlist *nextnode)
{
  next = nextnode;  // set next in list
}

void varlist::setvalue(char *newvalue)
{
  value = strdup(newvalue); // set value
}

void varlist::setname(char *newname)
{
  free(name); // remove default name value
  name = strdup(newname); // set name
}

char *varlist::getvalue()
{
  return value; // get value
}

char *varlist::getname()
{
  return name; // get name
}

varlist *varlist::getnext()
{
  return next; // get next in list
}


// CGIDATA OBJECT
// ------------------------------------------------------
cgidata::cgidata() {
  variables = NULL; // used in public functions

  // if the request method is either post or get...
  if (getenv("REQUEST_METHOD") && 
       (!strcmp(getenv("REQUEST_METHOD"), "POST") ||
       !strcmp(getenv("REQUEST_METHOD"), "GET") ) ) {

    // if there is a query string...
    if (getenv("QUERY_STRING") && 
        strlen(getenv("QUERY_STRING")))

      // parse the query string and decode it.
      parse(getenv("QUERY_STRING"), 1);

    // if the request method is post...
    if (getenv("REQUEST_METHOD") && 
        !strcmp(getenv("REQUEST_METHOD"), "POST")) {

      // if there is posted data...
      if (getenv("CONTENT_LENGTH") && atoi(getenv("CONTENT_LENGTH"))) {
        // obtain that data
        char *stdin = new char[atoi(getenv("CONTENT_LENGTH"))];
        cin >> stdin;
        // if the data is encoded, decode it.  Either way, parse it.
        if (getenv("CONTENT_TYPE") && !strcmp(getenv("CONTENT_TYPE"), "application/x-www-form-urlencoded")) // verify this string...
          parse(stdin, 1);
        else
          parse(stdin, 0);
        // remove the post data temporary variable.
        delete stdin;
      }
    }
  }
  else {

    // if there is posted data...
    if (getenv("CONTENT_LENGTH") && atoi(getenv("CONTENT_LENGTH"))) {
      int lng = atoi(getenv("CONTENT_LENGTH") );


      char *stdin = new char[ lng + 1 ];
      cin.read( stdin, lng );
      // if the data is encoded, decode it.  Either way, parse it.
      if (getenv("CONTENT_TYPE") && !strcmp(getenv("CONTENT_TYPE"), "application/x-www-form-urlencoded")) // verify this string...
          parse(stdin, 1);
        else
          parse(stdin, 1);
        // remove the post data temporary variable.
        delete stdin;
    }
  }  
}

void cgidata::parse(char *input, int booldecode) {
  int start = 0;  // indicates beginning of substring
  unsigned int end = 0; // indicates end of substring
  // unsigned to match datatype of strlen
  char *temp; // temporary storage for substrings
  varlist *current = variables; // pointer to variable list
  // if there is a first variable already...
  if (current) {
    // move to the last variable in the list...
    while (current->getnext()) {
      current = current->getnext();
    }
    // and create a new one.
    current->setnext(new varlist);
    current = current->getnext();
  }
  // otherwise, create a new first variable.
  else
    current = variables = new varlist;
  // go through the string character by character
  for (end = 0; end <= strlen(input); end++) {
    // if the current character is a =, &, or NULL...
    if (input[end] == '&' || input[end] == '=' || input[end] == 0) {
      // copy the substring into temp and decode if necessary
      temp = new char[end-start+1];
      strncpy(temp, &input[start], end-start);
      temp[end-start] = 0;
      if (booldecode)
        temp = urldecode(temp);
      switch (input[end]) {
      // if we reached the end of the string...
      case 0:
        // set the current value.
        current->setvalue(temp);
        break;
      // if we reached the end of a variable pair
      case '&':
        // set the current value, and create a new variable.
        current->setvalue(temp);
        current->setnext(new varlist);
        current = current->getnext();
        break;
      // if we reached the end of a variable name
      case '=':
        // if the name is not blank...
        if (temp[0])
          // set the current name
          current->setname(temp);
        break;
      }
      // delete the temporary value, and 
      // reset the beginning of the substring
      delete temp;
      start = end + 1;
    }
  }
}

cgidata::~cgidata() {
  // delete the variables data member
  delete variables;
}

int cgidata::count() {
  int count = 0; // number of variables
  varlist *current = variables;
  // if there are no variables, current == NULL, so count through them.
  while (current) {
    count++;
    current = current->getnext();
  }
  return count;
}

char *cgidata::name(int index) {
  varlist *current = variables; // pointer to variable list
  int i = 0; // count
  // go through all the variables.
  while (current) {
    // if we are on the variable indicated by index...
    if (i==index) {
      // return it's name.
      return current->getname();
    }
    // otherwise, increment i and go to next variable.
    else {
       i++;
      current = current->getnext();
    }
  }
  // if i was never equal to index, return an error.
  return "error";
}

char *cgidata::value(int index) {
  varlist *current = variables; // pointer to variable list
  int i = 0; // count
  // go through all the variables.
  while (current) {
    // if we are on the variable indecated by index...
    if (i==index) {
      // return it's value.
      return current->getvalue();
    }
    // otherwise, increment i and go to next variable.
    else {
      i++;
      current = current->getnext();
    }
  }
  // if i was never equal to index, return an error.
  return "error";
}

int cgidata::count(char *varname) {
  varlist *current = variables; // pointer to variable list
  int i = 0;  // count
  // go through all of the variables...
  while (current) {
    // if varname is the current name, increment i.
    if (!strcmp(current->getname(), varname)) {
      i++;
    }
    current = current->getnext();
  }
  // return the number of variables with the name varname
  return i;
}

char *cgidata::value(char *varname, int index) {
  varlist *current = variables; // pointer to variable list
  int i = 0; // count
  // go through all of the variables.
  while (current) {
    // if the current variable name is the same as varname,
    if (!strcmp(current->getname(), varname)) {
      // and the count is the same as index
      if (i == index) {
        // return the value of the current variable
        return current->getvalue();
      }
      // otherwise, increment the count
      else {
        i++;
      }
    }
    else {
      current = current->getnext();
    }
  }
  // if the count was never equal to the index, return an error.
  return "error";
}

char *cgidata::urldecode(char *string) {
  int length = strlen(string);  // get the length of the string
  int offset = 0; // difference between original and new length
  int i; // count
  // go through each character of the string
  for (i=0;i<length;i++) {
    // for every % that you find, increase the offset by two.
    if (string[i] == '%') offset += 2;
  }
  // create a new string of the corrent length.
  char *result = new char[length-offset+1];
  // create a pointer to that string
  char *current = result;
  // go through each character of the original string
  for (i=0; i<length; i++, current++ ) {
    switch (string[i]) {
    // if the current character is a %, send the string starting from
    // the next character to be decoded from hexadecimal.
    case '%':
      *current = hextochar(&string[i+1]);
      // increment the count to compensate for the values passed over
      i+=2;
      break;
    // if the current character is a +, replace it with a space.
    case '+':
      *current = ' ';
      break;
    // if the current character is anything else, copy it over
    default:
      *current = string[i];
    }
  }
  // set the final character to NULL to make a null terminated string
  *current = 0;
  // return the result.
  return result;
}

char cgidata::hextochar(char *in)
{
  int val=0; // the decimal character value
  int i; // count
  // do this once for each of the first two characters in the string
  for(i=0; i<2;i++) {
    // do a bunch of stuff that translates the hex values into
    // decimal, and then return the cast of the decimal value as
    // a character.
    char ch = in[i];
    switch (ch) {
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        if (i==0)
          val = (16*(int(ch)-48));
        else
          val += (int(ch)-48);
        break;
      default:
        if (i==0)
          val = (16*(int(ch)-55));
        else
          val += (int(ch)-55);
        break;
    }
  }
  return char(val);
}
