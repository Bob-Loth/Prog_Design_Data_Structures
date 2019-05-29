#ifndef STATIC_ARRAY_H
#define STATIC_ARRAY_H
#include <unordered_set>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>
template <typename V>

class SortableArray
{
public:
	//constructors
	SortableArray(int = 10);
	~SortableArray();
	SortableArray(const SortableArray<V>&);

	//public member functions
	SortableArray<V>& operator=(const SortableArray<V>&);
	int capacity() const;
	void capacity(int);
	V operator[](int) const; //getter
	V& operator[](int);   //setter
	void heapSort(int size); 
	void countSort(int size);
	void count3Sort(int size);
	void reportSlice(int size) const;
private:
	V* values;
	int cap;
	V dummy = V();
	void heapify(int size, int i);
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
inline void SortableArray<V>::heapSort(int size)
{
	for (int i = size / 2 - 1; i >= 0; --i) {
		heapify(size, i);
	}

	for (int i = size - 1; i >= 0; --i) {
		std::swap(values[0], values[i]);
		heapify(i, 0);
	}

	

}


template<typename V>
void SortableArray<V>::countSort(int size)
{
	std::map<V, int> uniqueVals;
	
	for (int i = 0; i < size; ++i) {
		++uniqueVals[values[i]];
	}
	
	//now "sort" the data back into the array
	auto it = uniqueVals.begin();
	int i = 0, num = 0, prev = 0;
	for (auto it = uniqueVals.begin(); it != uniqueVals.end(); it++) {
		
		num += it->second;
		for (i = prev; i < num; ++i) {
			values[i] = it->first;
		}
		prev = num;
	}
	
	for (auto it = uniqueVals.begin(); it != uniqueVals.end(); it++) {
		std::cout << "num of " << it->first << ": " << it->second << std::endl;
	}

	
}
template<typename V>
void SortableArray<V>::count3Sort(int size)
{
	V val1 = values[0]; //the first unique value
	V val2;
	V val3;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;

	for (int i = 1; i < size; ++i) { //find the second unique value
		if (values[i] != val1) {
			val2 = values[i];
			break;
		}
	}

	for (int i = 1; i < size; ++i) {
		if (values[i] != val1 && values[i] != val2) {//find the third unique value
			val3 = values[i];
			break;
		}
	}

	//optional step, if you care about the data being in correct order as well as all together
	V minVal = std::min(val1, val2);
	minVal = std::min(minVal, val3);
	V maxVal = std::max(val1, val2);
	maxVal = std::max(maxVal, val3);
	V medVal = std::max(val1, val2);
	medVal = std::min(medVal, val3);
	if (medVal == minVal || medVal == maxVal)
	{
		medVal = std::min(val1, val2);
		medVal = std::max(medVal, val3);
	}
	//now count the occurrences of val1 val2 and val3
	for (int i = 0; i < size; ++i) {
		if (values[i] == minVal) num1++;
		if (values[i] == medVal) num2++;
		if (values[i] == maxVal) num3++;

	}
	//now "sort" the data back into the array
	int i = 0;
	//first part
	for (i = 0; i < num1; ++i) {
		values[i] = minVal;
	}
	//second part
	for (i = num1; i < num1 + num2; ++i) {
		values[i] = medVal;
	}
	//last part
	for (i = num1 + num2; i < size; ++i) {
		values[i] = maxVal;
	}
	std::cout << "num of Paper: " << num1 << std::endl;
	std::cout << "num of Rock: " << num2 << std::endl;
	std::cout << "num of Scissors: " << num3 << std::endl;
}
template<typename V>
inline void SortableArray<V>::reportSlice(int size) const
{
	std::cout << "Selecting 10 evenly-spaced values from array to display\n\n";
	int slice = size / 9;
	for (int i = 0; i < 10; ++i) {
		std::cout << values[slice * i] << std::endl;
	}
	
}

template<typename V>
void SortableArray<V>::heapify(int size, int root)
{
	int max = root;
	//heap children calcs
	int left = 2 * root + 1; 
	int right = 2 * root + 2;

	if (left < size) {
		if (values[left] > values[max]) {
			max = left; //new root;
		}
	}
	if (right < size) {
		if (values[right] > values[max]) {
			max = right; //new root;
		}
	}
	if (max != root) { // if max has been reassigned.
		std::swap(values[root], values[max]);

		heapify(size, max); //repeat until root = max
	}
	//if you get here, the root is the largest value in the subheap
}




#endif
