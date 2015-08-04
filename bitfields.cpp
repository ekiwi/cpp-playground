#include <iostream>
#include <stdint.h>

struct Fields
{
	unsigned int a : 4;
	signed   int b : 4;
	uint16_t     c : 4;
	int16_t      d : 4;
};

#define TEST(value) \
	value =  4; std::cout << #value " =  4; " #value ": " << value << std::endl; \
	value = 10; std::cout << #value " = 10; " #value ": " << value << std::endl; \
	value = -1; std::cout << #value " = -1; " #value ": " << value << std::endl; \
	value = 20; std::cout << #value " = 20; " #value ": " << value << std::endl << std::endl;

int main()
{
	std::cout << "sizeof(Fields): " << sizeof(Fields) << std::endl;
	Fields ff;

	std::cout << "unsigned int a : 4;" << std::endl;
	TEST(ff.a)

	std::cout << "signed   int b : 4;" << std::endl;
	TEST(ff.b)

	std::cout << "uint16_t     c : 4;" << std::endl;
	TEST(ff.c)

	std::cout << "int16_t      c : 4;" << std::endl;
	TEST(ff.d)
}