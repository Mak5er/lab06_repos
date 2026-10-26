// UnitTest_06_1_it.cpp
// Рева Максим
// Модульний тест для Lab_06_1_it.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_06_1_it_main
#include "../Lab_06_1_it.cpp"
#undef main

TEST_SUITE("UnitTest_06_1_it")
{
    TEST_CASE("Criterion check")
    {
        CHECK(Criterion(5, 1) == true);   // positive, index 1 not mult 4
        CHECK(Criterion(5, 4) == false);  // positive, but index 4 mult 4
        CHECK(Criterion(-3, 1) == false); // negative
        CHECK(Criterion(0, 2) == false);  // zero
    }

    TEST_CASE("Count, Sum, Replace on sample array")
    {
        // 8 elements:
        // index 0: 5 (mult 4 -> false)
        // index 1: 3 (positive, not mult 4 -> true)
        // index 2: -4 (false)
        // index 3: 7 (positive, not mult 4 -> true)
        // index 4: 6 (mult 4 -> false)
        // index 5: 2 (positive, not mult 4 -> true)
        // index 6: 0 (false)
        // index 7: 1 (positive, not mult 4 -> true)
        int arr[8] = { 5, 3, -4, 7, 6, 2, 0, 1 };
        // matches: index 1 (3), index 3 (7), index 5 (2), index 7 (1)
        // count = 4, sum = 3 + 7 + 2 + 1 = 13

        CHECK(Count(arr, 8) == 4);
        CHECK(Sum(arr, 8) == 13);

        Replace(arr, 8);
        CHECK(arr[0] == 5);
        CHECK(arr[1] == 0);
        CHECK(arr[2] == -4);
        CHECK(arr[3] == 0);
        CHECK(arr[4] == 6);
        CHECK(arr[5] == 0);
        CHECK(arr[6] == 0);
        CHECK(arr[7] == 0);
    }
}
