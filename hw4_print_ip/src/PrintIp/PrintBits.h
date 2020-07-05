#pragma once

#include "Bits.h"

#include <iostream>

namespace hw4 {

/// @ingroup homework_4
/// Print input value as his bits.
/// @tparam T Input value type.
/// @param[in] value Value to print as bits.
template<typename T>
void printBits(T value) {
	Bits<T> b;
	b.value = value;
	
	for (int j = sizeof(T) - 1; j >= 0; j--) {
		for (int i = 128; i; i >>= 1)
			if (i & b.bits[j]) std::cout << "1";
			else std::cout << "0";
		std::cout << ' ';
	}
	std::cout << std::endl;
}

}