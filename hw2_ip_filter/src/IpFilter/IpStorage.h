#pragma once

#include "ProcessDirection.h"
#include "ForEach.h"
#include "IpV4.h"

#include <OperationResult/OperationResult.h>

#include <vector>
#include <set>
#include <ostream>
#include <functional>
#include <iterator>

namespace bl
{

class IpStorage
{
	struct IpBoundaries {
		IpV4 min;
		IpV4 max;
	};

public:
	using Iterator = typename std::multiset<IpV4>::iterator;

	IpStorage(std::ostream& out);

	OperationResult add(IpV4&& ip);
	OperationResult add(const std::string& ipStr);

	template<ProcessDirection processingDirection_ = ProcessDirection::ASC>
	void printAll() const {
		print<processingDirection_>(std::begin(_storage), std::end(_storage));
	}

	template<ProcessDirection processingDirection_ = ProcessDirection::ASC>
	void printIpsContainsByte(IpV4::Byte byte) const {
		ForEach<Iterator> printIfContains([this, &byte](const IpV4& ip) {
				if (ip.contains(byte)) {
					_out << ip << '\n';
				}
			});
		printIfContains.process<processingDirection_>(std::begin(_storage), std::end(_storage));
	}

	template<ProcessDirection outputDirection_ = ProcessDirection::ASC, typename ...Bytes>
	void printFilteredByFirstBytes(Bytes ...bytes) {
		IpBoundaries ipBoundaries = _ipRestrictions;
		formFilteringBoundaries(ipBoundaries, 0, bytes...);

		auto begin = std::lower_bound(std::begin(_storage), std::end(_storage), ipBoundaries.min);
		auto end = std::upper_bound(std::begin(_storage), std::end(_storage), ipBoundaries.max);

		print<outputDirection_>(begin, end);
	}

private:
	bool validateIp(const IpV4& ip) const;

	void formFilteringBoundaries(IpBoundaries& range, size_t byteIndex) {
	}

	template<ProcessDirection processingDirection_>
	void print(Iterator begin, Iterator end) const {
		_print.process<processingDirection_>(begin, end);
	}

	template<typename T, typename ...Bytes>
	void formFilteringBoundaries(IpBoundaries& ipBoundaries, size_t byteIndex, const T& value, Bytes ...bytes) {
		ipBoundaries.min.byte(byteIndex) = value;
		ipBoundaries.max.byte(byteIndex) = value;

		formFilteringBoundaries(ipBoundaries, byteIndex + 1, bytes...);
	}

	std::multiset<IpV4> _storage;
	const IpBoundaries _ipRestrictions;
	ForEach<Iterator> _print;

	std::ostream& _out;
};

}
