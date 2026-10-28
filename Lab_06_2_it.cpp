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

// Прототипи функцій
void Create(int* a, const int size, const int Low, const int High);
void Print(const int* a, const int size);
void SwapHalves(int* a, const int n);

int main()
{
    srand(static_cast<unsigned>(time(nullptr)));

    const int n = 5;            // розмір однієї половини масиву
    const int size = 2 * n;     // загальна кількість елементів вектора (2n = 10)
    int a[size];                // одновимірний масив (вектор) a
    const int Low = -10;        // нижня межа генерації
    const int High = 20;        // верхня межа генерації

    // 1. Формування початкового масиву
    Create(a, size, Low, High);

    cout << "=====================================================================" << endl;
    cout << " Лабораторна робота № 6.2 (ітераційний спосіб) | Варіант 23" << endl;
    cout << " Завдання: обмін місцями першої та другої половин вектора a[2n]" << endl;
    cout << " Параметри: n = " << n << ", загальний розмір 2n = " << size << endl;
    cout << "=====================================================================" << endl;

    cout << " Індекси i:           ";
    for (int i = 0; i < size; i++)
        cout << setw(4) << i;
    cout << endl;
    cout << "---------------------------------------------------------------------" << endl;

    // 2. Виведення початкового масиву
    cout << " Початковий масив a:  ";
    Print(a, size);

    // 3. Обмін першої та другої половин масиву
    SwapHalves(a, n);

    // 4. Виведення модифікованого масиву
    cout << " Після обміну половин:";
    Print(a, size);
    cout << "=====================================================================" << endl;

    return 0;
}

// Ітераційне заповнення масиву випадковими числами у діапазоні [Low, High]
void Create(int* a, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        a[i] = Low + rand() % (High - Low + 1);
}

// Форматне виведення елементів масиву в рядок
void Print(const int* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

// Ітераційний обмін першої та другої половин масиву (розміром 2n)
void SwapHalves(int* a, const int n)
{
    for (int i = 0; i < n; i++)
    {
        // Обмін i-го елемента першої половини з i-м елементом другої половини (індекс i + n)
        int temp = a[i];
        a[i] = a[i + n];
        a[i + n] = temp;
    }
}
