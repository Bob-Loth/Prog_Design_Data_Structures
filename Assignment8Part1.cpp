//programmer's name: Robert Loth
//programmer's ID: 1684749
/*manually tested the first 10000, results were accurate when compared with excel-sorted values.
At present, reading and sorting 80k lines is expected to take over half-hour. 
Will review code and sort out any inefficiencies that are not due to the use of our DynamicArray class.*/
#define _CRT_SECURE_NO_WARNINGS
//C++ Libs
#include <fstream>
#include <string>
#include <iostream>
// C Libs
#include <cstring>
#include <ctime>
//to count number of unique classes held at dvc
using namespace std;
double timingTestResult(int testN);

int main() {
  
  
  
  cout << "Programmer's name: Robert Loth" << endl;
  cout << "Programmer's ID: 1684749" << endl << endl;
  
  for (int n = 8000; n <= 64000; n *= 2) {
    if (n == 8000)
      cout << timingTestResult(n) << " (Expected O(n)) for n = " << n << endl;
    else
      cout << timingTestResult(n) << " (Expected " << 2 * timingTestResult(n / 2) // twice the runtime of the previous result, assuming linear progression
      << ") for n = " << n << endl;
  }
  return 0;
}

double timingTestResult(int maxN) {
  ifstream fin;
  string line;
  int n = 1;
  char str[1000];
  char* token = strtok(str, "\t");
  clock_t startTime = clock();
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  
  while (fin.good() && n <= maxN) {

    getline(fin, line);
    strcpy(str, line.c_str());
    if (str[0] == 0) continue;
    //parse line
    const string term(token = strtok(str, "\t"));
    const string section((token = strtok(0, "\t")) ? token : "");
    const string course((token = strtok(0, "\t")) ? token : "");
    const string instructor((token = strtok(0, "\t")) ? token : "");
    const string whenWhere((token = strtok(0, "\t")) ? token : "");
    if (course.find('-') == string::npos) continue;
    const string subjectCode(course.begin(), course.begin() + course.find('-'));
    ++n;
  }
  clock_t endTime = clock();
  double parseExecTime = double(endTime - startTime) / CLOCKS_PER_SEC;
  fin.close();
  return parseExecTime;
}
