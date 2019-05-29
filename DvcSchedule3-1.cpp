#define _CRT_SECURE_NO_WARNINGS

#include "AssociativeArray.h"
#include "DynamicArray.h"
//C++ libs
#include <iostream>
#include <string>
#include <fstream>
// C libs
#include <cstring>
using namespace std;
int main() {
  cout << "Programmer's name: Robert Loth" << endl;
  cout << "Programmer's ID: 1684749" << endl;
  AssociativeArray<string, AssociativeArray<string, int>> count;//in order, subject code, then course, then # of sections
  AssociativeArray<string, AssociativeArray<string, bool>> alreadySeen;
  
  queue<string> courseKeys;
  ifstream fin;
  string line;
  char str[1000];
  char* token = strtok(str, "\t");
  fin.open("dvc-schedule.txt");
  if (!fin.good()) throw "I/O error";
  int dup = 0;
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

    if (alreadySeen[term].containsKey(section)) dup++;
    else
    {
      alreadySeen[term][section] = true;
      count[subjectCode][course]++;
    }
    
    
  }
  queue<string> subKeys = count.Keys();
  
  cout << "Duplication: " << dup << endl;
  DynamicArray<string> subjectCodes;
  for (int i = 0; subKeys.size(); i++)
  {
    subjectCodes[i] = subKeys.front();
    subKeys.pop();
  }
  for (int i = 0; i < count.size(); i++)
  {
    for (int j = i + 1; j < count.size(); j++)
    {
      if (subjectCodes[i] > subjectCodes[j])
      {
        swap(subjectCodes[i], subjectCodes[j]);
      }
    }
  }
  
  for (int i = 0; i < count.size(); i++)
  {
	int sizeS = count[subjectCodes[i]].size(); // number of courses in each subject code
    cout << subjectCodes[i] << ": "<< sizeS << " sections" << endl;
	for (int j = 0; j < sizeS; j++) {
		cout << "\t" << "course name" << ": " << "number of sections" << " sections" << endl;
	}
  }
  
  system("pause");
  return 0;
}