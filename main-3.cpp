//programmer's name: Robert Loth, Daniel Anderson
//programmer's ID: 1684749, 1038385

#include <iostream>
#include <string>
#include "Array.h"


using namespace std;

int main()
{
	cout << "Programmers' names: Robert Loth, Daniel Anderson" << endl;
	cout << "Programmers' ID: 1684749, 1038385" << endl;

	string indexInput;
	Array indexArray;

	string valueInput;
	Array valueArray;

	int i = 0;
	//prompt user to input index and value
	while (indexInput != "Q")
	{
		
		cout << "input an index and a value in format: index value [press Q to quit]: ";
		cin >> indexInput;
		if (indexInput == "Q") break;
		cin >> valueInput;
		indexArray[i] = atoi(indexInput.c_str());
		valueArray[i] = atoi(valueInput.c_str());
		i++;
	}
	cout << "You stored this many values: " << i << endl;
	for (int j = 0; j < i; j++)
	{
		cout << indexArray[j] << " => " << valueArray[j] << endl;
	}
	system("pause");
	return 0;
}