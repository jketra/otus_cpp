#pragma once

#include <stdint.h>

namespace hw4 {

/// Union for converting values to bits.
/// @tparam T Type of converting value.
template<typename T>
union Bits {
	T value;					///< Main value.
	uint8_t bits[sizeof(T)];	///< Representation of the main value in bit form.
};

}
