//Programmer: Bob Loth
//Programmer's ID: 1684749

#ifndef LABEXERCISE0_H
#define LABEXERCISE0_H

#include <iostream>
#include <string>
using namespace std;
void Welcome(){

    string firstName;
    string lastName;
    //prompt user
    cout << "Please enter your first name: ";
    cin >> firstName;
    cin.ignore();
    cout << "Please enter your last name: ";
    cin >> lastName;
    cin.ignore();
    //print out welcome message
    //give some course info
    cout << "COMSC210 : Lab Exercise Zero" << endl;
    cout << "============================" << endl;
    cout << lastName << " " << firstName << ", Welcome to COMSC210-2704" << endl;
    cout << firstName << endl;
    cout << lastName << endl;
    cout << "Enjoys the hybrid format class!!" << endl;
    cout << lastName << ", " << firstName << endl;
    cout << "The class will meet once a week at 11:10am in L-149 on Thursday." << endl;

}

#endif // LABEXERCISE0_H
