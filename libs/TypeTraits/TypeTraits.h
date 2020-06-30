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

template<typename ...>
using void_t = void;

template<typename T, typename = void>
struct is_container : std::false_type {};

template<typename T>
struct is_container<T, void_t<typename std::remove_reference_t<T>::iterator>> : std::true_type {};

template<typename Expected, typename Actual>
using CheckType = typename std::enable_if_t< std::is_same< std::remove_const_t<std::remove_reference_t<Actual>>, 
std::remove_const_t<std::remove_reference_t<Expected>> >::value >;

template<typename Expected, typename... Actual>
using CheckTypes = typename std::enable_if_t<fake_std17::conjunction<std::is_convertible<Actual, Expected>...>::value>;

template<typename T>
using IsContainer = typename std::enable_if_t<sfinae::is_container<std::remove_reference_t<T>>::value>;

template<typename Expected, typename... Actual>
using AreTypesSame = typename std::enable_if_t<fake_std17::conjunction<std::is_same<Actual, Expected>...>::value>;
}
