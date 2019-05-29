// Programmer: Bob Loth
// Programmer's ID: 1684749
#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib> //rand
#include <ctime> //seed rand
using namespace std;

int main()
{
  // programmer's identification
  cout << "Programmer: Bob Loth\n";
  cout << "Programmer's ID: 1684749\n";
  cout << "File: " << __FILE__ << endl;

  //generate attendance records, output to xls file
  ofstream fout;
  srand(time(0));
  
  vector<int> attendanceMoe;
  vector<int> attendanceCurly;
  vector<int> attendanceLarry;
  //populate attendance with random 1 or 0
  for (int i = 0; i < 5; i++) {
    attendanceMoe.push_back(rand() % 2);
    attendanceCurly.push_back(rand() % 2);
    attendanceLarry.push_back(rand() % 2);
  }

  //add present(1) or absent(0) string values to xls file
  fout.open("attendanceRecords.xls");
  if (fout.good())
  {
    fout << "Moe\t" << "Curly\t" << "Larry\n";
    for (int i = 0; i < 5; i++)
    {
      fout << attendanceMoe.at(i) << "\t";
      fout << attendanceCurly.at(i) << "\t";
      fout << attendanceLarry.at(i) << "\n";
    }
    fout.close();
  }
}

