#include "version.h"

#include <iostream>

int main (int, char **)
{
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Version: " << hw0::getProjectVersion() << std::endl;

	return 0;
}
