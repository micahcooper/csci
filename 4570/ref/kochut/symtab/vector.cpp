#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() 
{
  vector < string > v;
  vector<int>    v1;
  int            i;

  // insert string at the end
  //
  v.push_back( "hi" );
  v.push_back( "there" );
  v.push_back( "you" );
  v.push_back( "guys!" );


  // insert int's at the beginning
  //
  for( i = 0; i < 10; i++ )
    v1.insert( v1.begin(), i );

  // list all strings in v
  //
  for( i = 0; i < v.size(); i++ )
    cout << v[i] << " ";
  cout << endl;

  // list all int's in v1
  //
  for( i = 0; i < v1.size(); i++ )
    cout << v1[i] << " ";
  cout << endl;

}
