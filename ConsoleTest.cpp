// Programmer: Bob Loth
// Programmer's ID: 1684749
#include <iostream>
#include <string>
using namespace std;


int main()
{
  // programmer's identification
  cout << "Programmer: Bob Loth\n";
  cout << "Programmer's ID: 1684749\n";
  cout << "File: " << __FILE__ << endl;

  int x = 45;
  int y = 37;
  int userSum = -999;
  string buf;

  cout << "What is " << x << " + " << y << "?" << endl;
  cin >> buf;
  cin.ignore();
  userSum = atoi(buf.c_str());
  
  if (userSum == (x + y))
  {
    cout << "Correct!";
  }
  else
  {
    cout << "Incorrect...";
  }
  
}

