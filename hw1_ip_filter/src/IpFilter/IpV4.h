﻿#pragma once

#include <cstddef>
#include <array>
#include <string>
#include <ostream>

namespace hw1 {

class IpV4 {
	static constexpr size_t _bytesNumber = 4u;
public:
	using Byte = int;

	IpV4(Byte first = 0, Byte second = 0, Byte third = 0, Byte forth = 0);
	IpV4(const IpV4& other);
	IpV4(IpV4&& other);

	Byte& byte(size_t index);
	Byte byte(size_t index) const;

	bool contains(Byte byte) const;

	const IpV4& operator=(const IpV4& other);
	bool operator<(const IpV4& other) const;
	bool operator>(const IpV4& other) const;

	friend std::ostream& operator<<(std::ostream& out, const IpV4& ip);

	static constexpr size_t bytesNumber() {
		return _bytesNumber;
	}

private:
	std::array<Byte, _bytesNumber> _data;
};

}
