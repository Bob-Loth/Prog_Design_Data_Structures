
#ifndef STACK_H
#define STACK_H
#include "DynamicArray.h"
template <typename T>
class Stack
{
private:
  DynamicArray<T> values;
  int end;

public:
  Stack();
  Stack(const Stack<T>&);
  ~Stack();
  Stack<T>& operator=(const Stack<T>&);
  void push(const T&);
  const T& peek() const;
  void pop();
  int siz() const;
  bool empty() const;
  void clear();
};

template<typename T>
Stack<T>::Stack()
{
  end = 0;
  for (int i = 0; i < end; i++)
  {
    values[i] = T();
  }
}

template<typename T>
Stack<T>::Stack(const Stack<T>& stack2)
{
  end = stack2.end;
  for (int i = 0; i < stack2.end; i++)
  {
    values[i] = stack2.values[i];
  }
}

template<typename T>
Stack<T>::~Stack()
{
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack<T>& stack2)
{
  
  this->end = stack2.end;
  for (int i = 0; i < stack2.end; i++)
  {
    this->values[i] = stack2.values[i];
  }
  return *this;
}

template<typename T>
void Stack<T>::push(const T & newValue)
{
  values[end] = newValue;
  end++;
}

template<typename T>
const T & Stack<T>::peek() const
{
  return values[end - 1];
}

template<typename T>
void Stack<T>::pop()
{
  if (end > 0)
    end--;
}

template<typename T>
int Stack<T>::siz() const
{
  return end;
}

template<typename T>
bool Stack<T>::empty() const
{
  return (end == 0) ? (true) : (false);
}

template<typename T>
void Stack<T>::clear()
{
  end = 0;
}
#endif // !STACK_H


