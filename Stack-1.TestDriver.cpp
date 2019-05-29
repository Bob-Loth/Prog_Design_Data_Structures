#include "Stack.h"
#include <assert.h>
#include <iostream>
#include <string> //contained in Stack.h
using namespace std;
int main()
{
  //testing int and string types
  Stack<int> ints;
  Stack<string> strings;
  assert(ints.siz() == 0);
  assert(strings.siz() == 0);
  cout << "successfully created stacks" << endl;
  //pop test
  ints.push(46);
  ints.pop();
  strings.push("48");
  strings.pop();
  assert(ints.siz() == 0);
  assert(strings.siz() == 0);
  cout << "successfully popped stacks" << endl;
  //clear, empty test
  ints.push(46);
  ints.push(46);
  ints.push(46);
  strings.push("48");
  strings.push("48");
  strings.push("48");
  ints.clear();
  strings.clear();
  assert(ints.empty());
  assert(strings.empty());
  cout << "successfully cleared stacks" << endl;
  //push test
  ints.push(46);
  ints.push(47);
  strings.push("48");
  strings.push("49");

  //peek test
  assert(ints.peek() == 47);
  assert(ints.siz() == 2);
  assert(strings.peek() == "49");
  assert(strings.siz() == 2);
  cout << "Successfully pushed values to stacks" << endl;
  //copy tests
  Stack<string> strings2 = strings;
  Stack<int> ints2 = ints;
  assert(ints2.peek() == 47);
  assert(ints2.siz() == 2);
  assert(strings2.peek() == "49");
  assert(strings2.siz() == 2);
  cout << "Successfully copied stack values to newly created stack" << endl;
  //Stack<string> strings2 = strings;
  
  return 0;
}