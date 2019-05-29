//programmer's name: Robert Loth, Daniel Anderson
//programmer's ID: 1684749, 1038385

#include <iostream>
#include <cassert>
#include "Array.h"

using namespace std;

int main()
{
	Array myArray;
	//capacity test
	assert(myArray.capacity() == 100); 
	//constructor test
	for (int i = 0; i < myArray.capacity(); i++) 
	{
		assert(myArray[i] == 0);
	}
	myArray[6] = 12356;
	myArray[7] = 7654321;
	assert(12356 == myArray[6]);
	assert(7654321 == myArray[7]);
	myArray[-1000] = 123123;
	assert(12356 == myArray[6]);
	assert(7654321 == myArray[7]);
	assert(123123 == myArray[-6]);
	assert(123123 == myArray[100]);
	assert(123123 != myArray[9]);
	assert(71841 != myArray[8]);

	return 0;
}