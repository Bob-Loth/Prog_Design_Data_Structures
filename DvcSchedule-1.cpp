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
#include "DynamicArray.h"
#include <assert.h>
// C Libs
#include <cstring>

//to count number of unique classes held at dvc
using namespace std;
struct Subject
{
  std::string subjectCode;
  int count;
};
struct SectionsForTerm
{
  string term;
  int numberOfSectionsSeen;
  DynamicArray<string> seenSectionNumber;
};
int check_term_duplication(const string term, const DynamicArray<SectionsForTerm>& termArray, int size);
bool check_section_duplication(const string section, const SectionsForTerm& termArray);


int main() {
  DynamicArray<string> UniqueClasses;
  DynamicArray<Subject> subjectCount;

  int numberOfTermsSeen = 0;
  DynamicArray<SectionsForTerm> alreadySeen(100);

  ifstream fin;
  string line;

  int count = 0;
  int classIndex = 0;
  int subjectIndex = 0;
  int duplicates = 0;
  char str[1000];
  char* token = strtok(str, "\t");

  cout << "Programmer's name: Robert Loth" << endl;
  cout << "Programmer's ID: 1684749" << endl;
  cout << "Press enter to begin reading file, storing and sorting data in file." << endl;
  cin.ignore();
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  while (fin.good()) {
    
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
    
    //update alreadySeen array, seenSectionNumber
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
    }
    
    if (!found) {
      for (int i = 0; i < subjectIndex; i++) {
        if (subjectCount[i].subjectCode.compare(subjectCode) == 0) {
          found = true;
          subjectCount[i].count++;
          break;
        }
      }
    }
    else {
      duplicates++;
    }
    if (!found) {
      subjectCount[subjectIndex].subjectCode = subjectCode;
      subjectCount[subjectIndex].count++;
      subjectIndex++;
    }
    count++;
  }
  fin.close();

  //sort subjectCount array
  for (int i = 0; i < count; i++) {
    if (i % 5000 == 0) {
      cout << ".";
      cout.flush();
    }
    for (int j = 0; j < count; j++) {
      if (subjectCount[i].subjectCode > subjectCount[j].subjectCode)
        swap(subjectCount[j], subjectCount[i]);
    }
  }
  //output subjects followed by number of sections per subject
  
  for (int i = subjectIndex - 1; i >= 0; i--) {
    cout << subjectCount[i].subjectCode << " - " << subjectCount[i].count << " sections" << endl;
  }
  cout << "\n\nDuplicates found: " << duplicates << endl;
  cout << "Number of subjects: " << subjectIndex << endl << endl;
  system("pause");
  return 0;
}

int check_term_duplication(const string term, const DynamicArray<SectionsForTerm>& termArray, int size) {
  int term_index = -1;
  for (int i = 0; i < size; i++) {
    if (termArray[i].term == term) term_index = i; break;
  }
  return term_index;
}
bool check_section_duplication(const string section, const SectionsForTerm& termArray) {
  for (int i = 0; i < termArray.numberOfSectionsSeen; i++) {
    if (termArray.seenSectionNumber[i] == section) {
      return true;
    }
  }
}


