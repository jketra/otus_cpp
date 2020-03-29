#include "IpStorage.h"

#include <StringAddOns/StringFunctions.h>

#include <utility>
#include <stdexcept>
#include <algorithm>
#include <sstream>

namespace bl
{

IpStorage::IpStorage(std::ostream& out) :
	_ipRestrictions{ { 0, 0, 0, 0 }, { 255, 255, 255, 255 } },
	_print(std::function<void(const IpV4&)>([&out](const IpV4& ip){ out << ip << std::endl; })),
	_out(out)
{
}

OperationResult IpStorage::add(IpV4&& ip)
{
	if (validateIp(ip)) {
		_storage.insert(std::forward<IpV4>(ip));
		return OperationResult::Success();
	}

	return std::move(OperationResult::Fail("Invalid IpV4 [") << _ipRestrictions.min <<
		"-" << _ipRestrictions.max << "]: " << ip);
}

OperationResult IpStorage::add(const std::string& ipStr)
{
	auto bytes = bl::split(ipStr, '.');

	if (bytes.size() == 4u) {
		try {
			return add(IpV4{ std::stoi(bytes[0]), std::stoi(bytes[1]), std::stoi(bytes[2]), std::stoi(bytes[3]) });
		}
		catch (std::invalid_argument const &e) {
			return std::move(OperationResult::Fail("Bad input : ") << e.what() << ": "<< ipStr);
		}
		catch (std::out_of_range const &e) {
			return  std::move(OperationResult::Fail("Integer overflow: ") << e.what() << ": " << ipStr);
		}
	}

	return  OperationResult::Fail("Invalid input");
}

bool IpStorage::validateIp(const IpV4& ip) const
{
	for (unsigned i = 0; i < 4u; ++i) {
		if (ip.byte(i) < _ipRestrictions.min.byte(i) || _ipRestrictions.max.byte(i) < ip.byte(i)) {
 			return false;
		}
	}

	return true;
}

}
