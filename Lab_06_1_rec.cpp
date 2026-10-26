// Lab_06_1_rec.cpp
// Рева Максим
// Лабораторна робота № 6.1
// Пошук елементів одновимірного масиву рекурсивним способом
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* t, const int size, const int Low, const int High, int i = 0)
{
    if (i >= size)
        return;
    t[i] = Low + rand() % (High - Low + 1);
    Create(t, size, Low, High, i + 1);
}

void Print(const int* t, const int size, int i = 0)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(4) << t[i];
    Print(t, size, i + 1);
}

bool Criterion(int value, int index)
{
    return (value > 0 && index % 4 != 0);
}

int Count(const int* t, const int size, int i = 0)
{
    if (i >= size)
        return 0;
    int current = Criterion(t[i], i) ? 1 : 0;
    return current + Count(t, size, i + 1);
}

int Sum(const int* t, const int size, int i = 0)
{
    if (i >= size)
        return 0;
    int current = Criterion(t[i], i) ? t[i] : 0;
    return current + Sum(t, size, i + 1);
}

void Replace(int* t, const int size, int i = 0)
{
    if (i >= size)
        return;
    if (Criterion(t[i], i))
        t[i] = 0;
    Replace(t, size, i + 1);
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
