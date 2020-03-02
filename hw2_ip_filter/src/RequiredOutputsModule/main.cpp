#include "IpFilter/IpV4.h"

#include <iostream>

int main (int, char **)
{
	bl::IpV4 ip1;
	bl::IpV4 ip2{10, 10, 10, 10};

	std::cout << ip1 << " < " << ip2 << " is " << (ip1 < ip2) << std::endl;

	std::cout << ip1.byte<3>() << '.' << ip1.byte<4>() << std::endl;

	return 0;
}
