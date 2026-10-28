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

// Прототипи функцій
void Create(int* t, const int size, const int Low, const int High);
void Print(const int* t, const int size);
bool Criterion(int value, int index);
int Count(const int* t, const int size);
int Sum(const int* t, const int size);
void Replace(int* t, const int size);

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));

    const int size = 20;    // розмір масиву за варіантом 23
    int t[size];            // одновимірний масив t
    const int Low = -14;    // нижня межа діапазону [-14, 7]
    const int High = 7;     // верхня межа діапазону [-14, 7]

    // 1. Формування масиву
    Create(t, size, Low, High);

    cout << "=============================================================================================" << endl;
    cout << " Лабораторна робота № 6.1 (ітераційний спосіб) | Варіант 23" << endl;
    cout << " Критерій: всі додатні елементи (t[i] > 0) з індексами, крім кратних 4 (i % 4 != 0)" << endl;
    cout << "=============================================================================================" << endl;

    cout << " Індекси i:         ";
    for (int i = 0; i < size; i++)
        cout << setw(4) << i;
    cout << endl;
    cout << "---------------------------------------------------------------------------------------------" << endl;

    // 2. Виведення початкового масиву
    cout << " Початковий масив:  ";
    Print(t, size);

    // 3. Обчислення кількості та суми елементів за критерієм
    int count = Count(t, size);
    int sum = Sum(t, size);

    // 4. Заміна відібраних елементів нулями та виведення модифікованого масиву
    Replace(t, size);
    cout << " Модифікований (0): ";
    Print(t, size);
    cout << "=============================================================================================" << endl;

    // 5. Виведення таблиці результатів
    cout << "\n+-----------------------------------------------+------------+" << endl;
    cout << "| Показник                                      |  Значення  |" << endl;
    cout << "+-----------------------------------------------+------------+" << endl;
    cout << "| Кількість елементів за критерієм (Count)      | " << setw(10) << count << " |" << endl;
    cout << "| Сума елементів за критерієм (Sum)             | " << setw(10) << sum << " |" << endl;
    cout << "+-----------------------------------------------+------------+" << endl;

    return 0;
}

// Ітераційне заповнення масиву випадковими числами у діапазоні [Low, High]
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

// Ітераційне обчислення кількості елементів за критерієм
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

// Ітераційне обчислення суми елементів за критерієм
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
