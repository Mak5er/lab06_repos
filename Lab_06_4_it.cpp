// Lab_06_4_it.cpp
// Рева Максим
// Лабораторна робота № 6.4
// Опрацювання та впорядкування одновимірних динамічних масивів (ітераційний спосіб)
// Варіант 23

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void Create(int* a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

void Print(const int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

long long ProductEven(const int* a, const int n)
{
    if (n <= 0)
        return 0;
    long long prod = 1;
    for (int i = 0; i < n; i += 2)
        prod *= a[i];
    return prod;
}

int FirstZeroIndex(const int* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            return i;
    }
    return -1;
}

int LastZeroIndex(const int* a, const int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
            return i;
    }
    return -1;
}

int SumBetweenZeros(const int* a, const int n)
{
    int first = FirstZeroIndex(a, n);
    int last = LastZeroIndex(a, n);

    if (first == -1 || last == -1 || first >= last - 1)
        return 0;

    int sum = 0;
    for (int i = first + 1; i < last; i++)
        sum += a[i];
    return sum;
}

void Transform(int* a, const int n)
{
    int* temp = new int[n];
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            temp[k++] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            temp[k++] = a[i];
    }
    for (int i = 0; i < n; i++)
        a[i] = temp[i];

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

    Create(a, n, Low, High);

    cout << "\nInitial array:" << endl;
    Print(a, n);

    long long prod = ProductEven(a, n);
    cout << "Product of elements with even indices: " << prod << endl;

    int sum = SumBetweenZeros(a, n);
    int first = FirstZeroIndex(a, n);
    int last = LastZeroIndex(a, n);
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
    Print(a, n);

    delete[] a;
    return 0;
}
