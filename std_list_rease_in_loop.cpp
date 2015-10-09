#include <list>
#include <stdint.h>
#include <iostream>


int main()
{
	std::list<int32_t> values { 0,1,2,3,4,5,6 };

	for(const auto& value : values) {
		std::cout << value << ", ";
	}
	std::cout << std::endl;

	for(auto it = values.begin(); it != values.end();) {
		if((*it) % 2 == 0) {
			std::cout << "Going to remove: " << (*it) << std::endl;
			it = values.erase(it);
		} else {
			++it;
		}
	}

	for(const auto& value : values) {
		std::cout << value << ", ";
	}
	std::cout << std::endl;


	return 0;
}
