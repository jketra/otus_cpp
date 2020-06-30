#pragma once

#include <iostream>
#include <vector>
#include <iterator>
#include <type_traits>
#include <string>
#include <utility>

#include <TypeTraits/TypeTraits.h>

namespace hw4 {

template<typename T, typename = std::enable_if_t<std::is_integral_v<T>>>
void printIp(T ip) {
	
	Bits<T> mask;
	mask.value = std::numeric_limits<uint8_t>::max(); // 2^8 - 1;

	std::vector<uint8_t> result;
	result.reserve(sizeof(T));

	for (int k = 0; k < sizeof(T); ++k) {
		T newValue = mask.value & ip;
		newValue = newValue >> (k * 8);
		result.emplace_back(static_cast<uint8_t>(newValue));
		mask.value = mask.value << 8;
	}

	for (auto it = result.rbegin();;) {
		std::cout << static_cast<uint32_t>(*it);
		++it;
		
		if (it == result.rend()) {
			break;
		}

		std::cout << '.';
	}

	std::cout << std::endl;
}

void printIp(const std::string& ip);

template<typename T, typename = sfinae::IsContainer<T>>
void printIp(const T& ip) {
	if (ip.empty()) {
		return;
	}

	for (auto it = ip.begin();;) {
		std::cout << *it;
		++it;

		if (it == ip.end()) {
			break;
		}

		std::cout << '.';
	}

	std::cout << std::endl;
}

template<class Tuple, std::size_t... Indexes>
void print_tuple_impl(const Tuple& t, std::index_sequence<Indexes...>, const char* delimeter) {
	int tmp[]{0, (void(std::cout << (Indexes == 0 ? "" : delimeter) << std::get<Indexes>(t)), 0)...};
	(void)tmp;
}

template<typename T, typename... Args, typename = sfinae::AreTypesSame<T, Args...>>
void printIp(const std::tuple<T, Args...>& ip) {
	print_tuple_impl(ip, std::index_sequence_for<T, Args...>{}, ".");
	std::cout << std::endl;
}

template<typename T>
union Bits {
	T value;
	uint8_t bits[sizeof(T)];
};

template<typename T>
void show_bits(T a) {
	Bits<T> b;
	b.value = a;
	
	for (int j = sizeof(T) - 1; j >= 0; j--) {
		for (int i = 128; i; i >>= 1)
			if (i & b.bits[j]) std::cout << "1";
			else std::cout << "0";
		std::cout << ' ';
	}
	std::cout << std::endl;
}

}
