#include "StringAddOns/StringFunctions.h"

#include <IpFilter/IpStoragePrinter.h>
#include <IpFilter/IpStorage.h>
#include <IpFilter/IpV4.h>

#include <vector>
#include <string>
#include <iostream>

#define JDEBUG
#ifdef  JDEBUG
	#include <fstream>
	#include <sstream>
#endif

int main(int argc, char const *argv[])
{
	(void)argc;
	(void)argv;

#ifndef JDEBUG
	auto inStream = std::cin;
#else
	std::stringstream inStream;
	#ifdef WIN32
		std::string filePath{ "D:\\study\\OTUS\\HW2\\input_part.txt" };
	#else
		std::string filePath{ "/home/user/code/test_data/input_part.txt" };
	#endif

	std::ifstream file(filePath);

	if (file) {
		inStream << file.rdbuf();
		file.close();
	}
	else {
		std::cout << "Could not open file " << filePath << std::endl;
	}
#endif
	
	try {
		constexpr auto DESC = bl::PrintDirection::DESC;

		bl::IpStorage ipStorage;
		bl::IpStoragePrinter printer(std::cout);

		for (std::string line; std::getline(inStream, line);)
		{
			std::vector<std::string> v = bl::split(line, '\t');
			if ((!v.empty()) && (!v.front().empty())) {
				auto result = ipStorage.add(v.front());
				if (!result) {
					std::cout << result;
				}
			}
		}

		// ВЫВОД В СТАНДАРТНЫЙ ПОТОК:

		// 1. Полный список адресов после обратной сортировки.
		printer.print<DESC>(ipStorage.getAllIps());

		std::cout << "\n=====================================================\n";

		// 2. Список адресов, первый байт которых равен 1. Порядок сортировки не меняется.
		printer.print<DESC>(ipStorage.filteredByFirstBytes(1));

		std::cout << "\n=====================================================\n";

		// 3. Список адресов, первый байт которых равен 46, а второй 70. Порядок сортировки не меняется.
		printer.print<DESC>(ipStorage.filteredByFirstBytes(46, 70));

		std::cout << "\n=====================================================\n";

		// 4. Список адресов, любой байт которых равен 46. Порядок сортировки не меняется.
		printer.print<DESC>(ipStorage.getIpsContainsByte(46));
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
