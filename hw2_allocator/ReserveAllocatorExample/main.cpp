#include <ReserveAllocator/ReserveAllocator.h>

#include <vector>
#include <map>

#include <exception>
#include <iostream>

int main(int, char const **)
{
	try {
	    using namespace hw2;
		std::cout << "Homework 2: Allocator" << std::endl;

		auto v = std::vector<int, ReserveAllocator<int>>{};
        v.reserve(5);
        for (int i = 0; i < 5; ++i) {
            v.emplace_back(i);
            std::cout << "---" << std::endl;
        }

        std::cout << "VECTOR" << std::endl;
        for (auto i : v) {
            std::cout << i << std::endl;
        }

        auto m = std::map<int, int, std::less<>, ReserveAllocator<std::pair<const int, int>>>{};
        for (int i = 0; i < 5; ++i) {
            m.emplace(i, i);
            std::cout << "---" << std::endl;
        }

        std::cout << "MAP" << std::endl;
        for (auto i : m) {
            std::cout << "{ " << i.first << " -> " << i.second << " }" << std::endl;
        }

        using hardType = std::array<int, 3>;
        auto h = std::map<int, hardType, std::less<>, ReserveAllocator<std::pair<const int, hardType>>>{};
        for (int i = 0; i < 5; ++i) {
            h.emplace(i, hardType{i + 1, i + 2, i + 3});
            std::cout << std::endl;
        }

        std::cout << "HARD MAP" << std::endl;
        for (auto i : h) {
            std::cout << i.first << " -> { " << i.second[0] << ", "
                << i.second[1] << ", " << i.second[2] << " }" << std::endl;
        }
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
