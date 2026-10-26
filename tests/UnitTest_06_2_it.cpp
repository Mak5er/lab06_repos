// UnitTest_06_2_it.cpp
// Рева Максим
// Модульний тест для Lab_06_2_it.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_06_2_it_main
#include "../Lab_06_2_it.cpp"
#undef main

TEST_SUITE("UnitTest_06_2_it")
{
    TEST_CASE("Swap halves iterative: n = 4, size = 8")
    {
        const int n = 4;
        int a[8] = { 1, 2, 3, 4, 10, 20, 30, 40 };

        SwapHalves(a, n);

        CHECK(a[0] == 10);
        CHECK(a[1] == 20);
        CHECK(a[2] == 30);
        CHECK(a[3] == 40);
        CHECK(a[4] == 1);
        CHECK(a[5] == 2);
        CHECK(a[6] == 3);
        CHECK(a[7] == 4);
    }
}
