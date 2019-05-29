


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <fstream>
using namespace std;
int main() {
	string input;
	ifstream fin;
	string line;
	char str[1000];
	char* token = strtok(str, "\t");
	map <string, set<string>> courses; //course, term year, term

	fin.open("dvc-schedule.txt");
	if (!fin.good()) throw "IO error";
	while (fin.good()) {
		getline(fin, line);
		strcpy(str, line.c_str());
		if (str[0] == 0) continue;

		const string semester(token = strtok(str, " "));
		const string year((token = strtok(0, "\t")) ? token : "");
		const string donotuse((token = strtok(0, "\t")) ? token : "");
		const string course((token = strtok(0, "\t")) ? token : "");

		courses[course].insert(year + " " + semester);


	}
	while (true) {


		cout << "Please enter a course name(SUBJ-course#), or X to quit: ";
		cin >> input;
		cin.ignore();
		if (input == "x" || input == "X") break;
		auto it = courses.find(input);
		if (it == courses.end()) {
			cout << "No record of " << input << " found in courses since 2000.\n";
		}
		else {
			line = *it->second.begin();
			string earliestYear = line.substr(0, line.find(" "));
			string earliestSemester = line.substr(line.find(" ") + 1, line.back());
			cout << it->first << " - earliest course is in the " << earliestSemester
				<< " of " << earliestYear << endl;
			line = *--it->second.end();
			string latestYear = line.substr(0, line.find(" "));
			string latestSemester = line.substr(line.find(" ") + 1, line.back());
			cout << it->first << " - latest course is in the " << latestSemester
				<< " of " << latestYear << endl;
		}
	}
}