#include "Stack.h"
#include <assert.h>
using namespace std;
int main()
{
  //testing int and string types
  Stack<int> ints;
  Stack<string> strings;
  assert(ints.size() == 10);
  assert(strings.size() == 10);

  //pop test
  ints.pop();
  strings.pop();
  assert(ints.size() == 9);
  assert(strings.size() == 9);

  //clear, empty test
  ints.clear();
  strings.clear();
  assert(ints.empty());
  assert(strings.empty());

  //push test
  ints.push(46);
  ints.push(47);
  strings.push("48");
  strings.push("49");

  //peek test
  assert(ints.peek() == 47);
  assert(ints.size() == 2);
  assert(strings.peek() == "49");
  assert(strings.size() == 2);

  //copy tests
  Stack<string> strings2 = strings;
  Stack<int> ints2 = ints;
  assert(ints2.peek() == 47);
  assert(ints2.size() == 2);
  assert(strings2.peek() == "49");
  assert(strings2.size() == 2);
  //Stack<string> strings2 = strings;
  return 0;
}