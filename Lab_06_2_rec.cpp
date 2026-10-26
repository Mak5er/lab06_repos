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

void Create(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i >= size)
        return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, size, Low, High, i + 1);
}

void Print(const int* a, const int size, int i = 0)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    Print(a, size, i + 1);
}

void SwapHalves(int* a, const int n, int i = 0)
{
    if (i >= n)
        return;
    int temp = a[i];
    a[i] = a[i + n];
    a[i + n] = temp;
    SwapHalves(a, n, i + 1);
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int n = 5;
    const int size = 2 * n;
    int a[size];
    const int Low = -10;
    const int High = 20;

    Create(a, size, Low, High);

    cout << "Original array (size = " << size << "):" << endl;
    Print(a, size);

    SwapHalves(a, n);

    cout << "Array after swapping halves:" << endl;
    Print(a, size);

    return 0;
}
