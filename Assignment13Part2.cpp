#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <map>
#include <vector>
#include <sstream>
#include <fstream>
using namespace std;
int main() {
	string input;
	ifstream fin;
	string line;
	char str[1000];
	char* token = strtok(str, "\t");
	int courseCount = 0;
	map<string, vector<string>> courses; //section+semester creates something that should be unique
										//if vector size > 1, then there are multiple classes per section+semester
	
	fin.open("dvc-schedule.txt");
	while (fin.good()) {
		getline(fin, line);
		strcpy(str, line.c_str());
		if (str[0] == 0) continue;

		const string semester(token = strtok(str, "\t"));
		const string section((token = strtok(0, "\t")) ? token : "");
		const string course((token = strtok(0, "\t")) ? token : "");

		courses[semester + " " + section].push_back(course);
		++courseCount;
	}
	int dup = 0;
	for (auto it = courses.begin(); it != courses.end(); ++it) {
		if (it->second.size() > 1) { //if there are multiple courses per unique term+section
			cout << it->first << ": \n"; //output the term+section 
			for (int i = 0; i < it->second.size(); ++i) { //as well as all associated courses
				cout << "\t" << it->second.at(i) << endl;
				++dup;
			}
		}
	}
	cout << dup << " out of " << courseCount <<
		" courses appear to share a section+term with at least one other course\n";
}