﻿#include <PrintIp/PrintIp.h>

#include <cstdint>
#include <string>
#include <vector>
#include <list>
#include <tuple>

int main(int, char const **)
{
	using namespace hw3;
	
	system("chcp 1251");

	// print integers
	printIp(char(-1));
	printIp(short(0));
	printIp(2130706433);
	printIp(8875824491850138409);

	// print string
	printIp("const char*"); // type conversion
	printIp(std::string{ "string" });

	// print vector
	printIp(std::vector<int>{ 19, 29, 40 });
	printIp(std::vector<int>{ 29, 29, 29, 40 });
	
	// print list
	printIp(std::list<std::string>{"list", "vector", "map"});

	// print tuple
	printIp(std::make_tuple(10, 15, 20, 75));
	printIp(std::make_tuple(10, 20));

 	return 0;
}