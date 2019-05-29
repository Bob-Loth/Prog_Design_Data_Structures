#include "Queue.h"

#include <assert.h>
#include <iostream>
#include <string>


using namespace std;
int main()
{
  cout << "Starting integer queue test: " << endl;
  Queue<int> myq;
  cout << "Push test: " << endl;
  myq.push(50);
  cout << myq.back() << " should be 50" << endl;
  cout << myq.front() << " should be 50" << endl;
  assert(myq.back() == myq.front() && myq.back() == 50);
  

  cout << "\nFront, Back, and Size test: " << endl;
  myq.push(-85);
  myq.push(42);
  cout << myq.back() << " should be 42" << endl;
  cout << myq.front() << " should be 50" << endl;
  cout << "Size of " << myq.size() << " should be Size of 3" << endl;
  assert(myq.back() == 42);
  assert(myq.front() == 50);
  assert(myq.size() == 3);

  cout << "\nEmpty and Clear test: " << endl;
  cout << myq.empty() << " should be 0" << endl;
  assert(!myq.empty());
  myq.clear();
  cout << "Queue has been cleared." << endl;
  cout << myq.empty() << " should be 1" << endl;
  assert(myq.empty());

  cout << "\nPop test: " << endl;
  myq.push(4);
  myq.pop();
  assert(myq.size() == 0);
  cout << "Queue popped correctly." << endl;
  
  myq.pop();
  assert(myq.size() == 0);
  assert(myq.front() == NULL);
  assert(myq.back() == NULL);
  cout << "Queue correctly handled popping at size 0." << endl;

  cout << "Starting string queue test: " << endl;
  Queue<string> myStrings;
  cout << "Push test: " << endl;
  myStrings.push("strings");
  cout << myStrings.back() << " should be strings" << endl;
  cout << myStrings.front() << " should be strings" << endl;
  assert(myStrings.back() == myStrings.front());


  cout << "\nFront, Back, and Size test: " << endl;
  myStrings.push("second");
  myStrings.push("third in line");
  cout << myStrings.back() << " should be third in line" << endl;
  cout << myStrings.front() << " should be strings" << endl;
  cout << "Size of " << myStrings.size() << " should be Size of 3" << endl;
  assert(myStrings.back() == "third in line");
  assert(myStrings.front() == "strings");
  assert(myStrings.size() == 3);

  cout << "\nEmpty and Clear test: " << endl;
  cout << myStrings.empty() << " should be 0" << endl;
  assert(!myStrings.empty());
  myStrings.clear();
  cout << "Queue has been cleared." << endl;
  cout << myStrings.empty() << " should be 1" << endl;
  assert(myStrings.empty());

  cout << "\nPop test: " << endl;
  myStrings.push("POP!");
  myStrings.pop();
  assert(myStrings.size() == 0);
  cout << "Queue popped correctly." << endl;

  myStrings.pop();
  assert(myStrings.size() == 0);
  assert(myStrings.front() == "");
  assert(myStrings.back() == "");
  cout << "Queue correctly handled popping at size 0." << endl;
  system("pause");
  return 0;
}