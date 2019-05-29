#define _CRT_SECURE_NO_WARNINGS

// C++ libs
#include <iostream>
#include <string>
#include <fstream>
// C libs
#include <cstring>
#include <ctime>
// Classes
#include "HashTable.h"

using namespace std;
int hashCode(const string& key)
{
  int result = 0;
  for (unsigned int i = 0; i < key.length(); i++) {
    result = result + key.at(i);
  }
  return result;
}

int dup_hashCode(const string&);
int main() {
  cout << "Programmer's name: Robert Loth" << endl;
  cout << "Programmer's ID: 1684749" << endl;
  clock_t startTime = clock();
  const int RECORD_SIZE = 13000; 
  const int SUBCLASS_SIZE = 60; 
  HashTable<string, bool, RECORD_SIZE> record(dup_hashCode);
  HashTable<string, int, SUBCLASS_SIZE> subClass(hashCode);
  int dup = 0; //number of duplicate sections
  ifstream fin;
  string line;
  char str[1000];
  char* token = strtok(str, "\t");

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
    const string classCode = term + section;
    if (record[classCode]) dup++;
    else {
      record[classCode] = true;
      subClass[subjectCode]++;
      
    }
    
  }
  clock_t endTime = clock();
  double elapsedSeconds = double(endTime - startTime) / CLOCKS_PER_SEC;
  
  cout << "hashTable size = " << RECORD_SIZE << "/" <<  SUBCLASS_SIZE << endl;
  
  cout << "runtime: " << elapsedSeconds << " sec" << endl;
  cout << "The load factor for the duplication check: " << record.loadFactor() << endl; //number of used array indices
  cout << "The node load factor for the duplication check: " << record.Keys().size() * record.loadFactor() / RECORD_SIZE << endl;
  cout << "The average list size for the duplication check: " << record.Keys().size() / RECORD_SIZE  << endl; //average number of nodes in the list
  cout << "The load factor for the subject code: " << subClass.loadFactor() << endl;
  cout << "Total duplication: " << dup << "\n\n";
  queue<string> subQKeys = subClass.Keys();
  list<string> subVKeys;
  while (subQKeys.size()) {
    subVKeys.push_front(subQKeys.front());
    subQKeys.pop();
  }
  subVKeys.sort();
  for (list<string>::iterator it = subVKeys.begin(); it != subVKeys.end(); it++) {
    cout << *it << ", " << subClass[*it] << " section(s)" << endl;
  }
  
  return 0;
}

int dup_hashCode(const string& key)
{
  int result = 0;
  unsigned int i;
  for (i = 0; i < key.length() - 4; i++)
    result = result + key.at(i);
  for (int j = 0; j < 4; j++)
    result = result + (int)(key.at(i + j)) * pow(10, j);
  return result;
}

