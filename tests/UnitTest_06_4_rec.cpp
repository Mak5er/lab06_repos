// UnitTest_06_4_rec.cpp
// Рева Максим
// Модульний тест для Lab_06_4_rec.cpp

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#define main lab_06_4_rec_main
#include "../Lab_06_4_rec.cpp"
#undef main

TEST_SUITE("UnitTest_06_4_rec")
{
    TEST_CASE("Product of elements with even indices recursive")
    {
        // Парні індекси: 0 (2), 2 (3), 4 (4) -> 2 * 3 * 4 = 24
        int a[5] = { 2, -1, 3, 5, 4 };
        CHECK(ProductEven(a, 5, 0) == 24);
    }

    TEST_CASE("Sum between first and last zero recursive")
    {
        // Перший нуль на індексі 1, останній на індексі 4 -> між ними: 5 + (-2) = 3
        int a[6] = { 1, 0, 5, -2, 0, 7 };
        CHECK(FirstZeroIndex(a, 6, 0) == 1);
        CHECK(LastZeroIndex(a, 5) == 4);
        CHECK(SumBetweenZeros(a, 6) == 3);

        // Менше двох нулів -> сума = 0
        int b[4] = { 1, 0, 2, 3 };
        CHECK(SumBetweenZeros(b, 4) == 0);
    }

    TEST_CASE("Transform recursive: stable partition non-negative then negative")
    {
        int a[6] = { -3, 0, 5, -1, -4, 2 };
        // Очікуємо: спочатку {0, 5, 2}, потім {-3, -1, -4}
        Transform(a, 6);
        CHECK(a[0] == 0);
        CHECK(a[1] == 5);
        CHECK(a[2] == 2);
        CHECK(a[3] == -3);
        CHECK(a[4] == -1);
        CHECK(a[5] == -4);
    }
}
