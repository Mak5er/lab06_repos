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

// Ітераційне заповнення динамічного масиву випадковими числами у діапазоні [Low, High]
void Create(int* a, const int n, const int Low, const int High)
{
    for (int i = 0; i < n; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Форматне виведення елементів динамічного масиву
void Print(const int* a, const int n)
{
    for (int i = 0; i < n; i++)
        cout << setw(5) << a[i];
    cout << endl;
}

// 1.1. Обчислення добутку елементів масиву з парними номерами (індекси 0, 2, 4, ...)
long long ProductEven(const int* a, const int n)
{
    if (n <= 0)
        return 0;
    long long prod = 1; // початкове значення для добутку = 1
    for (int i = 0; i < n; i += 2) // крок +2 для обходу лише парних індексів
        prod *= a[i];
    return prod;
}

// Пошук індексу першого нульового елемента (повертає -1, якщо нулів немає)
int FirstZeroIndex(const int* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 0)
            return i;
    }
    return -1;
}

// Пошук індексу останнього нульового елемента (обхід з кінця масиву)
int LastZeroIndex(const int* a, const int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] == 0)
            return i;
    }
    return -1;
}

// 1.2. Обчислення суми елементів, розташованих між першим і останнім нулями
int SumBetweenZeros(const int* a, const int n)
{
    int first = FirstZeroIndex(a, n);
    int last = LastZeroIndex(a, n);

    // Якщо нулів менше двох або вони стоять поруч — між ними немає елементів
    if (first == -1 || last == -1 || first >= last - 1)
        return 0;

    int sum = 0;
    for (int i = first + 1; i < last; i++)
        sum += a[i];
    return sum;
}

// 2. Ітераційне перетворення масиву in-place (без виділення додаткового масиву, O(1) додаткової пам'яті):
// переставляємо елементи так, щоб спочатку йшли всі невід'ємні (>= 0), а потім від'ємні (< 0)
// зі збереженням їхнього відносного порядку (стабільне розбиття)
void Transform(int* a, const int n)
{
    int lastPos = 0; // позиція, куди має стати наступний невід'ємний елемент
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
        {
            if (i > lastPos)
            {
                int val = a[i];
                // Зсуваємо блок від'ємних елементів праворуч на одну позицію in-place
                for (int j = i; j > lastPos; j--)
                    a[j] = a[j - 1];
                a[lastPos] = val;
            }
            lastPos++;
        }
    }
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

    // Виділення динамічної пам'яті під масив розміром n
    int* a = new int[n];
    const int Low = -5;
    const int High = 5;

    // 1. Формування та виведення початкового масиву
    Create(a, n, Low, High);
    cout << "\nInitial array:" << endl;
    Print(a, n);

    // 2. Обчислення добутку елементів з парними індексами
    long long prod = ProductEven(a, n);
    cout << "Product of elements with even indices: " << prod << endl;

    // 3. Обчислення суми між першим і останнім нулями
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

    // 4. Перетворення масиву та виведення результату
    Transform(a, n);
    cout << "\nTransformed array (non-negative first, then negative):" << endl;
    Print(a, n);

    // Звільнення динамічної пам'яті
    delete[] a;
    return 0;
}
