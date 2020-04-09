#include "IpStoragePrinter.h"

namespace bl {

IpStoragePrinter::IpStoragePrinter(std::ostream& out) : _out(out) {}

template<>
void IpStoragePrinter::print<PrintDirection::ASC>(Iterator begin, Iterator end) const {
	std::copy(begin, end, std::ostream_iterator<IpV4>{ _out, "\n" });
}

template<>
void IpStoragePrinter::print<PrintDirection::DESC>(Iterator begin, Iterator end) const {
	std::reverse_copy(begin, end, std::ostream_iterator<IpV4>{ _out, "\n" });
}

}
