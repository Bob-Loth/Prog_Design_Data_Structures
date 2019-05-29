#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H
#include <string>

template <typename V>
class SortableArray
{
public:
  //constructors
  inline SortableArray(int = 10);
  inline ~SortableArray();
  inline SortableArray(const SortableArray<V>&);

  //public member functions
  inline SortableArray<V>& operator=(const SortableArray<V>&);
  inline int capacity() const;
  inline void capacity(int);
  inline V operator[](int) const; //getter
  inline V& operator[](int);   //setter
  inline void qsort(int, int);
private:
  V* values;
  int cap;
  V dummy = V();
  int partition(int start, int end);
};

template <typename V>
SortableArray <V>::SortableArray(int cap)
{
  this->cap = cap;
  values = new V[cap];
  for (int i = 0; i < cap; i++)
  {
    values[i] = V();
  }
}
template<typename V>
SortableArray<V>::~SortableArray()
{
  delete[] values;
}
template<typename V>
SortableArray<V>::SortableArray(const SortableArray<V>& original)
{
  cap = original.cap;
  values = new V[cap];

  for (int i = 0; i < cap; ++i) {
    values[i] = original.values[i];
  }
}
template<typename V>
SortableArray<V>& SortableArray<V>::operator=(const SortableArray<V>& original)
{
  if (this != &original)
  {
    delete[] values;

    cap = original.cap;
    values = new V[cap];
    for (int i = 0; i < cap; ++i)
    {
      values[i] = original.values[i];
    }
  }
  return *this;
}
template <typename V>
int SortableArray <V>::capacity() const
{
  return cap;
}
template<typename V>
void SortableArray<V>::capacity(int cap)
{
  V* temp = new V[cap];
  int limit;
  (cap < this->cap) ? limit = cap : limit = this->cap;

  for (int i = 0; i < limit; ++i)
  {
    temp[i] = values[i];
  }

  for (int i = limit; i < cap; ++i)
  {
    temp[i] = V();
  }
  delete[] values;
  values = temp;
  this->cap = cap;
}
template <typename V>
V SortableArray <V>::operator[](int index) const
{
  if (index < 0)
  {
    return V();
  }
  return values[index];
}
template <typename V>
V& SortableArray <V>::operator[](int index)
{
  if (index < 0)
  {
    return dummy;
  }
  if (index >= cap)
  {
    capacity(2 * index);
  }
  return values[index];
}

template<typename V>
inline void SortableArray<V>::qsort(int start, int end)
{
	if (start < end) {
		int pivot = partition(start, end);
		qsort(start, pivot);
		qsort(pivot+1, end);
	}
}

template<typename V>
inline int SortableArray<V>::partition(int start, int end)
{
	V pivotVal = values[start];
	int pivot = start;
	int i = start;
	int j = end;
	V temp;
	bool swapped = true;

	while (swapped) {
		swapped = false;
		while (j >= pivot) { //move back ptr and swap if needed
			if (values[j] < pivotVal) {
				temp = values[pivot];
				values[pivot] = values[j];
				values[j] = temp;
				pivot = j;
				swapped = true;
				break;
			}
			else j--;
		}
		while (i <= pivot) { //move front ptr and swap if needed
			if (values[i] > pivotVal) {
				temp = values[pivot];
				values[pivot] = values[i];
				values[i] = temp;
				pivot = i;
				swapped = true;
				break;
			}
			else i++;
		}
		//stops when i and j are at pivot
	}
	return pivot;
}

#endif