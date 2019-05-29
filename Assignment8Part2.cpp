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
//data structures
#include "DynamicArray.h"
//to count number of unique classes held at dvc
using namespace std;
struct SectionsForTerm
{
  string term;
  int numberOfSectionsSeen;
  DynamicArray<string> seenSectionNumber;
};
struct Subject
{
  string subjectCode;
  int count;
};
double timingTestResult(int testN);
int check_term_duplication(const string term, const DynamicArray<SectionsForTerm>& termArray, int size) {
  int term_index = -1;
  for (int i = 0; i < size; i++) {
    if (termArray[i].term == term) {
      term_index = i;
      break;
    }
  }
  return term_index;
}
bool check_section_duplication(const string section, const SectionsForTerm& termArray) {
  for (int i = 0; i < termArray.numberOfSectionsSeen; i++) {
    if (termArray.seenSectionNumber[i] == section) {
      return true;
    }
  }
  return false;
}

int main() {
  cout << "Programmer's name: Robert Loth" << endl;
  cout << "Programmer's ID: 1684749" << endl << endl;
  for (int n = 800; n <= 800 * 16; n *= 2) {
    if (n == 800)
      cout << timingTestResult(n) << " (Expected O(n)) for n = " << n << endl;
    else
      cout << timingTestResult(n) << " (Expected " << 2 * timingTestResult(n / 2) // twice the runtime of the previous result, assuming linear progression
      << ") for n = " << n << endl;
  }
  system("pause");
  return 0;
}

double timingTestResult(int maxN) {
  ifstream fin;
  string line;
  int n = 1;
  int numberOfTermsSeen = 0;
  int duplicates = 0;
  char str[1000];
  char* token = strtok(str, "\t");
  
  DynamicArray<SectionsForTerm> alreadySeen(100);
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
    bool found = false;
    int term_index = check_term_duplication(term, alreadySeen, numberOfTermsSeen);
    if (term_index != -1) {
      found = check_section_duplication(section, alreadySeen[term_index]);
      if (!found) {
        alreadySeen[term_index].seenSectionNumber
          [alreadySeen[term_index].numberOfSectionsSeen++] = section;
      }
    }
    else {
      alreadySeen[numberOfTermsSeen].term = term;
      alreadySeen[numberOfTermsSeen].numberOfSectionsSeen = 1;
      alreadySeen[numberOfTermsSeen].seenSectionNumber[0] = section;
      numberOfTermsSeen++;
      duplicates++;
    }
    n++;
  }//while
  clock_t endTime = clock();
  double parseExecTime = double(endTime - startTime) / CLOCKS_PER_SEC;
  fin.close();
  return parseExecTime;
}

