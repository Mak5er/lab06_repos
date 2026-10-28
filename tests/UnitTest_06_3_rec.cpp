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
        // 1 + 4 + 9 + 16 = 30
        CHECK(SumSq(a, 4, 0) == 30);
    }

    TEST_CASE("Sum of squares template recursive (int & double)")
    {
        int a[4] = { 1, 2, 3, 4 };
        CHECK(SumSq<int>(a, 4, 0) == 30);

        double b[3] = { 1.5, 2.0, -2.5 };
        // 2.25 + 4.0 + 6.25 = 12.5
        CHECK(SumSq<double>(b, 3, 0) == doctest::Approx(12.5));
    }

    TEST_CASE("Create recursive within range")
    {
        int a[10];
        Create(a, 10, -5, 5);
        for (int i = 0; i < 10; i++)
        {
            CHECK(a[i] >= -5);
            CHECK(a[i] <= 5);
        }

        double b[10];
        Create<double>(b, 10, -3.0, 3.0);
        for (int i = 0; i < 10; i++)
        {
            CHECK(b[i] >= -3.0);
            CHECK(b[i] <= 3.0);
        }
    }
}
