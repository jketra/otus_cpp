#include <iostream>

#include "version.h"

int main (int, char **)
{
    std::cout << "Hello, World!" << std::endl;
	std::cout << "Version: " << info::getProjectVersion() << std::endl;

    return 0;
}
