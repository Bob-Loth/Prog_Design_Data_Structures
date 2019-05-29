#include <iostream>
#include <iomanip>
#include <assert.h>
#include <cstdlib>
#include <ctime>

#include "DynamicArray.h"
using namespace std;
double SortTest(const int INITIAL_N);
int main() {

  srand(time(0)); rand();
  for (int i = 0, n = 500; i < 5; i++, n *= 2) {
    cout << "for n=" << n << ": " << SortTest(n) << " ms, expected ";
    cout << 4 * SortTest(n / 2) << endl;
  }
  

  return 0;
}
double SortTest(const int INITIAL_N) {
  int n = INITIAL_N;

  DynamicArray<double> array(n);
  for (int i = 0; i < n; ++i) {
    array[i] = rand();
  }
  clock_t startTime = clock();
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (array[i] > array[j]) {
        double temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
  clock_t endTime = clock();
  double elapsedSeconds = double(endTime - startTime) / CLOCKS_PER_SEC;

  for (int i = 1; i < n; i++) assert(array[i - 1] <= array[i]);
  return elapsedSeconds;
}
