#pragma once

#include <type_traits>

namespace fake_std17 {

template<class...> struct conjunction : std::true_type { };
template<class B1> struct conjunction<B1> : B1 { };
template<class B1, class... Bn>
struct conjunction<B1, Bn...> 
    : std::conditional_t<bool(B1::value), conjunction<Bn...>, B1> {};

template<class...> struct disjunction : std::false_type { };
template<class B1> struct disjunction<B1> : B1 { };
template<class B1, class... Bn>
struct disjunction<B1, Bn...> 
    : std::conditional_t<bool(B1::value), B1, disjunction<Bn...>>  {};

}

namespace sfinae {

template<typename Expected, typename Actual>
using CheckType = typename std::enable_if_t< std::is_same< std::remove_const_t<std::remove_reference_t<Actual>>, 
std::remove_const_t<std::remove_reference_t<Expected>> >::value >;

template<typename Expected, typename... Actual>
using CheckTypes = typename std::enable_if_t<fake_std17::conjunction<std::is_convertible<Actual, Expected>...>::value>;

}
