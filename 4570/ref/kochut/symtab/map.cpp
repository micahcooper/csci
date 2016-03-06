#include <iostream>
#include <string>
#include <map>

using namespace std;

struct less_string
{

  bool operator()(string s1, string s2) const
  {
    return s1.compare(s2) < 0;
  }
};

struct less_int
{

  bool operator()(int i1, int i2) const
  {
    return i1 < i2;
  }
};

int main()
{
  map<string, int, less_string> dig2num;
  map<int, string, less_int>    num2dig;
  int val;
  
  dig2num["zero"] = 0;
  dig2num["one"] = 1;
  dig2num["two"] = 2;
  dig2num["three"] = 3;
  dig2num["four"] = 4;
  dig2num["five"] = 5;
  dig2num["six"] = 6;
  dig2num["seven"] = 7;
  dig2num["eight"] = 8;
  dig2num["nine"] = 9;
  
  num2dig[0] = "zero";
  num2dig[1] = "one";
  num2dig[2] = "two";
  num2dig[3] = "three";
  num2dig[4] = "four";
  num2dig[5] = "five";
  num2dig[6] = "six";
  num2dig[7] = "seven";
  num2dig[8] = "eight";
  num2dig[9] = "nine";
  
  cout << "5 = " << num2dig[5] << endl;

  cout << "five = " << dig2num["five"] << endl;

  cout << "eleven = " << dig2num["eleven"] << endl;

  val = dig2num["five"];

  map<int, string, less_int>::iterator cur  = num2dig.find(val);
  map<int, string, less_int>::iterator prev = cur;
  map<int, string, less_int>::iterator next = cur;

  ++next;
  --prev;

  cout << "Before 'five' is '" << num2dig[(*prev).first] << "'\n";
  cout << "After  'five' is '" << num2dig[(*next).first] << "'\n";
}
