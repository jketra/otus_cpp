#pragma once

#include <TypeTraits/TypeTraits.h>

#include <array>
#include <iostream>
#include <utility>
#include <cassert>

namespace hw1 {

template<size_t _bytesNumber>
class GenericIp;

template<size_t _bytesNumber>
std::ostream& operator<<(std::ostream& out, const GenericIp<_bytesNumber>& ip);

template<size_t _bytesNumber>
class GenericIp {
public:
	using Byte = int;
private:
	using Data = std::array<Byte, _bytesNumber>;

public:
	GenericIp() = default;

	template<typename... Bytes, typename = hw_libs::sfinae::AreTypesSame<Byte, Bytes...>,
			 typename = std::enable_if_t<sizeof...(Bytes) == _bytesNumber>>
	explicit GenericIp(Bytes... bytes) noexcept :
		_data{ bytes... } {
	}

	GenericIp(const GenericIp& other) noexcept :
		_data(other._data) {
	}
	
	GenericIp(GenericIp&& other) noexcept :
		_data(std::move(other._data)) {
	}

	Byte& byte(size_t index) {
		assert(index < bytesNumber());
		return _data[index];
	}

	Byte byte(size_t index) const {
		assert(index < bytesNumber());
		return _data[index];
	}

	bool contains(Byte byte) const {
		for (size_t index = 0; index < _bytesNumber; ++index) {
			if (_data[index] == byte)
				return true;
		}
		return false;
	}

	GenericIp& operator=(const GenericIp& other) {
		_data = other._data;
		return *this;
	}

	bool operator<(const GenericIp& other) const {
		return _data < other._data;
	}

	bool operator>(const GenericIp& other) const {
		return _data > other._data;
	}

	bool operator==(const GenericIp& other) const {
		return _data == other._data;
	}

	static constexpr size_t bytesNumber() {
		return _bytesNumber;
	}

	friend std::ostream& operator<< <>(std::ostream& out, const GenericIp& ip);

private:
	Data _data;
};

template<size_t _bytesNumber>
std::ostream& operator<<(std::ostream& out, const GenericIp<_bytesNumber>& ip) {
	size_t index = 0;

	while (index < _bytesNumber - 1) {
		out << ip._data[index++] << '.';
	}

	out << ip._data[index];

	return out;
}

}