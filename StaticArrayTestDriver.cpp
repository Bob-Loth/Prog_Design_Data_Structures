#include "StaticArray.cpp"
#include <string>
#include <iostream>
#include <cassert>

using namespace std;
int main() {
  StaticArray<int,10> myIntList;
  cout << myIntList.capacity() << "|size|" << 10 << endl;
  assert(myIntList.capacity() == 10);
  for (int i = 0; i < 10; ++i) {
    cout << myIntList[i] << "|value|" << 0 << endl;
    assert(myIntList[i] == 0);
  }

  StaticArray<double, 16> myDoubleList;
  cout << myDoubleList.capacity() << "|size|" << 16 << endl;
  assert(myDoubleList.capacity() == 16);
  for (int i = 0; i < 16; ++i) {
    myDoubleList[i] = 0.9;
    cout << myDoubleList[i] << "|value|" << 0.9 << endl;
    assert(myDoubleList[i] == 0.9);
  }
  
  StaticArray<string, 12> myStringList;
  cout << myStringList.capacity() << "|size|" << 12 << endl;
  assert(myStringList.capacity() == 12);
  for (int i = 0; i < 10; ++i) {
    myStringList[i] = "John Doe";
    cout << myStringList[i] << " |value| John Doe" << endl;
    assert(myStringList[i] == "John Doe");
  }
  system("pause");
  return 0;
}