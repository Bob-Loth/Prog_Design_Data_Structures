#include "Stack.h"
#include <iostream>

using namespace std;
int main()
{
  Stack<double> calculator;
  
  string input = "error, no input";
  double numericalInput;
  double val1 = 0;
  double val2 = 0;
  while (true)
  {
    Stack<double> copyCalc = calculator;
    cout << "Enter, or Q to exit: " ;
    while (copyCalc.siz() > 0)
    {
      cout << copyCalc.peek() << " ";
      copyCalc.pop();
    }
    cin >> input;
    if (input == "q" || input == "Q") break;
    cin.ignore();
    
  
    if (input == "+" && calculator.siz() >= 2)
    {
      val1 = calculator.peek();
      calculator.pop();
      val2 = calculator.peek();
      calculator.pop();
      calculator.push(val2 + val1);
    }
    else if (input == "-" && calculator.siz() >= 2)
    {
      val1 = calculator.peek();
      calculator.pop();
      val2 = calculator.peek();
      calculator.pop();
      calculator.push(val2 - val1);
    }
    else if (input == "*" && calculator.siz() >= 2)
    {
      val1 = calculator.peek();
      calculator.pop();
      val2 = calculator.peek();
      calculator.pop();
      calculator.push(val2 * val1);
    }
    else if (input == "/" && calculator.siz() >= 2)
    {
      val1 = calculator.peek();
      calculator.pop();
      val2 = calculator.peek();
      calculator.pop();
      calculator.push(val2 / val1);
    }
    numericalInput = atof(input.c_str());
    if (numericalInput != 0.0)
    {
      calculator.push(numericalInput);
    }
  }
  
  return 0;
}