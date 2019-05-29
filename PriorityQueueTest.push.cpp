
#include "PriorityQueue.h"
#include <iostream>
#include <cstdlib> //rand, srand
#include <ctime> //time
#include <cmath> //log
#include <cassert>
using namespace std;
double PushTest(int n) {
	PriorityQueue<double> TestQ(n);
	clock_t startTime = clock();
	for (int i = 0; i < n; i++) {
		TestQ.push(rand());
	}
	clock_t endTime = clock();
	
	assert(TestQ.size() == n);
	for (int i = 0; i < n; i++) { //determine if queue is ordered correctly
		double prev = TestQ.top();
		TestQ.pop();
		double next = TestQ.top();
		assert(prev >= next);
	}
	double elapsedSeconds = (double)endTime - (double)startTime / CLOCKS_PER_SEC;
	return elapsedSeconds;
}
int main()
{
	srand(time(0)); 
	int multValue = 2;
	int multTimes = 5;
	int init_n = 4000;
	for (int i = 0, n = init_n; i < multTimes; i++, n *= multValue) {
		cout << "for n=" << n << ": " << PushTest(n) << " ms, expected ";
		cout << log2(multValue) * PushTest(n / multValue) << endl;
	}
}

