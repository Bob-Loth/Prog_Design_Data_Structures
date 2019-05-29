#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H
#include <string>

template <typename V>
class DynamicArray
{
public:
  //constructors
  inline DynamicArray(int = 10);
  inline ~DynamicArray();
  inline DynamicArray(const DynamicArray<V>&);

  //public member functions
  inline DynamicArray<V>& operator=(const DynamicArray<V>&);
  inline int capacity() const;
  inline void capacity(int);
  inline const V& operator[](int) const; //getter
  inline V& operator[](int);   //setter
private:
  V* classInfo;
  int cap;
  V dummy = V();
};

template <typename V>
DynamicArray <V>::DynamicArray(int cap)
{
  this->cap = cap;
  classInfo = new V[cap];
  for (int i = 0; i < cap; i++)
  {
    classInfo[i] = V();
  }
}
template<typename V>
DynamicArray<V>::~DynamicArray()
{
  delete[] classInfo;
}
template<typename V>
DynamicArray<V>::DynamicArray(const DynamicArray<V>& original)
{
  cap = original.cap;
  classInfo = new V[cap];

  for (int i = 0; i < cap; ++i) {
    classInfo[i] = original.classInfo[i];
  }
}
template<typename V>
DynamicArray<V>& DynamicArray<V>::operator=(const DynamicArray<V>& original)
{
  if (this != &original)
  {
    delete[] classInfo;

    cap = original.cap;
    classInfo = new V[cap];
    for (int i = 0; i < cap; ++i)
    {
      classInfo[i] = original.classInfo[i];
    }
  }
  return *this;
}
template <typename V>
int DynamicArray <V>::capacity() const
{
  return cap;
}
template<typename V>
void DynamicArray<V>::capacity(int cap)
{
  V* temp = new V[cap];
  int limit;
  (cap < this->cap) ? limit = cap : limit = this->cap;

  for (int i = 0; i < limit; ++i)
  {
    temp[i] = classInfo[i];
  }

  for (int i = limit; i < cap; ++i)
  {
    temp[i] = V();
  }
  delete[] classInfo;
  classInfo = temp;
  this->cap = cap;
}
template <typename V>
const V& DynamicArray <V>::operator[](int index) const
{
  if (index < 0)
  {
    return V();
  }
  return classInfo[index];
}
template <typename V>
V& DynamicArray <V>::operator[](int index)
{
  if (index < 0)
  {
    return dummy;
  }
  if (index >= cap)
  {
    capacity(2 * index);
  }
  return classInfo[index];
}

#endif