#include "DynamicArray.cpp"
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
  assert(myCharList.capacity() == 2);
  myCharList.capacity(48);
  assert(myCharList.capacity() == 48);
  myCharList.capacity(0);
  assert(myCharList.capacity() == 0);
  
  cout << "\nSquare bracket operator setter and getter test\n";
  DynamicArray<double> myDoubleList;
  myDoubleList[0] = 4.5;
  assert(myDoubleList[0] == 4.5);
  myDoubleList[1] = -5.67;
  assert(myDoubleList.capacity() == 2); //2x the highest index
  myDoubleList[64] = 6;
  assert(myDoubleList.capacity() == 128);
  assert(myDoubleList[64] == 6);
  
  system("pause");
  return 0;
}