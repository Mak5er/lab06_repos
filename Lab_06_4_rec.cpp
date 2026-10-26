// Lab_06_4_rec.cpp
// Рева Максим
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів (рекурсивний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int n, const int Low, const int High, int i = 0)
{
    if (i >= n)
        return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, n, Low, High, i + 1);
}

void Print(const int* a, const int n, int i = 0)
{
    if (i >= n)
    {
        cout << endl;
        return;
    }
    cout << setw(5) << a[i];
    Print(a, n, i + 1);
}

long long ProductEven(const int* a, const int n, int i = 0)
{
    if (n <= 0)
        return 0;
    if (i >= n)
        return 1;
    return a[i] * ProductEven(a, n, i + 2);
}

int FirstZeroIndex(const int* a, const int n, int i = 0)
{
    if (i >= n)
        return -1;
    if (a[i] == 0)
        return i;
    return FirstZeroIndex(a, n, i + 1);
}

int LastZeroIndex(const int* a, const int i)
{
    if (i < 0)
        return -1;
    if (a[i] == 0)
        return i;
    return LastZeroIndex(a, i - 1);
}

int SumBetween(const int* a, const int last, int i)
{
    if (i >= last)
        return 0;
    return a[i] + SumBetween(a, last, i + 1);
}

int SumBetweenZeros(const int* a, const int n)
{
    int first = FirstZeroIndex(a, n, 0);
    int last = LastZeroIndex(a, n - 1);

    if (first == -1 || last == -1 || first >= last - 1)
        return 0;

    return SumBetween(a, last, first + 1);
}

void CollectNonNegative(const int* a, int* temp, const int n, int i, int& k)
{
    if (i >= n)
        return;
    if (a[i] >= 0)
        temp[k++] = a[i];
    CollectNonNegative(a, temp, n, i + 1, k);
}

void CollectNegative(const int* a, int* temp, const int n, int i, int& k)
{
    if (i >= n)
        return;
    if (a[i] < 0)
        temp[k++] = a[i];
    CollectNegative(a, temp, n, i + 1, k);
}

void CopyBack(int* a, const int* temp, const int n, int i = 0)
{
    if (i >= n)
        return;
    a[i] = temp[i];
    CopyBack(a, temp, n, i + 1);
}

void Transform(int* a, const int n)
{
    int* temp = new int[n];
    int k = 0;
    CollectNonNegative(a, temp, n, 0, k);
    CollectNegative(a, temp, n, 0, k);
    CopyBack(a, temp, n, 0);
    delete[] temp;
}

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Enter array size n: ";
    if (!(cin >> n) || n <= 0)
    {
        cout << "Invalid array size." << endl;
        return 1;
    }

    int* a = new int[n];
    const int Low = -5;
    const int High = 5;

    Create(a, n, Low, High, 0);

    cout << "\nInitial array:" << endl;
    Print(a, n, 0);

    long long prod = ProductEven(a, n, 0);
    cout << "Product of elements with even indices: " << prod << endl;

    int sum = SumBetweenZeros(a, n);
    int first = FirstZeroIndex(a, n, 0);
    int last = LastZeroIndex(a, n - 1);
    if (first != -1 && last != -1 && first < last)
    {
        cout << "First zero at index: " << first << ", Last zero at index: " << last << endl;
        cout << "Sum between first and last zero: " << sum << endl;
    }
    else
    {
        cout << "Less than two zeros found in the array (sum = 0)." << endl;
    }

    Transform(a, n);

    cout << "\nTransformed array (non-negative first, then negative):" << endl;
    Print(a, n, 0);

    delete[] a;
    return 0;
}
