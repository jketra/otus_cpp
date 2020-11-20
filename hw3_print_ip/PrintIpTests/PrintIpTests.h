#pragma once

#include <PrintIp/PrintIp.h>

#include <sstream>
#include <vector>
#include <list>
#include <tuple>
#include <string>

#include <gtest/gtest.h>

namespace test {

/// Tests for homework 3.
class PrintIpTests : public ::testing::Test {
// protected for GTest
protected:
    PrintIpTests() :
        // save standard buffer.
        _coutbuf(std::cout.rdbuf()) {
        // redirect std::cout to _actOutput.
        std::cout.rdbuf(_actOutput.rdbuf());
    }

    ~PrintIpTests() override {
        // reset to standard output
        std::cout.rdbuf(_coutbuf);
    }

    std::streambuf* _coutbuf;        ///< Saved standard std::cout buffer.

    std::stringstream _actOutput;    ///< Actual output.
    std::stringstream _expOutput;    ///< Expected output.
};

/// Test for integer input parameter.
TEST_F(PrintIpTests, IntegerInput) {
    hw3::printIp(char(-1));
    hw3::printIp(short(0));
    hw3::printIp(2130706433);
    hw3::printIp(8875824491850138409);

    _expOutput << "255" << std::endl;
    _expOutput << "0.0" << std::endl;
    _expOutput << "127.0.0.1" << std::endl;
    _expOutput << "123.45.67.89.101.112.131.41" << std::endl;

    EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

/// Test for string as input parameter.
TEST_F(PrintIpTests, StringInput) {
    hw3::printIp("42.42.42.42");
    hw3::printIp("const char*");
    hw3::printIp(std::string{ "string" });

    _expOutput << "42.42.42.42" << std::endl;
    _expOutput << "const char*" << std::endl;
    _expOutput << "string" << std::endl;

    EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

/// Test for container as input parameter (vector, list).
TEST_F(PrintIpTests, ContainerInput) {
    hw3::printIp(std::vector<int>{});
    hw3::printIp(std::vector<int>{ 19 });
    hw3::printIp(std::vector<int>{ 29, 29, 29, 40 });
    hw3::printIp(std::list<std::string>{"list", "vector", "map"});

    _expOutput << "19" << std::endl;
    _expOutput << "29.29.29.40" << std::endl;
    _expOutput << "list.vector.map" << std::endl;

    EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

/// Test for tuple as input parameter.
TEST_F(PrintIpTests, TupleInput) {
    hw3::printIp(std::make_tuple(0));
    hw3::printIp(std::make_tuple(10, 15, 20, 75));
    hw3::printIp(std::make_tuple(10, 20));

    _expOutput << "0" << std::endl;
    _expOutput << "10.15.20.75" << std::endl;
    _expOutput << "10.20" << std::endl;

    EXPECT_EQ(_actOutput.str(), _expOutput.str());
}

}
