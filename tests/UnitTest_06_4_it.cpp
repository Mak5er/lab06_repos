// UnitTest_06_4_it.cpp
// Рева Максим
// Модульний тест для Lab_06_4_it.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_06_4_it_main
#include "../Lab_06_4_it.cpp"
#undef main

TEST_SUITE("UnitTest_06_4_it")
{
    TEST_CASE("Product of elements with even indices")
    {
        // indices 0, 2, 4 -> 2 * 3 * 4 = 24
        int a[5] = { 2, -1, 3, 5, 4 };
        CHECK(ProductEven(a, 5) == 24);
    }

    TEST_CASE("Sum between first and last zero")
    {
        // indices: 0: 1, 1: 0, 2: 5, 3: -2, 4: 0, 5: 7
        // first zero at 1, last zero at 4.
        // elements between: a[2]=5, a[3]=-2. Sum = 3.
        int a[6] = { 1, 0, 5, -2, 0, 7 };
        CHECK(FirstZeroIndex(a, 6) == 1);
        CHECK(LastZeroIndex(a, 6) == 4);
        CHECK(SumBetweenZeros(a, 6) == 3);

        // Less than 2 zeros
        int b[4] = { 1, 0, 2, 3 };
        CHECK(SumBetweenZeros(b, 4) == 0);
    }

    TEST_CASE("Transform: stable partition non-negative then negative")
    {
        int a[6] = { -3, 0, 5, -1, -4, 2 };
        // non-negative: 0, 5, 2
        // negative: -3, -1, -4
        // expected: 0, 5, 2, -3, -1, -4
        Transform(a, 6);
        CHECK(a[0] == 0);
        CHECK(a[1] == 5);
        CHECK(a[2] == 2);
        CHECK(a[3] == -3);
        CHECK(a[4] == -1);
        CHECK(a[5] == -4);
    }
}
