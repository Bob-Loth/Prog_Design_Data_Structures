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
bool check_duplication(const string classCode, const DynamicArray<string> &classArray, int size);

int main() {
  DynamicArray<string> UniqueClasses;
  DynamicArray<Subject> subjectCount;
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
  system("pause");
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
    //cout << term << '|' << section << '|' << course << '|' << instructor << '|';
    //cout << whenWhere << '|' << subjectCode << endl;
    //small count
    if (count % 10 == 0) {
      cout << '.';
      cout.flush();
    }
    //large count
    if (count % 100 == 0) {
      system("CLS");
      cout << count;
    }
    //update UniqueClasses array
    string classCode = term + section;
    bool found = check_duplication(classCode, UniqueClasses, classIndex);
    if (!found) {
      UniqueClasses[classIndex++] = classCode;
      for (int i = 0; i < subjectIndex; ++i) {
        if (subjectCount[i].subjectCode == subjectCode) { 
          found = true;
          //cout << i << "notDup" << endl; //for debugging
          subjectCount[i].count++; // adds 1 to the subjectCount of the object with matching subjectCode
          break;
        }
        /* I PUT THE ELSE DUPLICATES STATEMENT HERE IN A PREVIOUS BUILD. 
        MADE DUPLICATES INACCURATE AND MADE RUNTIME >1hour. ALWAYS PLACE TO INDICATE DUPLICATE FOUND.
        */
      }
    }
    else duplicates++;
    
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
    for (int j = 0; j < count; j++) {
      if (subjectCount[i].subjectCode > subjectCount[j].subjectCode)
        swap(subjectCount[j], subjectCount[i]);
    }
  }
  //output subjects followed by number of sections per subject
  cout << "\n\nDuplicates found: " << duplicates << endl;
  cout << "Number of subjects: " << subjectIndex << endl << endl;
  for (int i = subjectIndex - 1; i >= 0; i--) {
    cout << subjectCount[i].subjectCode << " - " << subjectCount[i].count << " sections" << endl;
  }
  system("pause");
  return 0;
}

bool check_duplication(const string classCode, const DynamicArray<string>& classArray, int size) {
  for (int i = 0; i < size; ++i) {
    if (classArray[i] == classCode) return true;
  }
  return false; //went through all entries without finding duplicate
  //refine this later to start searching for duplicates at the correct character, rather than starting at A every time
}

//for (int i = 0; i < nonDuplicateClasses.capacity(); ++i){
//  if (term+section == term+section[i])

