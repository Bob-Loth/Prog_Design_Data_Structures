#include "StaticArray.h"
#include <string>
template <typename V, int CAP>
  StaticArray <V, CAP>::StaticArray()
  {
    for (int i = 0; i < CAP; i++)
    {
      values[i] = V();
    }
    dummy = V();
  }
  template <typename V, int CAP>
  int StaticArray <V, CAP>::capacity() const
  {
    return CAP;
  }
  template <typename V, int CAP>
  V StaticArray <V, CAP>::operator[](int index) const
  {
    if (index < 0 || index >= CAP)
    {
      return dummy;
    }
    return values[index];
  }
  template <typename V, int CAP>
  V& StaticArray <V, CAP>::operator[](int index)
  {
    if (index < 0 || index >= CAP)
    {
      return dummy;
    }
    return values[index];
  }
