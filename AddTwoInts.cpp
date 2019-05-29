// Programmer: Bob Loth
// Programmer's ID: 1684749
#include <iostream>
using namespace std;

int AddTwoInts(const int &int1, const int &int2);
int main()
{
  // programmer's identification
  cout << "Programmer: Bob Loth\n";
  cout << "Programmer's ID: 1684749\n";
  cout << "File: " << __FILE__ << endl;

  int int1 = 4;
  int int2 = 5;
  cout << "The sum of " << int1 << " and " << int2 << " is " << AddTwoInts(int1, int2);
}

int AddTwoInts(const int &int1, const int &int2)
{
  int sum = int1 + int2;
  return sum;
}
