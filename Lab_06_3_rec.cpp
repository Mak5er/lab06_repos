// Lab_06_3_rec.cpp
// Рева Максим
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (рекурсивний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>

using namespace std;

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

// Рекурсивний шаблон функції для форматного виведення масиву
template <typename T>
void Print(const T* a, const int size, int i = 0)
{
    if (i >= size) // базовий випадок
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
    int a[n] = { 1, -2, 3, 4, -5, 6 }; // тестовий масив цілих чисел

    cout << "Array a (int):" << endl;
    Print(a, n);

    // Виклик звичайної рекурсивної функції
    int s1 = SumSq(a, n);
    cout << "SumSq(a, n) [non-template] = " << s1 << endl;

    // Виклик шаблонної рекурсивної функції для int
    int s2 = SumSq<int>(a, n);
    cout << "SumSq<int>(a, n) [template] = " << s2 << endl;

    // Перевірка шаблонної рекурсивної функції для масиву double
    double b[n] = { 1.5, -2.0, 3.5, 4.0, -1.0, 2.5 };
    cout << "\nArray b (double):" << endl;
    Print(b, n);

    double s3 = SumSq<double>(b, n);
    cout << "SumSq<double>(b, n) [template] = " << s3 << endl;

    return 0;
}
