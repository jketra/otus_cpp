﻿#pragma once

#include "IpV4.h"

#include <OperationResult/OperationResult.h>
#include <TypeTraits/TypeTraits.h>

#include <set>
#include <ostream>
#include <iterator>
#include <tuple>
#include <algorithm>

namespace bl
{

class IpStorage
{
	using Byte = IpV4::Byte;
	
	struct IpBoundaries {
		IpV4 min;
		IpV4 max;
	};

public:
	using Container = std::multiset<IpV4>;
	using Iterator  = Container::iterator;
	
	IpStorage();

	OperationResult add(const IpV4& ip);
	OperationResult add(IpV4&& ip);
	OperationResult add(const std::string& ipStr);

	const Container& getAllIps() const;
	Container getIpsContainsByte(IpV4::Byte byte) const;

	void clear();
	bool empty() const;

	template<typename... Args, typename = sfinae::CheckTypes<IpV4::Byte, Args...>>
	std::tuple<Iterator, Iterator> filteredByFirstBytes(IpV4::Byte head, Args ...tail) {
		static_assert(sizeof...(tail) < IpV4::bytesNumber(), "The number of input bytes mustn't exceed 4");

		std::array<IpV4::Byte, sizeof...(tail) + 1u> filteringBytes{ head, tail... };
		
		IpBoundaries ipBoundaries = _ipRestrictions;
		for (unsigned i = 0; i < filteringBytes.size(); ++i) {
			ipBoundaries.min.byte(i) = filteringBytes[i];
			ipBoundaries.max.byte(i) = filteringBytes[i];
		}

		auto begin = std::lower_bound(std::begin(_storage), std::end(_storage), ipBoundaries.min);
		auto end = std::upper_bound(std::begin(_storage), std::end(_storage), ipBoundaries.max);

		return std::make_tuple(begin, end);
	}

private:
	bool validateIp(const IpV4& ip) const;

	Container _storage;
	const IpBoundaries _ipRestrictions;
};

}
