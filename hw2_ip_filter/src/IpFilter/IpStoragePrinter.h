#pragma once

#include "IpStorage.h"

#include <ostream>
#include <tuple>

namespace bl {

enum class PrintDirection {
	ASC,
	DESC
};

class IpStoragePrinter {
	using Container = IpStorage::Container;
	using Iterator = IpStorage::Iterator;

public:
	IpStoragePrinter(std::ostream& out);

	template<PrintDirection printDirection_ = PrintDirection::ASC>
	void print(const Container& container) const {
		print<printDirection_>(std::begin(container), std::end(container));
	}

	template<PrintDirection printDirection_ = PrintDirection::ASC>
	void print(const std::tuple<Iterator, Iterator>& boundaries) const {
		Iterator begin, end;
		std::tie(begin, end) = boundaries;
		print<printDirection_>(begin, end);
	}

	template<PrintDirection printDirection_ = PrintDirection::ASC>
	void print(Iterator begin, Iterator end) const;

private:
	std::ostream& _out;
};

}
