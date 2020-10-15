#pragma once

#include <StringAddOns/StringFunctions.h>

#include <IpFilter/IpStoragePrinter.h>
#include <IpFilter/IpStorage.h>
#include <IpFilter/IpV4.h>

#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include <gtest/gtest.h>

namespace test {

class IpStorageTests : public ::testing::Test {
// protected for GTest
protected:
	IpStorageTests() :
		_printer(_actOutput)
	{}
	
	void setTestsIps() {
		_inputIps.emplace_back( 79, 46, 201, 157 );
		_inputIps.emplace_back( 66, 169, 196, 128 );
		_inputIps.emplace_back( 46, 70, 225, 39 );
		_inputIps.emplace_back( 46, 70, 147, 26 );
		_inputIps.emplace_back( 197, 48, 89, 171 );
		_inputIps.emplace_back( 46, 70, 147, 26 );
		_inputIps.emplace_back( 104, 222, 164, 236 );
		_inputIps.emplace_back( 1, 29, 168, 70 );
		_inputIps.emplace_back( 1, 158, 70, 188 );

		for (const auto& ip : _inputIps) {
			_ipStorage.add(ip);
		}
	}

	std::stringstream _actOutput;
	std::stringstream _expOutput;

	hw1::IpStorage<hw1::IpV4> _ipStorage;

	const static auto DESC{ hw1::PrintDirection::DESC };
	hw1::IpStoragePrinter<hw1::IpStorage<hw1::IpV4>> _printer;

	std::vector<hw1::IpV4> _inputIps;
};

TEST_F(IpStorageTests, AddValidIpV4) {
	auto result = _ipStorage.add(hw1::IpV4{ 79, 46, 201, 157 });
	ASSERT_TRUE(result) << result;

	result = _ipStorage.add(hw1::IpV4{ 0, 0, 0, 0 });
	ASSERT_TRUE(result) << result;

	result = _ipStorage.add(hw1::IpV4{ 255, 255, 255, 255 });
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
	auto result = _ipStorage.add(hw1::IpV4{ 20, -1, 0, 0 });
	std::cout << "-- " << result;
	ASSERT_FALSE(result);

	result = _ipStorage.add(hw1::IpV4{ 0, 0, 256, 0 });
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

	std::vector<hw1::IpV4> expIps;

	std::copy_if(_inputIps.begin(), _inputIps.end(), std::back_inserter(expIps),
		[&firstByte, &secondByte](const hw1::IpV4& ip) { return ip.byte(0) == firstByte && ip.byte(1) == secondByte; });
	
	std::sort(expIps.begin(), expIps.end(), std::less<>());
	for (const auto& ip : expIps) {
		_expOutput << ip << '\n';
	}

	std::sort(expIps.begin(), expIps.end(), std::greater<>());
	for (const auto& ip : expIps) {
		_expOutput << ip << '\n';
	}

	auto resultIps = _ipStorage.filteredByFirstBytes(firstByte, secondByte);
	_printer.print(resultIps);
	_printer.print<DESC>(resultIps);

	EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

TEST_F(IpStorageTests, PrintIpsContainsByte) {
	_inputIps.emplace_back( 1, 1, 1, 1 );
	_inputIps.emplace_back( 46, 1, 1, 1 );
	_inputIps.emplace_back( 1, 46, 1, 1 );
	_inputIps.emplace_back( 1, 1, 46, 1 );
	_inputIps.emplace_back( 1, 1, 1, 46 );
	_inputIps.emplace_back( 46, 46, 46, 46 );

	for (const auto& ip : _inputIps) {
		_ipStorage.add(ip);
	}

	int byteValue = 46;

	std::vector<hw1::IpV4> expIps;

	std::copy_if(_inputIps.begin(), _inputIps.end(), std::back_inserter(expIps),
		[&byteValue](const hw1::IpV4& ip) { 
			return ip.byte(0) == byteValue || ip.byte(1) == byteValue || 
			ip.byte(2) == byteValue || ip.byte(3) == byteValue; 
		});

	std::sort(expIps.begin(), expIps.end(), std::less<>());
	for (const auto& ip : expIps) {
		_expOutput << ip << '\n';
	}

	std::sort(expIps.begin(), expIps.end(), std::greater<>());
	for (const auto& ip : expIps) {
		_expOutput << ip << '\n';
	}

	auto resultIps = _ipStorage.getIpsContainsByte(byteValue);
	
	_printer.print(resultIps);
	_printer.print<DESC>(resultIps);

	EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

TEST_F(IpStorageTests, ControlDataset) {
	hw1::IpStorage<hw1::IpV4> ipStorage;

	std::ifstream inStream("test_data/control_dataset.tsv", std::ifstream::in);

	ASSERT_TRUE(inStream.is_open()) << "File control_dataset.tsv not found";

	for (std::string line; std::getline(inStream, line);) {
		std::vector<std::string> v = hw_libs::split(line, '\t');
		if ((!v.empty()) && (!v.front().empty())) {
			auto result = ipStorage.add(v.front());
			if (!result) {
				std::cout << result;
			}
		}
	}
	
	inStream.close();

	// Вывод  в _actOutput:
	//
	// 1. Полный список адресов после обратной сортировки.
	_printer.print<DESC>(ipStorage.getAllIps());
	
	// 2. Список адресов, первый байт которых равен 1. Порядок сортировки не меняется.
	_printer.print<DESC>(ipStorage.filteredByFirstBytes(1));

	// 3. Список адресов, первый байт которых равен 46, а второй 70. Порядок сортировки не меняется.
	_printer.print<DESC>(ipStorage.filteredByFirstBytes(46, 70));

	// 4. Список адресов, любой байт которых равен 46. Порядок сортировки не меняется.
	_printer.print<DESC>(ipStorage.getIpsContainsByte(46));
	
	inStream.open("test_data/expected_ips.txt", std::ifstream::in);
	ASSERT_TRUE(inStream.is_open()) << "File expected_ips.txt not found";

	for (std::string line; std::getline(inStream, line);) {
		_expOutput << line << std::endl;
	}

	EXPECT_EQ(_actOutput.str(), _expOutput.str());
	
	inStream.close();
}

}
