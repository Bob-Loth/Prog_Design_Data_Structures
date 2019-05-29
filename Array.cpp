#include "Array.h"



Array::Array()
{
	for (int i = 0; i < 100; i++)
	{
		values[i] = 0;
	}
	dummy = 0;
}


Array::~Array()
{
}

int Array::capacity()
{
	return 100;
}

int Array::operator[](int index) const
{
	if (index >= 0 && index < 100)
	{
		return values[index];
	}
	else
	{
		return dummy;
	}
}

int& Array::operator[](int index)
{
	if (index >= 0 && index < 100) 
	{
		return values[index];
	}
	else
	{
		return dummy;
	}
}
