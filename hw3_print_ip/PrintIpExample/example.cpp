#include "../PrintIp/PrintIp.h"

#include <cstdint>
#include <string>
#include <vector>
#include <list>
#include <tuple>

int main(int, char const **)
{
    using namespace hw3;

    // print integers
    printIp(char(-1));
    printIp(short(0));
    printIp(2130706433);
    printIp(8875824491850138409);

    // print string
    printIp("const char*"); // type conversion
    printIp(std::string{ "string" });

    // print vector
    printIp(std::vector<std::string>{ "vector0", "vector1", "vector2" });
    printIp(std::vector<int>{ 29, 29, 29, 40 });

    // print list
    printIp(std::list<std::string>{"list0", "list1", "list2"});

    // print tuple
    printIp(std::make_tuple(std::string{"tuple0"}, std::string{"tuple1"}));
    printIp(std::make_tuple(10, 15, 20, 75));

    return 0;
}
