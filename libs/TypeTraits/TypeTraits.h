#pragma once

#include <type_traits>

namespace fake_std17 {

template<class...> struct conjunction : std::true_type { };
template<class B1> struct conjunction<B1> : B1 { };
template<class B1, class... Bn>
struct conjunction<B1, Bn...> 
    : std::conditional_t<bool(B1::value), conjunction<Bn...>, B1> {};

}

namespace sfinae {

template<typename Expected, typename... Actual>
using CheckTypes = typename std::enable_if_t<fake_std17::conjunction<std::is_convertible<Actual, Expected>...>::value>;

//template<typename... Args, typename = CheckTypes<IpV4::Byte, Args...>>
}