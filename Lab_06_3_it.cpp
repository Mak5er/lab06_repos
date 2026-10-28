// Lab_06_3_it.cpp
// Рева Максим
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (ітераційний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>

using namespace std;

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

// Шаблон функції для форматного виведення масиву будь-якого типу T
template <typename T>
void Print(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(8) << a[i];
    cout << endl;
}

int main()
{
    const int n = 6;
    int a[n] = { 1, -2, 3, 4, -5, 6 }; // тестовий цілочисельний масив

    cout << "Array a (int):" << endl;
    Print(a, n);

    // Виклик звичайної функції
    int s1 = SumSq(a, n);
    cout << "SumSq(a, n) [non-template] = " << s1 << endl;

    // Виклик шаблонної функції, спеціалізованої для int
    int s2 = SumSq<int>(a, n);
    cout << "SumSq<int>(a, n) [template] = " << s2 << endl;

    // Перевірка шаблонної функції на масиві дійсних чисел (double)
    double b[n] = { 1.5, -2.0, 3.5, 4.0, -1.0, 2.5 };
    cout << "\nArray b (double):" << endl;
    Print(b, n);

    double s3 = SumSq<double>(b, n);
    cout << "SumSq<double>(b, n) [template] = " << s3 << endl;

    return 0;
}
