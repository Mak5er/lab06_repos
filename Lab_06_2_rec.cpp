// Lab_06_2_rec.cpp
// Рева Максим
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів рекурсивним способом
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Рекурсивне заповнення масиву випадковими числами у діапазоні [Low, High]
void Create(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i >= size) // базовий випадок: масив заповнено
        return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

// Рекурсивне форматне виведення елементів масиву
void Print(const int* a, const int size, int i = 0)
{
    if (i >= size) // базовий випадок: усі елементи виведено
    {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    Print(a, size, i + 1);
}

// Рекурсивний обмін першої та другої половин масиву (розміром 2n)
void SwapHalves(int* a, const int n, int i = 0)
{
    if (i >= n) // базовий випадок: дійшли до середини масиву
        return;

    // Обмін місцями симетричних елементів двох половин: a[i] та a[i + n]
    int temp = a[i];
    a[i] = a[i + n];
    a[i + n] = temp;

    SwapHalves(a, n, i + 1); // рекурсивний перехід до наступної пари елементів
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int n = 5;            // кількість елементів у кожній половині
    const int size = 2 * n;     // повний розмір вектора (2n = 10)
    int a[size];                // масив a
    const int Low = -10;        // мінімальне значення
    const int High = 20;        // максимальне значення

    // 1. Рекурсивне формування та виведення початкового вектора
    Create(a, size, Low, High);
    cout << "Original array (size = " << size << "):" << endl;
    Print(a, size);

    // 2. Рекурсивний обмін першої та другої половин
    SwapHalves(a, n);

    // 3. Виведення результату
    cout << "Array after swapping halves:" << endl;
    Print(a, size);

    return 0;
}
