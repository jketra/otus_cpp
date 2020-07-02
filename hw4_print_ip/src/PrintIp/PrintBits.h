#pragma once

#include "Bits.h"

#include <iostream>

namespace hw4 {

template<typename T>
void printBits(T a) {
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