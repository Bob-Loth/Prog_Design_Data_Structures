//Programmer's name: Robert Loth
//Programmer's ID: 1684749
#include "DynamicArray.h"

#include <iostream>
#include <iomanip>


using namespace std;
int main() {
  DynamicArray<double> myDynamicArray;
  DynamicArray<bool> hasBeenModified;

  string indexInput;     //atoi filtering of non-integer results
  string valueInput; //same as above
  int currentIndex = 0;
  int modifiedCount = 0; //stores the number of positions in values DynamicArray modified at least once.

  for (int i = 0; i < myDynamicArray.capacity(); ++i)
  {
    //prompt input
	  cout << "Programmer's name: Robert Loth" << endl;
	  cout << "Programmer's ID: 1684749" << endl;
    cout << "Input an index and a value [Q to quit]: ";
    cin >> indexInput;
    if (toupper(indexInput[0]) == 'Q') break;
    cin >> valueInput;
    if (toupper(valueInput[0]) == 'Q') break;

    currentIndex = atoi(indexInput.c_str());
    myDynamicArray[currentIndex] = atof(valueInput.c_str());
    hasBeenModified[currentIndex] = true;
  }

  /*determine the number of positions in the values Array modified at least once.
  Does not increment more than once if value was modified multiple times. */
  for (int i = 0; i < hasBeenModified.capacity(); ++i)
  {
    if (hasBeenModified[i])
    {
      ++modifiedCount;
    }
  }
  /*display the number of unique indexes used, the index location, and the value stored.
  Does not keep history of modifications of specific indices, only final value.
  Does not display indices not modified by the user. */
  cout << endl << "You stored this many values : " << modifiedCount << endl;
  cout << "The index-value pairs are: " << endl;
  cout << "______________________________" << endl;
  for (int i = 0; i < myDynamicArray.capacity(); ++i)
  {
    if (hasBeenModified[i])
    {
      cout << i << "  =>  " << myDynamicArray[i] << endl;
    }
  }
  /*retrieves the value stored in a specific index, index input received
  from user and checked against known filled indices. Returns same
  error message if index is valid but unused, or is invalid.*/
  while (true) {
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> indexInput;
    if (toupper(indexInput[0]) == 'Q') break;
    currentIndex = atoi(indexInput.c_str());
    if (currentIndex < myDynamicArray.capacity() && currentIndex >= 0 && hasBeenModified[currentIndex] == true)
    {
      cout << endl << "Found it -- the value stored at " << currentIndex << " is " << myDynamicArray[currentIndex] << endl;
    }
    else
    {
      cout << endl << "I didn't find it." << endl;
    }
  }
  return 0;
}