//
// Created by user on 04.07.2022.
//

#ifndef LAMBDAS_HEADER_HPP
#define LAMBDAS_HEADER_HPP

#include <iostream>
#include <cstdlib>
#include <vector>
#include <functional>
#include <exception>
#include <typeinfo>
#include <string>
#include <sstream>

template <typename T>
using FilterFuncs = std::vector<std::function<T()>>;

FilterFuncs<int> filterVecInts = {};
FilterFuncs<double> filterVecDoubles = {};


class UnexpectedType: public std::exception {
public:
    [[nodiscard]] const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
        return "Unexpected type was given!";
    }
};

//template <typename T1, typename T2>
//class NotMatchingTypes: public std::exception {
//public:
//    NotMatchingTypes(T1 val1_, T2 val2_) : val1(val1_), val2(val2_) {}
//
//    [[nodiscard]] const char* what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override {
//        std::ostringstream return_string{};
//        return_string << "The types of divisor and given value do not match (" << typeid(val1).name() << " differs from"
//            << typeid(val2).name() << ")\n";
//        return return_string.str().c_str();
//    }
//
//private:
//    T1 val1;
//    T2 val2;
//};

template <typename T>
class Widget {
public:
    explicit Widget(T divisor_);
    template <typename U>
    void addFilter(U value);
private:
    T divisor;
};

template <typename T>
template <typename U>
void Widget<T>::addFilter(U value) {
    // If U is type of an integral then we are going to add this lambda to filterVecInts
    if (std::is_integral_v<std::remove_reference_t<U>>) {
        filterVecInts.push_back([divisor = divisor, value = value](){ return static_cast<int>(value) / divisor; });
    }
    // Else if U is type of a floating point (float, double, long double) than add this lambda to filterVecDoubles
    else if (std::is_floating_point_v<std::remove_reference_t<U>>) {
        filterVecDoubles.push_back([divisor = divisor, value = value](){ return static_cast<double>(value) / divisor; });
    }
    else {
        throw UnexpectedType();
    }
}

template<typename T>
Widget<T>::Widget(T divisor_) {
    if (std::is_integral_v<std::remove_reference_t<T>> || std::is_floating_point_v<std::remove_reference_t<T>>) {
        divisor = divisor_;
    }
    else {
        throw UnexpectedType();
    }
}


#endif //LAMBDAS_HEADER_HPP
