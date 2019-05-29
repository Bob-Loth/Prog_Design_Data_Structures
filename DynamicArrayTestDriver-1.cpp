//Programmer's name: Robert Loth
//Programmer's ID: Robert Loth

#include "DynamicArray.h"
#include "DynamicArray.h"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;
int main() {

  DynamicArray<int> myIntList;
  cout << myIntList.capacity() << "|size|" << 10 << endl;
  
  // object copy test
  cout << "\nObject copy test \n";
  
  DynamicArray<int> CopyTest = myIntList; // making a copy
  assert(myIntList.capacity() == CopyTest.capacity());
  for (int i = 0; i < myIntList.capacity(); i++)
    assert(myIntList[i] == CopyTest[i]); // uses the setter version for both a and d

  // object assignment test
  cout << "\nObject assignment test \n";
  DynamicArray<int> e; e = myIntList;
  assert(myIntList.capacity() == e.capacity());
  for (int i = 0; i < myIntList.capacity(); i++)
    assert(myIntList[i] == e[i]);
  
  cout << "\nCapacity setter and getter test\n";
  DynamicArray<char> myCharList;
  assert(myCharList.capacity() == 10);
  myCharList.capacity(48);
  assert(myCharList.capacity() == 48);
  myCharList.capacity(0);
  assert(myCharList.capacity() == 0);
  
  cout << "\nSquare bracket operator setter and getter test\n";
  DynamicArray<double> myDoubleList;
  myDoubleList[0] = 4.5;
  assert(myDoubleList[0] == 4.5);
  myDoubleList[1] = -5.67;
  assert(myDoubleList.capacity() == 10); //2x the highest index
  myDoubleList[64] = 6;
  assert(myDoubleList.capacity() == 128);
  assert(myDoubleList[64] == 6);
  
  cout << "\nString Object copy test \n";
  DynamicArray<string> mystringList;
  DynamicArray<string> CopyTestString = mystringList; // making a copy
  assert(mystringList.capacity() == CopyTestString.capacity());
  for (int i = 0; i < mystringList.capacity(); i++)
	  assert(mystringList[i] == CopyTestString[i]); // uses the setter version for both a and d

										   // object assignment test
  cout << "\nString Object assignment test \n";
  DynamicArray<string> j; j = mystringList;
  assert(mystringList.capacity() == j.capacity());
  for (int i = 0; i < mystringList.capacity(); i++)
	  assert(mystringList[i] == j[i]);

  cout << "\nString Capacity setter and getter test\n";
  DynamicArray<string> mystringList2;
  assert(mystringList.capacity() == 10);
  mystringList2.capacity(48);
  assert(mystringList2.capacity() == 48);
  mystringList2.capacity(0);
  assert(mystringList2.capacity() == 0);

  cout << "\nString Square bracket operator setter and getter test\n";
  DynamicArray<string> mystringList3;
  mystringList3[0] = "4.5";
  assert(mystringList3[0] == "4.5");
  mystringList3[1] = "-5.67";
  assert(mystringList3.capacity() == 10); //2x the highest index
  mystringList3[64] = "6";
  assert(mystringList3.capacity() == 128);
  assert(mystringList3[64] == "6");
  cin.ignore();
  return 0;
}