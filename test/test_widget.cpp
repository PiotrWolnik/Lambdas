//
// Created by user on 04.07.2022.
//

#include "gtest/gtest.h"
#include "header.hpp"

TEST(WidgetTest, testingAddFilterFunc) {
    // Case 1 - addFilter with value of type int
    Widget<int> obj1{10};
    obj1.addFilter(10);
    EXPECT_EQ(filterVecInts[0](), 1);
    filterVecInts.clear();

    // Case 2 - addFilter with value of type double
    Widget<double> obj2{12.5};
    obj2.addFilter(25.0);
    EXPECT_EQ(filterVecDoubles[0](), 2.0);
    filterVecDoubles.clear();

    // Case 3 - UnexpectedType error is thrown when divisor is not an integral or a floating point
    EXPECT_THROW(Widget<std::string> obj3{"Hello"}, UnexpectedType);

    // Case 4 - UnexpectedType error is thrown when type of parameter is not an integral or a floating point
//    Widget<int> obj4{20};
//    EXPECT_THROW(obj4.addFilter(""), UnexpectedType);
}