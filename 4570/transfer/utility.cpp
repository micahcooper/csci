#include <stdlib.h>
#include <cstring>

//extern char* filename;
extern int label_no;
int parNo;
//FILE* code = fopen(filename, "w");

char* get_label_name( char* name)
{
	char* temp;
	if( strlen( name ) > 8 )
  	return strncat( temp, name, 7 );
  else
		return name;
}

int getLabel()
{
	return label_no++;
}
