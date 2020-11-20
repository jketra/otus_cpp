#include <ReserveAllocator/ReserveAllocator.h>

#include <vector>

#include <exception>
#include <iostream>

int main(int, char const **)
{
	try {
		std::cout << "Homework 2: Allocator" << std::endl;

        auto v = std::vector<int, hw2::ReserveAllocator<int>>{};
        v.reserve(5);
        for (size_t i = 0; i < 5; ++i) {
            v.emplace_back(i);
            std::cout << "---" << std::endl;
        }

        for (auto i : v) {
            std::cout << i << std::endl;
        }

        //    auto m = std::map<int, int, std::less<int>, logging_allocator<std::pair<const int, int>>>{};
        //    for (size_t i = 0; i < 5; ++i) {
        //        m.emplace(i, i);
        //        std::cout << "---" << std::endl;
        //    }

        //    auto h = std::map<int, hard, std::less<int>, logging_allocator<std::pair<const int, hard>>>{};
        //    for (size_t i = 0; i < 5; ++i) {
        //        h.emplace(i, hard(i, i));
        //        std::cout << std::endl;
        //    }
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
