#pragma once

#include "IpFilter/IpStoragePrinter.h"
#include "IpFilter/IpStorage.h"
#include "IpFilter/IpV4.h"

#include <sstream>
#include <vector>
#include <string>

#include <gtest/gtest.h>

namespace test {

class IpStorageTests : public ::testing::Test {
// protected for GTest
protected:
	IpStorageTests() :
		_ipStorage(),
		_printer(_actOutput)
	{}
	
	void setTestsIps() {
		_inputIps.emplace_back(bl::IpV4{ 79, 46, 201, 157 });
		_inputIps.emplace_back(bl::IpV4{ 66, 169, 196, 128 });
		_inputIps.emplace_back(bl::IpV4{ 46, 70, 225, 39 });
		_inputIps.emplace_back(bl::IpV4{ 46, 70, 147, 26 });
		_inputIps.emplace_back(bl::IpV4{ 197, 48, 89, 171 });
		_inputIps.emplace_back(bl::IpV4{ 46, 70, 147, 26 });
		_inputIps.emplace_back(bl::IpV4{ 104, 222, 164, 236 });
		_inputIps.emplace_back(bl::IpV4{ 1, 29, 168, 70 });
		_inputIps.emplace_back(bl::IpV4{ 1, 158, 70, 188 });

		for (const auto& ip : _inputIps) {
			_ipStorage.add(ip);
		}
	}

	std::stringstream _actOutput;
	std::stringstream _expOutput;

	bl::IpStorage _ipStorage;

	const static auto ASC { bl::PrintDirection::ASC };
	const static auto DESC{ bl::PrintDirection::DESC };
	bl::IpStoragePrinter _printer;

	std::vector<bl::IpV4> _inputIps;
};

TEST_F(IpStorageTests, AddValidIpV4) {
	auto result = _ipStorage.add(bl::IpV4{ 79, 46, 201, 157 });
	ASSERT_TRUE(result) << result;

	result = _ipStorage.add(bl::IpV4{ 0, 0, 0, 0 });
	ASSERT_TRUE(result) << result;

	result = _ipStorage.add(bl::IpV4{ 255, 255, 255, 255 });
	ASSERT_TRUE(result) << result;

	_expOutput << "0.0.0.0\n" << "79.46.201.157\n" << "255.255.255.255\n"
		<< "255.255.255.255\n" << "79.46.201.157\n" << "0.0.0.0\n";

	auto allIps = _ipStorage.getAllIps();
	_printer.print(allIps);
	_printer.print<DESC>(allIps);

	EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

TEST_F(IpStorageTests, AddValidString) {
	auto result = _ipStorage.add("79.46.201.157");
	ASSERT_TRUE(result) << result;

	result = _ipStorage.add("0.0.0.0");
	ASSERT_TRUE(result) << result;

	result = _ipStorage.add("255.255.255.255");
	ASSERT_TRUE(result) << result;

	_expOutput << "0.0.0.0\n" << "79.46.201.157\n" << "255.255.255.255\n";

	_printer.print(_ipStorage.getAllIps());

	EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

TEST_F(IpStorageTests, AddInvalidIpV4) {
	auto result = _ipStorage.add(bl::IpV4{ 20, -1, 0, 0 });
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	result = _ipStorage.add(bl::IpV4{ 0, 0, 256, 0 });
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	ASSERT_TRUE(_ipStorage.empty());
}

TEST_F(IpStorageTests, AddInvalidString) {
	auto result = _ipStorage.add("0.-1.4.60");
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	result = _ipStorage.add("255.200.256.60");
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	result = _ipStorage.add("5.200,10.3");
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	result = _ipStorage.add("5.200.10.a");
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	result = _ipStorage.add("5.200.10.11.12");
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	result = _ipStorage.add("5.200.");
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	ASSERT_TRUE(_ipStorage.empty());
}

TEST_F(IpStorageTests, PrintFilteredByFirstBytes) {
	setTestsIps();
	
	int firstByte = 46;
	int secondByte = 70;

	std::vector<bl::IpV4> expIps;

	std::copy_if(_inputIps.begin(), _inputIps.end(), std::back_inserter(expIps),
		[&firstByte, &secondByte](const bl::IpV4& ip) { return ip.byte(0) == firstByte && ip.byte(1) == secondByte; });
	
	std::sort(expIps.begin(), expIps.end(), std::less<bl::IpV4>());
	for (const auto& ip : expIps) {
		_expOutput << ip << '\n';
	}

	std::sort(expIps.begin(), expIps.end(), std::greater<bl::IpV4>());
	for (const auto& ip : expIps) {
		_expOutput << ip << '\n';
	}

	auto resultIps = _ipStorage.filteredByFirstBytes(firstByte, secondByte);
	_printer.print(resultIps);
	_printer.print<DESC>(resultIps);

	EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

TEST_F(IpStorageTests, PrintIpsContainsByte) {
	setTestsIps();

	int byteValue = 46;

	std::vector<bl::IpV4> expIps;

	std::copy_if(_inputIps.begin(), _inputIps.end(), std::back_inserter(expIps),
		[&byteValue](const bl::IpV4& ip) { 
			return ip.byte(0) == byteValue || ip.byte(1) == byteValue || 
			ip.byte(2) == byteValue || ip.byte(3) == byteValue; 
		});

	std::sort(expIps.begin(), expIps.end(), std::less<bl::IpV4>());
	for (const auto& ip : expIps) {
		_expOutput << ip << '\n';
	}

	std::sort(expIps.begin(), expIps.end(), std::greater<bl::IpV4>());
	for (const auto& ip : expIps) {
		_expOutput << ip << '\n';
	}

	auto resultIps = _ipStorage.getIpsContainsByte(byteValue);
	
	_printer.print(resultIps);
	_printer.print<DESC>(resultIps);

	EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

}
