// UnitTest_06_3_it.cpp
// Рева Максим
// Модульний тест для Lab_06_3_it.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_06_3_it_main
#include "../Lab_06_3_it.cpp"
#undef main

TEST_SUITE("UnitTest_06_3_it")
{
    TEST_CASE("Sum of squares non-template (int)")
    {
        int a[4] = { 1, 2, 3, 4 };
        // 1^2 + 2^2 + 3^2 + 4^2 = 1 + 4 + 9 + 16 = 30
        CHECK(SumSq(a, 4) == 30);
    }

    TEST_CASE("Sum of squares template (int & double)")
    {
        int a[4] = { 1, 2, 3, 4 };
        CHECK(SumSq<int>(a, 4) == 30);

        double b[3] = { 1.5, 2.0, -2.5 };
        // 1.5^2 + 2.0^2 + (-2.5)^2 = 2.25 + 4.0 + 6.25 = 12.5
        CHECK(SumSq<double>(b, 3) == doctest::Approx(12.5));
    }
}
