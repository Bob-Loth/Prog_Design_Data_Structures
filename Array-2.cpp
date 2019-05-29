#ifndef ARRAY
#define ARRAY
class Array
{
public:
  inline Array();
  inline ~Array();
  inline int capacity() const;
  inline int operator[](int) const; //getter
  inline int& operator[](int);   //setter
private:
  int values[100];
  int dummy;
};


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

int Array::capacity() const
{
	return 100;
}

int Array::operator[](int index) const
{
	if (index < 0 || index >= 100)
	{
    return dummy;
	}
	return values[index];
	
}

int& Array::operator[](int index)
{
  if (index < 0 || index >= 100)
  {
    return dummy;
  }
  return values[index];
}
#endif