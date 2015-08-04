#include <iostream>
#include <stdint.h>
#include <bitset>

#pragma GCC diagnostic ignored "-Woverflow"

enum class Color : uint8_t
{
	Red = 0,
	Green = 1,
	Blue = 2,
	Black = 100,
};

inline std::ostream& operator<<(std::ostream & os, const Color & color) {
	switch(color) {
	case Color::Red:
		os << "Red"; break;
	case Color::Green:
		os << "Green"; break;
	case Color::Blue:
		os << "Blue"; break;
	}
	return os;
}

struct __attribute__ ((__packed__)) Fields
{
	unsigned int a : 4;
	signed   int b : 4;
	uint16_t     c : 4;
	int16_t      d : 4;
	Color        color : 2;
};

struct __attribute__ ((__packed__)) Read3BitsStruct
{
	unsigned int other : 5;
	unsigned int value : 3;
};

inline std::ostream& operator<<(std::ostream & os, const Fields & ff) {
	os  << "(" << ff.a << ", " << ff.b << ", "
	    << ff.c << ", " << ff.d << ", " << ff.color << ")" << std::endl;
	return os;
}

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

	std::cout << "signed int b : 4;" << std::endl;
	TEST(ff.b)

	std::cout << "uint16_t c : 4;" << std::endl;
	TEST(ff.c)

	std::cout << "int16_t c : 4;" << std::endl;
	TEST(ff.d)

	std::cout << "Color color : 2;" << std::endl;
	ff.color = Color::Green;
	std::cout << "ff.color: " << ff.color << std::endl;
	ff.color = Color::Black;
	std::cout << "ff.color: " << ff.color << std::endl << std::endl;

	std::cout << "bitfield to data mapping" << std::endl;
	uint8_t data[3] = {3<<4,3,2};
	Fields* f0 = reinterpret_cast<Fields*>(data);
	std::cout << "f0: " << *f0 << std::endl;

	uint8_t data1 = 0b11010000;
	Read3BitsStruct* f1 = reinterpret_cast<Read3BitsStruct*>(&data1);
	std::cout << "data1:     " << std::bitset<8>(data1)     << std::endl;
	std::cout << "f1->value: " << std::bitset<3>(f1->value) << std::endl;
	std::cout << "f1->other: " << std::bitset<5>(f1->other) << std::endl;
}
