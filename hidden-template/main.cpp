#include <iostream>
#include "i-am-not-a-template.hpp"

int main()
{
	std::cout << "IAmNotATemplate::getBool(): " << IAmNotATemplate::getBool() << std::endl;
	std::cout << "IAmNotATemplate::setName(\"Test\"): " << std::endl;
	IAmNotATemplate::setName("Test");
	std::cout << "IAmNotATemplate::getName(): " << IAmNotATemplate::getName() << std::endl;
}
