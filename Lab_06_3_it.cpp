// Lab_06_3_it.cpp
// Рева Максим
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (ітераційний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Спосіб 1: Звичайна ітераційна функція формування масиву цілих чисел випадковими значеннями
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Спосіб 2: Шаблон ітераційної функції формування масиву довільного числового типу T
template <typename T>
void Create(T* a, const int size, const T Low, const T High)
{
    for (int i = 0; i < size; i++)
        a[i] = static_cast<T>(Low + (High - Low) * (rand() / static_cast<double>(RAND_MAX)));
}

// Шаблон функції для форматного виведення масиву будь-якого типу T
template <typename T>
void Print(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << setprecision(2) << a[i];
    cout << endl;
}

// Спосіб 1: Звичайна ітераційна функція для масиву цілих чисел (int)
int SumSq(const int* a, const int size)
{
    int s = 0; // накопичувач суми квадратів
    for (int i = 0; i < size; i++)
        s += a[i] * a[i]; // додаємо квадрат поточного елемента
    return s;
}

// Спосіб 2: Шаблон ітераційної функції для масиву довільного числового типу T
template <typename T>
T SumSq(const T* a, const int size)
{
    T s = T(); // ініціалізація нульовим значенням для типу T (0 або 0.0)
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));

    const int n = 6;
    int a[n];
    const int Low = -10;
    const int High = 10;

    // 1. Формування та виведення масиву int звичайною функцією
    Create(a, n, Low, High);
    cout << "Array a (int, non-template):" << endl;
    Print(a, n);

    // Виклик звичайної функції обчислення суми квадратів
    int s1 = SumSq(a, n);
    cout << "SumSq(a, n) [non-template] = " << s1 << endl;

    // 2. Формування та виведення масиву int шаблонною функцією
    int a2[n];
    Create<int>(a2, n, Low, High);
    cout << "\nArray a2 (int, template):" << endl;
    Print(a2, n);

    // Виклик шаблонної функції, спеціалізованої для int
    int s2 = SumSq<int>(a2, n);
    cout << "SumSq<int>(a2, n) [template] = " << s2 << endl;

    // 3. Формування та перевірка шаблонних функцій на масиві double
    double b[n];
    const double dLow = -10.0;
    const double dHigh = 10.0;
    Create<double>(b, n, dLow, dHigh);
    cout << "\nArray b (double, template):" << endl;
    Print(b, n);

    double s3 = SumSq<double>(b, n);
    cout << "SumSq<double>(b, n) [template] = " << s3 << endl;

    return 0;
}
