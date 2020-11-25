#pragma once

#include "IpStorage.h"

#include <ostream>
#include <tuple>
#include <algorithm>

namespace hw1 {

enum class PrintDirection {
	ASC,
	DESC
};

template <typename IpStorageType>
class IpStoragePrinter {
	using Container = typename IpStorageType::Container;
	using Iterator = typename IpStorageType::Iterator;
	using Ip = typename IpStorageType::Ip;

public:
	IpStoragePrinter(std::ostream& out) :
	    _out(out) {}

	template<PrintDirection _printDirection = PrintDirection::ASC>
	void print(const Container& container) const {
		print<_printDirection>(std::begin(container), std::end(container));
	}

	template<PrintDirection _printDirection = PrintDirection::ASC>
	void print(const std::tuple<Iterator, Iterator>& boundaries) const {
		Iterator begin, end;
		std::tie(begin, end) = boundaries;
		print<_printDirection>(begin, end);
	}

	template<PrintDirection _printDirection>
	void print(Iterator begin, Iterator end) const {
	    switch(_printDirection) {
	        case PrintDirection::ASC :
                std::copy(begin, end, std::ostream_iterator<Ip>{ _out, "\n" });
                break;
	        case PrintDirection::DESC :
                std::reverse_copy(begin, end, std::ostream_iterator<Ip>{ _out, "\n" });
                break;
            default:
                _out << "[ERROR]: " << "unknown print direction.\n";
	    }
	}

private:
	std::ostream& _out;
};

}
