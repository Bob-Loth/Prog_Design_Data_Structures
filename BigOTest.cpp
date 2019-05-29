#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>

#include "Sorting.h"
using namespace std;
int main() {
	srand(time(0));
	
	clock_t start;
	clock_t end;
	double duration; //time taken for certain operations
	ifstream fin;
	ofstream fout;
	string line; //file input reader
	const int fileLines = 10000000;
	fout.open("rps.txt");
	for (int i = 0; i < fileLines; i++) {
		int r = rand() % 3;
		if (r == 0) fout << "rock\n";
		else if (r == 1) fout << "paper\n";
		else fout << "scissors\n";
	}
	fout.close();
	cout << "\nSTARTING TEST FOR TIME COMPLEXITY WITH INCREASING N\n\n";
	for (int n = 10000; n <= 10000000; n *= 10) { //10thousand to 10million, inclusive
		fin.open("rps.txt");
		SortableArray<string> test;
		for (int i = 0; i < n; i++) {
			getline(fin, line);
			test[i] = line;
		}
		fin.close();
		cout << "\nSample of array of size " << n << " before sorting by countSort:\n";
		test.reportSlice(n); //gives 10 values, evenly spaced, starting at values[0]

		start = clock();
		test.countSort(n);
		end = clock();
		duration = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
		cout << "\ncountSort operation on " << n << " strings took " <<
			duration << " seconds.\n\n";
		cout << "Sample of array sorted by countSort:\n";
		test.reportSlice(n);
	}

	cout << "STARTING TEST FOR TIME COMPLEXITY WITH INCREASING U (unique elements)\n\n";

	for (int U = 10; U < 101; U = U + 10)
	{
		const int n = 3000000; //n remains at 1 million, U changes
		fout.open("rps2.txt");
		for (int i = 0; i < n; i++) { //n remains at 1 million, U changes
			int r = rand() % U; //U represents num of unique elements
			fout << r << " ";
		}
		fout.close();
		fin.open("rps2.txt");
		SortableArray<int> test;
		int intTest;
		for (int i = 0; i < n; i++) {
			fin >> intTest;
			test[i] = intTest;
		}
		fin.close();
		cout << "\nSample of array with " << U << " unique values before sorting by countSort:\n";
		test.reportSlice(n); //gives 10 values, evenly spaced, starting at values[0]

		start = clock();
		test.countSort(n);
		end = clock();
		duration = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
		cout << "\ncountSort operation on " << n << " strings with " << U << " unique elements took " <<
			 duration << " seconds.\n\n";
		cout << "Sample of array sorted by countSort:\n";
		test.reportSlice(n);
	}
	
	
	
	
	


	return 0;
}