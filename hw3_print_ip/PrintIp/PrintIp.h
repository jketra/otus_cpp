﻿#pragma once

#include "Bits.h"

#include <TypeTraits/TypeTraits.h>

#include <vector>
#include <tuple>
#include <string>

#include <type_traits>
#include <limits>

#include <iostream>

/// @defgroup homework_3 Print Ip Project.

/// @ingroup homework_3.
/// @brief The third homework (print ip).
namespace hw3 {

/// @addtogroup homework_3.
/// @{

/// Print integer value as ip (previously converted to bits).
/// @tparam T Integer type.
/// @param[in] ip The value to be converted and printed.
template<typename T, typename = std::enable_if_t<std::is_integral<T>::value>>
void printIp(T ip) {
    static const uint8_t bitShift = 8;
    Bits<T> mask;
    mask.value = std::numeric_limits<uint8_t>::max(); // 2^8 - 1;

    std::vector<uint8_t> result;
    result.reserve(sizeof(T));

    for (unsigned k = 0; k < sizeof(T); ++k) {
        T newValue = mask.value & ip;
        newValue = newValue >> (k * bitShift);
        result.emplace_back(static_cast<uint8_t>(newValue));
        mask.value = mask.value << bitShift;
    }

    for (auto it = result.rbegin();; std::cout << '.') {
        std::cout << static_cast<unsigned>(*it);

        if (++it == result.rend()) {
            break;
        }
    }

    std::cout << std::endl;
}

/// Print string value as ip.
/// @param[in] ip The value to be printed.
inline void printIp(const std::string& ip) {
    std::cout << ip << std::endl;
}

/// Print the container as ip (dot separated container contents).
/// @tparam T Container type.
/// @param[in] ip The container to be printed.
template<typename T, typename = hw_libs::sfinae::IsContainer<T>>
void printIp(const T& ip) {
    if (ip.empty()) {
        return;
    }

    for (auto it = ip.begin();; std::cout << '.') {
        std::cout << *it;

        ++it;
        if (it == ip.end()) {
            break;
        }
    }

    std::cout << std::endl;
}

/// Print the tuple.
/// @tparam Tuple Tuple type.
/// @tparam std::size_t... types of indexes.
/// @param[in] value Tuple to print.
/// @param[in] delimiter Separator between tuple values.
template<class Tuple, std::size_t... Indexes>
void print_tuple_impl(const Tuple& value, std::index_sequence<Indexes...>, const char* delimiter) {
    int tmp[]{0, (void(std::cout << (Indexes == 0 ? "" : delimiter) << std::get<Indexes>(value)), 0)...};
    (void)tmp;
}

/// Print the tuple as ip if the tuple's values types match.
/// @tparam T tuple's value type.
/// @tparam ...Args tuple's values types.
/// @param[in] ip Tuple to print as ip.
template<typename T, typename... Args, typename = hw_libs::sfinae::AreTypesSame<T, Args...>>
void printIp(const std::tuple<T, Args...>& ip) {
    print_tuple_impl(ip, std::index_sequence_for<T, Args...>{}, ".");
    std::cout << std::endl;
}

/// @}

}
