#pragma once

#include "Boundaries.h"
#include "IpV4.h"

namespace hw1 {

template <typename T>
struct Restrictions;

template <>
struct Restrictions<IpV4> {
	static const Boundaries<IpV4> boundaries;
};

}
