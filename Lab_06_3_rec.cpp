// Lab_06_3_rec.cpp
// Рева Максим
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (рекурсивний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

// Спосіб 1: Звичайна рекурсивна функція формування масиву цілих чисел випадковими значеннями
void Create(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i >= size)
        return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

// Спосіб 2: Шаблон рекурсивної функції формування масиву довільного числового типу T
template <typename T>
void Create(T* a, const int size, const T Low, const T High, int i = 0)
{
    if (i >= size)
        return;
    a[i] = static_cast<T>(Low + (High - Low) * (rand() / static_cast<double>(RAND_MAX)));
    Create<T>(a, size, Low, High, i + 1);
}

// Рекурсивний шаблон функції для форматного виведення масиву
template <typename T>
void Print(const T* a, const int size, int i = 0)
{
    if (i >= size) // базовий випадок
    {
        cout << endl;
        return;
    }
    cout << setw(8) << setprecision(2) << a[i];
    Print<T>(a, size, i + 1);
}

// Спосіб 1: Звичайна рекурсивна функція обчислення суми квадратів для int
int SumSq(const int* a, const int size, int i = 0)
{
    if (i < size)
        return a[i] * a[i] + SumSq(a, size, i + 1); // квадрат поточного + рекурсивна сума хвоста
    else
        return 0; // базовий випадок: елементи закінчилися
}

// Спосіб 2: Шаблон рекурсивної функції для масиву довільного числового типу T
template <typename T>
T SumSq(const T* a, const int size, int i = 0)
{
    if (i < size)
        return a[i] * a[i] + SumSq<T>(a, size, i + 1);
    else
        return T(); // повернення нейтрального нульового значення для типу T
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));

    const int n = 6;
    int a[n];
    const int Low = -10;
    const int High = 10;

    // 1. Формування та виведення масиву int звичайною рекурсивною функцією
    Create(a, n, Low, High);
    cout << "Array a (int, non-template):" << endl;
    Print(a, n);

    // Виклик звичайної рекурсивної функції
    int s1 = SumSq(a, n);
    cout << "SumSq(a, n) [non-template] = " << s1 << endl;

    // 2. Формування та виведення масиву int шаблонною рекурсивною функцією
    int a2[n];
    Create<int>(a2, n, Low, High);
    cout << "\nArray a2 (int, template):" << endl;
    Print(a2, n);

    // Виклик шаблонної рекурсивної функції для int
    int s2 = SumSq<int>(a2, n);
    cout << "SumSq<int>(a2, n) [template] = " << s2 << endl;

    // 3. Формування та перевірка шаблонних рекурсивних функцій для double
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
