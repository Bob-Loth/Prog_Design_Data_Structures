#pragma once
#include <algorithm>

template<typename V>
class PriorityQueue
{
	V* values;
	int CAP;
	int siz;

	void capacity(int);
public:
	PriorityQueue(int = 2);
	PriorityQueue(const PriorityQueue<V>&);
	~PriorityQueue() { delete values; }

	void push(const V&);
	void pop();
	V top() const { return values[0]; }
	int size() { return siz; }
	bool empty() { return (siz == 0) ? true : false; }
	void clear() { siz = 0; }

};

template<typename V>
inline void PriorityQueue<V>::capacity(int)
{
	return CAP;
}

template<typename V>
inline PriorityQueue<V>::PriorityQueue(int cap)
{
	CAP = cap;
	values = new V[CAP];
	siz = 0;
}

template<typename V>
inline PriorityQueue<V>::PriorityQueue(const PriorityQueue<V>& original)
{
	this->CAP = original.CAP;
	this->siz = original.siz;
	this->values = new V[CAP];
	for (int i = 0; i < siz; i++) {
		this->values[i] = original.values[i];
	}
}

template<typename V>
inline void PriorityQueue<V>::push(const V& val)
{
	if (siz == CAP) {//double array capacity
		int newCap = CAP * 2;
		V* temp = new V[newCap];
		std::copy(values, values + CAP, temp);
		delete values;
		values = temp;
	}
	values[siz] = val;
	int index = siz;
	siz++;
	while (index != 0) {
		int parentIndex = ((index + 1) / 2) - 1;
		if (values[index] > values[parentIndex]) {
			std::swap(values[index], values[parentIndex]);
			index = parentIndex;
		}
		else break;
	}
	
}

template<typename V>
inline void PriorityQueue<V>::pop()
{
	bool empty = false;
	if (siz == 0) empty = true;
	if (!empty) {
		int index = 0;
		for (index = 0; index < siz; index++)
		{
			int leftChild = (index * 2) + 1;
			int rightChild = (index * 2) + 2;
			if (leftChild > siz) break;
			if (rightChild > siz) {
				values[index] = values[leftChild];
				index = leftChild;
			}
			else if (values[leftChild] > values[rightChild]) {
				values[index] = values[leftChild];
				index = leftChild;
			}
			else {
				values[index] = values[rightChild];
				index = rightChild;
			}
		}
		siz--;
		values[index] = values[siz];
		{
			if (index != 0) {
				int parentIndex = (index + 1) / 2 + 1;
				if (values[index] > values[parentIndex]) {
					V temp = values[index];
					values[index] = values[parentIndex];
					values[parentIndex] = temp;
					index = parentIndex;
				}
			}
		}
	}
}
