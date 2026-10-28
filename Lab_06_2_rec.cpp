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

// Прототипи рекурсивних функцій
void Create(int* a, const int size, const int Low, const int High, int i = 0);
void Print(const int* a, const int size, int i = 0);
void PrintIndices(const int size, int i = 0);
void SwapHalves(int* a, const int n, int i = 0);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int n = 5;            // кількість елементів у кожній половині
    const int size = 2 * n;     // повний розмір вектора (2n = 10)
    int a[size];                // масив a
    const int Low = -10;        // мінімальне значення
    const int High = 20;        // максимальне значення

    // 1. Рекурсивне формування початкового вектора
    Create(a, size, Low, High);

    cout << "=====================================================================" << endl;
    cout << " Лабораторна робота № 6.2 (рекурсивний спосіб) | Варіант 23" << endl;
    cout << " Завдання: обмін місцями першої та другої половин вектора a[2n]" << endl;
    cout << " Параметри: n = " << n << ", загальний розмір 2n = " << size << endl;
    cout << "=====================================================================" << endl;

    cout << " Індекси i:           ";
    PrintIndices(size);
    cout << "---------------------------------------------------------------------" << endl;

    // 2. Виведення початкового масиву
    cout << " Початковий масив a:  ";
    Print(a, size);

    // 3. Рекурсивний обмін першої та другої половин
    SwapHalves(a, n);

    // 4. Виведення модифікованого масиву
    cout << " Після обміну половин:";
    Print(a, size);
    cout << "=====================================================================" << endl;

    return 0;
}

// Рекурсивне заповнення масиву випадковими числами у діапазоні [Low, High]
void Create(int* a, const int size, const int Low, const int High, int i)
{
    if (i >= size) // базовий випадок: масив заповнено
        return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

// Рекурсивне виведення рядка індексів
void PrintIndices(const int size, int i)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(4) << i;
    PrintIndices(size, i + 1);
}

// Рекурсивне форматне виведення елементів масиву
void Print(const int* a, const int size, int i)
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
void SwapHalves(int* a, const int n, int i)
{
    if (i >= n) // базовий випадок: дійшли до середини масиву
        return;

    // Обмін місцями симетричних елементів двох половин: a[i] та a[i + n]
    int temp = a[i];
    a[i] = a[i + n];
    a[i + n] = temp;

    SwapHalves(a, n, i + 1); // рекурсивний перехід до наступної пари елементів
}
