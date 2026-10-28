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

// Прототипи рекурсивних функцій
void Create(int* t, const int size, const int Low, const int High, int i = 0);
void Print(const int* t, const int size, int i = 0);
void PrintIndices(const int size, int i = 0);
bool Criterion(int value, int index);
int Count(const int* t, const int size, int i = 0);
int Sum(const int* t, const int size, int i = 0);
void Replace(int* t, const int size, int i = 0);

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));

    const int size = 20;    // розмір масиву за варіантом 23
    int t[size];            // одновимірний масив t
    const int Low = -14;    // мінімальне значення елементів
    const int High = 7;     // максимальне значення елементів

    // 1. Рекурсивне формування масиву
    Create(t, size, Low, High);

    cout << "=============================================================================================" << endl;
    cout << " Лабораторна робота № 6.1 (рекурсивний спосіб) | Варіант 23" << endl;
    cout << " Критерій: всі додатні елементи (t[i] > 0) з індексами, крім кратних 4 (i % 4 != 0)" << endl;
    cout << "=============================================================================================" << endl;

    cout << " Індекси i:         ";
    PrintIndices(size);
    cout << "---------------------------------------------------------------------------------------------" << endl;

    // 2. Рекурсивне виведення початкового масиву
    cout << " Початковий масив:  ";
    Print(t, size);

    // 3. Рекурсивне обчислення кількості та суми
    int count = Count(t, size);
    int sum = Sum(t, size);

    // 4. Рекурсивна заміна нулями та виведення модифікованого масиву
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

// Рекурсивне заповнення масиву випадковими числами у діапазоні [Low, High]
void Create(int* t, const int size, const int Low, const int High, int i)
{
    if (i >= size) // базовий випадок: вихід за межі масиву
        return;
    t[i] = Low + rand() % (High - Low + 1);
    Create(t, size, Low, High, i + 1); // рекурсивний перехід до наступного елемента
}

// Рекурсивне виведення рядка індексів
void PrintIndices(const int size, int i)
{
    if (i >= size)
    {
        cout << endl;
        return;
    }
    cout << setw(4) << i;
    PrintIndices(size, i + 1);
}

// Рекурсивне форматне виведення елементів масиву
void Print(const int* t, const int size, int i)
{
    if (i >= size) // базовий випадок: кінець рядка
    {
        cout << endl;
        return;
    }
    cout << setw(4) << t[i];
    Print(t, size, i + 1);
}

// Перевірка критерію Варіанта 23: додатні елементи з індексами, не кратними 4
bool Criterion(int value, int index)
{
    return (value > 0 && index % 4 != 0);
}

// Рекурсивне обчислення кількості елементів за критерієм
int Count(const int* t, const int size, int i)
{
    if (i >= size) // базовий випадок
        return 0;
    int current = Criterion(t[i], i) ? 1 : 0;
    return current + Count(t, size, i + 1); // підрахунок на рекурсивному підйомі
}

// Рекурсивне обчислення суми елементів за критерієм
int Sum(const int* t, const int size, int i)
{
    if (i >= size) // базовий випадок
        return 0;
    int current = Criterion(t[i], i) ? t[i] : 0;
    return current + Sum(t, size, i + 1); // накопичення суми на рекурсивному підйомі
}

// Рекурсивна заміна нулями елементів, що задовольняють критерію
void Replace(int* t, const int size, int i)
{
    if (i >= size) // базовий випадок
        return;
    if (Criterion(t[i], i))
        t[i] = 0;
    Replace(t, size, i + 1);
}
