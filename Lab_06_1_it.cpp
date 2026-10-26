// Lab_06_1_it.cpp
// Рева Максим
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву ітераційним способом
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* t, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        t[i] = Low + rand() % (High - Low + 1);
}

void Print(const int* t, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << t[i];
    cout << endl;
}

bool Criterion(int value, int index)
{
    return (value > 0 && index % 4 != 0);
}

int Count(const int* t, const int size)
{
    int count = 0;
    for (int i = 0; i < size; i++)
    {
        if (Criterion(t[i], i))
            count++;
    }
    return count;
}

int Sum(const int* t, const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (Criterion(t[i], i))
            sum += t[i];
    }
    return sum;
}

void Replace(int* t, const int size)
{
    for (int i = 0; i < size; i++)
    {
        if (Criterion(t[i], i))
            t[i] = 0;
    }
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int size = 20;
    int t[size];
    const int Low = -14;
    const int High = 7;

    Create(t, size, Low, High);

    cout << "Original array:" << endl;
    Print(t, size);

    int count = Count(t, size);
    int sum = Sum(t, size);

    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    Replace(t, size);

    cout << "Modified array:" << endl;
    Print(t, size);

    return 0;
}
