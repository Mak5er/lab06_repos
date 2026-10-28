// Lab_06_3_rec.cpp
// Рева Максим
// Лабораторна робота № 6.3
// Опрацювання одновимірних масивів за допомогою звичайних функцій та шаблонів (рекурсивний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>

using namespace std;

// Прототипи рекурсивних функцій
int SumSq(const int* a, const int size, int i = 0);

template <typename T>
T SumSq(const T* a, const int size, int i = 0);

template <typename T>
void Print(const T* a, const int size, int i = 0);

int main()
{
    const int n = 6;
    int a[n] = { 1, -2, 3, 4, -5, 6 };              // тестовий масив цілих чисел
    double b[n] = { 1.5, -2.0, 3.5, 4.0, -1.0, 2.5 }; // тестовий масив дійсних чисел

    cout << "=========================================================================" << endl;
    cout << " Лабораторна робота № 6.3 (рекурсивний спосіб) | Варіант 23" << endl;
    cout << " Завдання: обчислення суми квадратів елементів масиву чисел" << endl;
    cout << "=========================================================================" << endl;

    cout << " Масив a (int):    ";
    Print(a, n);

    cout << " Масив b (double): ";
    Print(b, n);
    cout << "-------------------------------------------------------------------------" << endl;

    // 1. Виклик звичайної рекурсивної функції
    int s1 = SumSq(a, n);

    // 2. Виклик шаблонної рекурсивної функції для int
    int s2 = SumSq<int>(a, n);

    // 3. Виклик шаблонної рекурсивної функції для double
    double s3 = SumSq<double>(b, n);

    // Виведення зведеної таблиці результатів
    cout << "\n+---------------------------------------------------+--------------+" << endl;
    cout << "| Виклик функції                                    |   Результат  |" << endl;
    cout << "+---------------------------------------------------+--------------+" << endl;
    cout << "| SumSq(a, n)         [звичайна функція, int]       | " << setw(12) << s1 << " |" << endl;
    cout << "| SumSq<int>(a, n)    [шаблон функції, int]         | " << setw(12) << s2 << " |" << endl;
    cout << "| SumSq<double>(b, n) [шаблон функції, double]      | " << setw(12) << fixed << setprecision(2) << s3 << " |" << endl;
    cout << "+---------------------------------------------------+--------------+" << endl;

    return 0;
}

// Спосіб 1: Звичайна рекурсивна функція обчислення суми квадратів для int
int SumSq(const int* a, const int size, int i)
{
    if (i < size)
        return a[i] * a[i] + SumSq(a, size, i + 1); // квадрат поточного + рекурсивна сума хвоста
    else
        return 0; // базовий випадок: елементи закінчилися
}

// Спосіб 2: Шаблон рекурсивної функції для масиву довільного числового типу T
template <typename T>
T SumSq(const T* a, const int size, int i)
{
    if (i < size)
        return a[i] * a[i] + SumSq<T>(a, size, i + 1);
    else
        return T(); // повернення нейтрального нульового значення для типу T
}

// Рекурсивний шаблон функції для форматного виведення масиву
template <typename T>
void Print(const T* a, const int size, int i)
{
    if (i >= size) // базовий випадок
    {
        cout << endl;
        return;
    }
    cout << setw(8) << a[i];
    Print<T>(a, size, i + 1);
}
