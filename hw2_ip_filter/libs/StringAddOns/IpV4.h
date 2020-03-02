#pragma once

#include <cstddef>
#include <array>
#include <ostream>

namespace bl
{

class IpV4
{
	static constexpr size_t BYTE_NUMBER = 4u;

public:
	IpV4(int first = 0, int second = 0, int third = 0, int forth = 0);

	template<size_t _index, std::enable_if_t<(_index > 0 && _index <= BYTE_NUMBER), int> = 0>
	int byte() const;

	bool operator<(const IpV4& other);

	friend std::ostream& operator<<(std::ostream& out, const IpV4& ip);

private:
	std::array<int, BYTE_NUMBER> _data;
};

template<size_t _index, std::enable_if_t<(_index > 0 && _index <= IpV4::BYTE_NUMBER), int>>
int IpV4::byte() const
{
	return _data[_index - 1];
}

}
