#include "IpStorage.h"

#include <StringAddOns/StringFunctions.h>

#include <utility>
#include <stdexcept>
#include <algorithm>
#include <sstream>

namespace bl
{

IpStorage::IpStorage() :
	_ipRestrictions{ { 0, 0, 0, 0 }, { 255, 255, 255, 255 } }
{
}

OperationResult IpStorage::add(const std::string& ipStr)
{
	auto bytes = bl::split(ipStr, '.');

	if (bytes.size() == 4u) {
		try {
			return add(IpV4{ std::stoi(bytes[0]), std::stoi(bytes[1]), std::stoi(bytes[2]), std::stoi(bytes[3]) });
		}
		catch (std::invalid_argument const &e) {
			return std::move(OperationResult::Fail("Bad input: ") << std::string(e.what()) << ": "<< ipStr);
		}
		catch (std::out_of_range const &e) {
			return  std::move(OperationResult::Fail("Integer overflow : ") << e.what() << ": " << ipStr);
		}
	}

	return std::move(OperationResult::Fail("Invalid input: ") << ipStr);
}

const IpStorage::Container& IpStorage::getAllIps() const {
	return _storage;
}

IpStorage::Container IpStorage::getIpsContainsByte(IpV4::Byte byte) const {
	Container result;
	std::vector<IpV4> vet;
	std::copy_if(std::begin(_storage), std::end(_storage), std::inserter(result, std::begin(result)),
		[&byte](const IpV4& ip) { return ip.contains(byte); });

	return std::move(result);
}

void IpStorage::clear()
{
	_storage.clear();
}

bool IpStorage::empty() const
{
	return _storage.empty();
}

bool IpStorage::validateIp(const IpV4& ip) const
{
	for (unsigned i = 0; i < IpV4::bytesNumber(); ++i) {
		if (ip.byte(i) < _ipRestrictions.min.byte(i) || _ipRestrictions.max.byte(i) < ip.byte(i)) {
 			return false;
		}
	}

	return true;
}

}
