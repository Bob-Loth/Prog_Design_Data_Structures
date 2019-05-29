//programmer's name: Robert Loth
//programmer's ID: 1684749

#include <iostream> //cin, cout, endl
#include <string>   //use of string objects
#include <iomanip>  //use of toupper to facilitate quit command
#include "Array.cpp"

using namespace std;

int main()
{
  cout << "Programmer's name: Robert Loth" << endl;
  cout << "Programmer's ID: 1684749" << endl;
  cout << "______________________________" << endl;
  
  Array values;          //stores the values input by the user
  Array hasBeenModified; //1 if parallel position in values Array was modified, else 0
  string indexInput;     //atoi filtering of non-integer results
  string valueInput;     //same as above
  int currentIndex = -1;      //receives input filtered by indexInput in for loop 1 to place values in values Array
  
  int modifiedCount = 0; //stores the number of positions in values Array modified at least once.
  
  for (int i = 0; i < values.capacity(); ++i) 
  {
    //prompt input
    cout << "Input an index and a value [Q to quit]: ";
    cin >> indexInput; 
    if (toupper(indexInput[0]) == 'Q') break;
    cin >> valueInput;
    if (toupper(valueInput[0]) == 'Q') break;

    //validation for string input, out of bounds input handled by class
    currentIndex = atoi(indexInput.c_str());
    values[currentIndex] = atoi(valueInput.c_str());
    hasBeenModified[currentIndex] = 1; 
  }

  /*determine the number of positions in the values Array modified at least once.
  Does not increment more than once if value was modified multiple times. */
  for (int i = 0; i < hasBeenModified.capacity(); ++i)
  {
    if (hasBeenModified[i] == 1)
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
  for (int i = 0; i < values.capacity(); ++i)
  {
    if (hasBeenModified[i] == 1)
    {
      cout << i << "  =>  " << values[i] << endl;
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
    if (hasBeenModified[currentIndex] == 1)
    {
      cout << endl << "Found it -- the value stored at " << currentIndex << " is " << values[currentIndex] << endl;
    }
    else
    {
      cout << endl << "I didn't find it." << endl;
    }
  }
  system("pause");
  return 0;
}