//Programmer's name: Robert Loth
//Programmer's ID: 1684749
#include "SortableArray.h"
#include <iostream>
#include <iomanip>


using namespace std;
int main() {
  SortableArray<double> mySortableArray;
  SortableArray<bool> hasBeenModified;

  string indexInput;     //atoi filtering of non-integer results
  string valueInput; //same as above
  int currentIndex = 0;
  int modifiedCount = 0; //stores the number of positions in values SortableArray modified at least once.

  for (int i = 0; i < mySortableArray.capacity(); ++i)
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
    mySortableArray[currentIndex] = atof(valueInput.c_str());
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
  
  for (int i = 0; i < mySortableArray.capacity(); ++i)
  {
    if (hasBeenModified[i])
    {
      cout << i << "  =>  " << mySortableArray[i] << endl;
    }
  }

  /*Prompt once for how many values to include in the sorting.*/
  cout << "\nPlease enter the fill line to be sorted: ";
  int fillLine;
  cin >> fillLine;
  cin.ignore();
  mySortableArray.qsort(0, fillLine-1);
  /*retrieves the value stored in a specific index, index input received
  from user and checked against known filled indices. Returns same
  error message if index is valid but unused, or is invalid.*/
  cout << "The index-value pairs are: " << endl;
  for (int i = 0; i < mySortableArray.capacity(); ++i) {
	  cout << i << " => " << mySortableArray[i] << endl;
  }
  while (true) {
    cout << "Input an index for me to look up [Q to quit]: ";
    cin >> indexInput;
    if (toupper(indexInput[0]) == 'Q') break;
    currentIndex = atoi(indexInput.c_str());
    if (currentIndex < mySortableArray.capacity() && currentIndex >= 0 && hasBeenModified[currentIndex] == true)
    {
      cout << endl << "Found it -- the value stored at " << currentIndex << " is " << mySortableArray[currentIndex] << endl;
    }
    else
    {
      cout << endl << "I didn't find it." << endl;
    }
  }
  return 0;
}