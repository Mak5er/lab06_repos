// UnitTest_06_2_rec.cpp
// Рева Максим
// Модульний тест для Lab_06_2_rec.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_06_2_rec_main
#include "../Lab_06_2_rec.cpp"
#undef main

TEST_SUITE("UnitTest_06_2_rec")
{
    TEST_CASE("Swap halves recursive: n = 4, size = 8")
    {
        const int n = 4;
        // Перша половина: {1, 2, 3, 4}, друга половина: {10, 20, 30, 40}
        int a[8] = { 1, 2, 3, 4, 10, 20, 30, 40 };

        SwapHalves(a, n, 0);

        // Перевірка після рекурсивного обміну половин
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
