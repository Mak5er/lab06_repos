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

// Рекурсивне заповнення динамічного масиву випадковими числами у діапазоні [Low, High]
void Create(int* a, const int n, const int Low, const int High, int i = 0)
{
    if (i >= n) // базовий випадок
        return;
    a[i] = Low + rand() % (High - Low + 1);
    Create(a, n, Low, High, i + 1);
}

// Рекурсивне виведення елементів динамічного масиву
void Print(const int* a, const int n, int i = 0)
{
    if (i >= n) // базовий випадок
    {
        cout << endl;
        return;
    }
    cout << setw(5) << a[i];
    Print(a, n, i + 1);
}

// 1.1. Рекурсивне обчислення добутку елементів з парними номерами (індекси 0, 2, 4, ...)
long long ProductEven(const int* a, const int n, int i = 0)
{
    if (n <= 0)
        return 0;
    if (i >= n) // базовий випадок: повертаємо 1 як нейтральний множник
        return 1;
    return a[i] * ProductEven(a, n, i + 2); // рекурсивний крок +2 по парних індексах
}

// Рекурсивний пошук індексу першого нуля (прямий прохід від 0 до n-1)
int FirstZeroIndex(const int* a, const int n, int i = 0)
{
    if (i >= n) // нуль не знайдено
        return -1;
    if (a[i] == 0)
        return i;
    return FirstZeroIndex(a, n, i + 1);
}

// Рекурсивний пошук індексу останнього нуля (зворотний прохід від n-1 до 0)
int LastZeroIndex(const int* a, const int i)
{
    if (i < 0) // нуль не знайдено
        return -1;
    if (a[i] == 0)
        return i;
    return LastZeroIndex(a, i - 1);
}

// Допоміжна рекурсивна функція для підсумовування елементів до індексу last
int SumBetween(const int* a, const int last, int i)
{
    if (i >= last) // дійшли до останнього нуля
        return 0;
    return a[i] + SumBetween(a, last, i + 1);
}

// 1.2. Обчислення суми елементів між першим і останнім нульовими елементами
int SumBetweenZeros(const int* a, const int n)
{
    int first = FirstZeroIndex(a, n, 0);
    int last = LastZeroIndex(a, n - 1);

    // Якщо нулів менше двох або між ними немає елементів
    if (first == -1 || last == -1 || first >= last - 1)
        return 0;

    return SumBetween(a, last, first + 1);
}

// Допоміжна рекурсивна функція зсуву елементів праворуч на одну позицію in-place
void ShiftRight(int* a, int j, const int target)
{
    if (j <= target)
        return;
    a[j] = a[j - 1];
    ShiftRight(a, j - 1, target);
}

// 2. Рекурсивне перетворення масиву in-place (без виділення додаткового масиву, O(1) додаткової пам'яті):
// переставляємо елементи так, щоб спочатку йшли всі невід'ємні (>= 0), а потім від'ємні (< 0)
// зі збереженням їхнього відносного порядку (стабільне розбиття)
void Transform(int* a, const int n, int i = 0, int lastPos = 0)
{
    if (i >= n)
        return;

    if (a[i] >= 0)
    {
        if (i > lastPos)
        {
            int val = a[i];
            ShiftRight(a, i, lastPos);
            a[lastPos] = val;
        }
        Transform(a, n, i + 1, lastPos + 1);
    }
    else
    {
        Transform(a, n, i + 1, lastPos);
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

    // 1. Рекурсивне формування та виведення масиву
    Create(a, n, Low, High, 0);
    cout << "\nInitial array:" << endl;
    Print(a, n, 0);

    // 2. Рекурсивне обчислення добутку елементів з парними індексами
    long long prod = ProductEven(a, n, 0);
    cout << "Product of elements with even indices: " << prod << endl;

    // 3. Рекурсивне обчислення суми між першим і останнім нулями
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

    // 4. Рекурсивне перетворення масиву та виведення результату
    Transform(a, n);
    cout << "\nTransformed array (non-negative first, then negative):" << endl;
    Print(a, n, 0);

    // Звільнення динамічної пам'яті
    delete[] a;
    return 0;
}
