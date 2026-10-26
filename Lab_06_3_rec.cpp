// Lab_06_3_rec.cpp
// Рева Максим
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (рекурсивний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>

using namespace std;

// Звичайна рекурсивна функція для масиву цілих чисел
int SumSq(const int* a, const int size, int i = 0)
{
    if (i < size)
        return a[i] * a[i] + SumSq(a, size, i + 1);
    else
        return 0;
}

// Шаблон рекурсивної функції для масиву довільного числового типу
template <typename T>
T SumSq(const T* a, const int size, int i = 0)
{
    if (i < size)
        return a[i] * a[i] + SumSq<T>(a, size, i + 1);
    else
        return T();
}

template <typename T>
void Print(const T* a, const int size, int i = 0)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(8) << a[i];
    Print<T>(a, size, i + 1);
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
