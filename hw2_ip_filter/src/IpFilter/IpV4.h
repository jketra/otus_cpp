#pragma once

#include <cstddef>
#include <array>
#include <string>
#include <ostream>

namespace bl
{

class IpV4
{
	static constexpr size_t BYTE_NUMBER = 4u;
public:
	using Byte = int;

	IpV4(Byte first = 0, Byte second = 0, Byte third = 0, Byte forth = 0);
	IpV4(const IpV4& other);
	IpV4(IpV4&& other);

	template<size_t _index, std::enable_if_t<(_index > 0 && _index <= BYTE_NUMBER), int> = 0>
	Byte byte() const;

	Byte& byte(size_t index);
	Byte byte(size_t index) const;

	bool contains(Byte byte) const;

	bool operator<(const IpV4& other) const;

	static constexpr size_t bytesNumber();

	friend std::ostream& operator<<(std::ostream& out, const IpV4& ip);

private:
	std::array<Byte, BYTE_NUMBER> _data;
};

template<size_t _index, std::enable_if_t<(_index > 0 && _index <= IpV4::BYTE_NUMBER), int>>
IpV4::Byte IpV4::byte() const
{
	return _data[_index - 1];
}

}
