#include "version.h"

#include <iostream>

int main (int, char **)
{
    std::cout << "Hello, World!" << std::endl;
	std::cout << "Version: " << info::getProjectVersion() << std::endl;

    return 0;
}
