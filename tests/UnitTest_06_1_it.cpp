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
        CHECK(Criterion(5, 1) == true);   // додатне, індекс 1 не кратний 4 -> true
        CHECK(Criterion(5, 4) == false);  // додатне, але індекс 4 кратний 4 -> false
        CHECK(Criterion(-3, 1) == false); // від'ємне -> false
        CHECK(Criterion(0, 2) == false);  // нуль не є додатним -> false
    }

    TEST_CASE("Count, Sum, Replace on sample array")
    {
        // Контрольний масив з 8 елементів:
        // підходять індекси 1 (3), 3 (7), 5 (2), 7 (1) -> кількість = 4, сума = 13
        int arr[8] = { 5, 3, -4, 7, 6, 2, 0, 1 };

        CHECK(Count(arr, 8) == 4);
        CHECK(Sum(arr, 8) == 13);

        // Перевірка заміни відібраних елементів нулями
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
