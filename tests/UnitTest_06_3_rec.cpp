// UnitTest_06_3_rec.cpp
// Рева Максим
// Модульний тест для Lab_06_3_rec.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_06_3_rec_main
#include "../Lab_06_3_rec.cpp"
#undef main

TEST_SUITE("UnitTest_06_3_rec")
{
    TEST_CASE("Sum of squares non-template recursive (int)")
    {
        int a[4] = { 1, 2, 3, 4 };
        CHECK(SumSq(a, 4, 0) == 30);
    }

    TEST_CASE("Sum of squares template recursive (int & double)")
    {
        int a[4] = { 1, 2, 3, 4 };
        CHECK(SumSq<int>(a, 4, 0) == 30);

        double b[3] = { 1.5, 2.0, -2.5 };
        CHECK(SumSq<double>(b, 3, 0) == doctest::Approx(12.5));
    }
}
