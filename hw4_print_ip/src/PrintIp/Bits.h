#pragma once

#include <stdint.h>

namespace hw4 {

template<typename T>
union Bits {
	T value;
	uint8_t bits[sizeof(T)];
};

}
