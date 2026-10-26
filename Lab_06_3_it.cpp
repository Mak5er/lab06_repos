// Lab_06_3_it.cpp
// Рева Максим
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (ітераційний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>

using namespace std;

// Звичайна функція для масиву цілих чисел
int SumSq(const int* a, const int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}

// Шаблон функції для масиву довільного числового типу
template <typename T>
T SumSq(const T* a, const int size)
{
    T s = T();
    for (int i = 0; i < size; i++)
        s += a[i] * a[i];
    return s;
}

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
    int a[n] = { 1, -2, 3, 4, -5, 6 };

    cout << "Array a (int):" << endl;
    Print(a, n);

    int s1 = SumSq(a, n);
    cout << "SumSq(a, n) [non-template] = " << s1 << endl;

    int s2 = SumSq<int>(a, n);
    cout << "SumSq<int>(a, n) [template] = " << s2 << endl;

    double b[n] = { 1.5, -2.0, 3.5, 4.0, -1.0, 2.5 };
    cout << "\nArray b (double):" << endl;
    Print(b, n);

    double s3 = SumSq<double>(b, n);
    cout << "SumSq<double>(b, n) [template] = " << s3 << endl;

    return 0;
}
