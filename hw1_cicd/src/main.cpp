#include "version.h"

#include <iostream>

int main (int, char **)
{
	std::cout << "Hello, World!" << std::endl;
	std::cout << "Version: " << hw1::getProjectVersion() << std::endl;

	return 0;
}
