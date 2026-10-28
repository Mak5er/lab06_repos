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

// Заповнення масиву випадковими числами у діапазоні [Low, High]
void Create(int* t, const int size, const int Low, const int High)
{
    for (int i = 0; i < size; i++)
        t[i] = Low + rand() % (High - Low + 1);
}

// Форматне виведення елементів масиву в один рядок
void Print(const int* t, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << t[i];
    cout << endl;
}

// Перевірка критерію Варіанта 23: додатні елементи з індексами, не кратними 4
bool Criterion(int value, int index)
{
    return (value > 0 && index % 4 != 0);
}

// Ітераційне обчислення кількості елементів, що задовольняють критерію
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

// Ітераційне обчислення суми елементів, що задовольняють критерію
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

// Ітераційна заміна нулями елементів, що задовольняють критерію
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
    // Ініціалізація генератора випадкових чисел поточним часом
    srand(static_cast<unsigned>(time(nullptr)));

    const int size = 20;    // розмір масиву за варіантом
    int t[size];            // одновимірний масив t
    const int Low = -14;    // нижня межа діапазону значень
    const int High = 7;     // верхня межа діапазону значень

    // 1. Формування та виведення початкового масиву
    Create(t, size, Low, High);
    cout << "Original array:" << endl;
    Print(t, size);

    // 2. Обчислення кількості та суми елементів за критерієм
    int count = Count(t, size);
    int sum = Sum(t, size);

    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    // 3. Модифікація масиву (заміна відібраних елементів нулями) та виведення
    Replace(t, size);
    cout << "Modified array:" << endl;
    Print(t, size);

    return 0;
}
