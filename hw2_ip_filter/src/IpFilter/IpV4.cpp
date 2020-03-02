#pragma once

#include "IpV4.h"

namespace bl
{

IpV4::IpV4(int first, int second, int third, int forth) :
	_data{ first, second, third, forth }
{
}

bool IpV4::operator<(const IpV4& other)
{
	return _data < other._data;
}

std::ostream& operator<<(std::ostream& out, const IpV4& ip)
{
	size_t index = 0;
	
	while (index < IpV4::BYTE_NUMBER - 1) {
		out << ip._data[index++] << '.';
	}

	out << ip._data[index];

	return out;
}

}
