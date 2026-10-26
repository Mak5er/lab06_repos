// Lab_06_2_it.cpp
// Рева Максим
// Лабораторна робота № 6.2
// Опрацювання одновимірних масивів ітераційним способом
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

void SwapHalves(int* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = a[i];
        a[i] = a[i + n];
        a[i + n] = temp;
    }
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
