#include <iostream>
#include <stdint.h>

// See als:
// http://aszt.inf.elte.hu/~gsd/halado_cpp/ch06s10.html

class
Dog
{
public:
	static void
	bark()
	{
		std::cout << "bark bark..."<< std::endl;
	}
};

class
Cat
{
public:
	static void
	miau()
	{
		std::cout << "miau miau..."<< std::endl;
	}
};


template <class T>
class CanBark
{
public:
	~CanBark()
	{
		T::bark();
	}
};

template class CanBark<Dog>; // dogs can bark thus this should succeed
template class CanBark<Cat>; // should fail during compile time


int main()
{
	std::cout << "nothing to see here ...."<< std::endl;
}
