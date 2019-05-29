#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H
#include <string>

template <typename V, int CAP>
class StaticArray
{
public:
  StaticArray();
  int capacity() const;
  V operator[](int) const; //getter
  V& operator[](int);   //setter
private:
  V values[CAP];
  V dummy;
};
#endif