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

// Прототипи функцій
void Create(int* a, const int n, const int Low, const int High);
void Print(const int* a, const int n);
long long ProductEven(const int* a, const int n);
int FirstZeroIndex(const int* a, const int n);
int LastZeroIndex(const int* a, const int n);
int SumBetweenZeros(const int* a, const int n);
void Transform(int* a, const int n);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    int n;
    cout << "Введіть розмір динамічного масиву n: ";
    if (!(cin >> n) || n <= 0)
    {
        cout << "Помилка: розмір масиву n має бути додатним числом!" << endl;
        return 1;
    }

    // Виділення динамічної пам'яті під масив розміром n
    int* a = new int[n];
    const int Low = -3;
    const int High = 3;

    // 1. Формування початкового масиву
    Create(a, n, Low, High);

    cout << "\n====================================================================================" << endl;
    cout << " Лабораторна робота № 6.4 (ітераційний спосіб) | Варіант 23 | Розмір n = " << n << endl;
    cout << "====================================================================================" << endl;

    cout << " Індекси i:           ";
    for (int i = 0; i < n; i++)
        cout << setw(5) << i;
    cout << endl;
    cout << "------------------------------------------------------------------------------------" << endl;

    // 2. Виведення початкового масиву
    cout << " Початковий масив a:  ";
    Print(a, n);

    // 3. Обчислення характеристик за варіантом 23
    long long prod = ProductEven(a, n);
    int first = FirstZeroIndex(a, n);
    int last = LastZeroIndex(a, n);
    int sum = SumBetweenZeros(a, n);

    // 4. Перетворення масиву (спочатку >= 0, потім < 0) та виведення
    Transform(a, n);
    cout << " Перетворений масив:  ";
    Print(a, n);
    cout << "====================================================================================" << endl;

    // 5. Зведена таблиця результатів
    cout << "\n+----------------------------------------------------+--------------+" << endl;
    cout << "| Показник                                           |   Значення   |" << endl;
    cout << "+----------------------------------------------------+--------------+" << endl;
    cout << "| 1.1. Добуток елементів з парними індексами         | " << setw(12) << prod << " |" << endl;
    cout << "|      Індекс першого нульового елемента             | " << setw(12) << first << " |" << endl;
    cout << "|      Індекс останнього нульового елемента          | " << setw(12) << last << " |" << endl;
    cout << "| 1.2. Сума елементів між першим і останнім нулями   | " << setw(12) << sum << " |" << endl;
    cout << "+----------------------------------------------------+--------------+" << endl;

    // Звільнення динамічної пам'яті
    delete[] a;
    return 0;
}

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

// 2. Перетворення масиву: спочатку всі додатні та нульові (>= 0), потім від'ємні (< 0)
// зі збереженням їхнього відносного порядку (стабільне розбиття)
void Transform(int* a, const int n)
{
    int* temp = new int[n]; // тимчасовий динамічний масив
    int k = 0;              // поточна позиція запису в масив temp

    // Прохід 1: вибираємо всі невід'ємні елементи (додатні та нулі)
    for (int i = 0; i < n; i++)
    {
        if (a[i] >= 0)
            temp[k++] = a[i];
    }

    // Прохід 2: вибираємо всі від'ємні елементи
    for (int i = 0; i < n; i++)
    {
        if (a[i] < 0)
            temp[k++] = a[i];
    }

    // Копіюємо впорядковані елементи назад у початковий масив a
    for (int i = 0; i < n; i++)
        a[i] = temp[i];

    delete[] temp; // звільнення пам'яті тимчасового масиву
}
