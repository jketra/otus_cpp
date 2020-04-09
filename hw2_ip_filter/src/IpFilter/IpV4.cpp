#include "IpV4.h"

#include <StringAddOns/StringFunctions.h>

#include <utility>
#include <assert.h>

namespace bl
{

IpV4::IpV4(Byte first, Byte second, Byte third, Byte forth) :
	_data{ first, second, third, forth }
{
}

IpV4::IpV4(const IpV4& other) :
	_data(other._data)
{
}

IpV4::IpV4(IpV4&& other) :
	_data(std::forward<std::array<Byte, BYTE_NUMBER>>(other._data))
{
}

IpV4::Byte& IpV4::byte(size_t index)
{
	assert(index < bytesNumber());
	
	return _data[index];
}

IpV4::Byte IpV4::byte(size_t index) const
{
	assert(index < bytesNumber());

	return _data[index];
}

bool IpV4::contains(Byte byte) const
{
	for (size_t index = 0; index < IpV4::bytesNumber() - 1; ++index) {
		if (_data[index] == byte) {
			return true;
		}
	}

	return false;
}

const IpV4& IpV4::operator=(const IpV4& other)
{
	_data = other._data;

	return *this;
}

bool IpV4::operator<(const IpV4& other) const
{
	return _data < other._data;
}

bool IpV4::operator>(const IpV4& other) const
{
	return _data > other._data;
}

std::ostream& operator<<(std::ostream& out, const IpV4& ip)
{
	size_t index = 0;
	
	while (index < IpV4::bytesNumber() - 1) {
		out << ip._data[index++] << '.';
	}

	out << ip._data[index];

	return out;
}

}
