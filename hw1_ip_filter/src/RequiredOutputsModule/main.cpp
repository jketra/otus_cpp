#include <StringAddOns/StringFunctions.h>

#include <IpFilter/IpV4.h>
#include <IpFilter/IpStorage.h>
#include <IpFilter/IpStoragePrinter.h>

#include <vector>
#include <string>
#include <iostream>

int main(int, char const **) {
	try {
		using namespace hw1;
		constexpr auto DESC = PrintDirection::DESC;

		IpStorage<IpV4> ipStorage;
		IpStoragePrinter<IpStorage<IpV4>> printer(std::cout);

		for (std::string line; std::getline(std::cin, line);) {
			std::vector<std::string> v = hw_libs::split(line, '\t');
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

		// 2. Список адресов, первый байт которых равен 1. Порядок сортировки не меняется.
		printer.print<DESC>(ipStorage.filteredByFirstBytes(1));

		// 3. Список адресов, первый байт которых равен 46, а второй 70. Порядок сортировки не меняется.
		printer.print<DESC>(ipStorage.filteredByFirstBytes(46, 70));

		// 4. Список адресов, любой байт которых равен 46. Порядок сортировки не меняется.
		printer.print<DESC>(ipStorage.getIpsContainsByte(46));
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
