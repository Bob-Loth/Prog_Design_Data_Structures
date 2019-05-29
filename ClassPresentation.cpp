#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <ctime>
#include <cstdlib>
#include <random>
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
	const int fileLines = 1000000;
	//contains 1 million lines of either rock, paper, or scissors
	fout.open("rps.txt");
	for (int i = 0; i < fileLines; i++) {
		int r = rand() % 3;
		if (r == 0) fout << "rock\n";
		else if (r == 1) fout << "paper\n";
		else fout << "scissors\n";
	}
	fout.close();
	vector<string> rps;
	fin.open("rps.txt");
	int lineCount = 0;
	while (getline(fin, line)) {
		lineCount++;
		rps.push_back(line);
	}
	fin.close();
	
	SortableArray<string> sstring;
	cout << "file contained " << lineCount << " lines.\n\n";
	for (int i = 0; i < lineCount; i++) {
		sstring[i] = rps[i];
	}
	cout << "Sample of array before sorting by countSort:\n";
	sstring.reportSlice(lineCount); //gives 10 values, evenly spaced
	start = clock();
	sstring.countSort(lineCount);
	end = clock();
	duration = ((double)end - (double)start) / CLOCKS_PER_SEC;
	cout << "\ncountSort operation on " << lineCount << " strings took " <<
		duration << " seconds.\n\n";
	cout << "Sample of array sorted by countSort:\n";
	sstring.reportSlice(lineCount);
	
	
	fout.open("rps.txt");
	for (int i = 0; i < fileLines; i++) {
		int r = rand() % 3;
		if (r == 0) fout << "rock\n";
		else if (r == 1) fout << "paper\n";
		else  fout << "scissors\n";
	}
	fout.close();
	SortableArray<string> sstring2;
	fin.open("rps.txt");
	for (int i = 0; i < fileLines; ++i) {
		getline(fin, line);
		sstring2[i] = line;
	}
	cout << "\nSample of array before sorting by count3Sort:\n";
	sstring2.reportSlice(lineCount); //gives 9 values, evenly spaced
	start = clock();
	sstring2.count3Sort(lineCount);
	end = clock();
	duration = ((double)end - (double)start) / CLOCKS_PER_SEC;
	cout << "\ncount3Sort operation on " << lineCount << " strings took " <<
		duration << " seconds.\n\n";
	cout << "Sample of array sorted by count3Sort:\n";
	sstring2.reportSlice(lineCount);


	//sstring.Shuffle(lineCount);
	//start = clock();
	//sstring.qsort(0, lineCount);
	//end = clock();
	//duration = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
	//cout << "\n\n\nquickSort operation on " << lineCount << " strings took " <<
	//	duration << " seconds.\n\n";

	//
	//sstring.reportSlice(lineCount, num_slices);
	//sstring.Shuffle(lineCount);
	//cout << "\n\n";
	//sstring.reportSlice(lineCount, num_slices);
	//start = clock();
	//sstring.inSort(0, lineCount); //from 0 to lineCount, with run size 
	//end = clock();
	//duration = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
	//cout << "\n\n\ninSort operation on " << lineCount << " strings took " <<
	//	duration << " seconds.\n\n";
	//
	//sstring.Shuffle(lineCount);

	//start = clock();
	//sstring.mergeSort(lineCount, 64); //from 0 to lineCount, with run size 
	//end = clock();
	//duration = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
	//cout << "\n\n\nmergeSort operation on " << lineCount << " strings took " <<
	//	duration << " seconds.\n\n";
	//
	//sstring.Shuffle(lineCount);

	//start = clock();
	//sstring.heapSort(lineCount); //from 0 to lineCount, with run size 
	//end = clock();
	//duration = ((double)end - (double)start) / (double)CLOCKS_PER_SEC;
	//cout << "\n\n\nheapSort operation on " << lineCount << " strings took " <<
	//	duration << " seconds.\n\n";

	//sstring.Shuffle(lineCount);
	
	
	return 0;
}