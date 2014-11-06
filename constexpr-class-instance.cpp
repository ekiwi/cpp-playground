#include <iostream>
#include <stdint.h>


class
Color
{
public:
	static const Color White;
	static const Color white() { return Color(0xff,0xff,0xff); };
public:
	Color(uint8_t red, uint8_t green, uint8_t blue) :
		color(((static_cast<uint16_t>(red >> 3) << 11) |
				(static_cast<uint16_t>(green >> 2) << 5) |
				static_cast<uint16_t>(blue >> 3)))
	{
	}

public:
	uint16_t color;
};

const Color Color::White  = Color(0xff,0xff,0xff);


int main()
{
	std::cout << "Color::White::color: " << Color::White.color << std::endl;
}
