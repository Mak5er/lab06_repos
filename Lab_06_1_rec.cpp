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

// Рекурсивне заповнення масиву випадковими числами у діапазоні [Low, High]
void Create(int* t, const int size, const int Low, const int High, int i = 0)
{
    if (i >= size) // базовий випадок: вихід за межі масиву
        return;
    t[i] = Low + rand() % (High - Low + 1);
    Create(t, size, Low, High, i + 1); // рекурсивний перехід до наступного індексу
}

// Рекурсивне форматне виведення елементів масиву в один рядок
void Print(const int* t, const int size, int i = 0)
{
    if (i >= size) // базовий випадок: кінець рядка після останнього елемента
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
int Count(const int* t, const int size, int i = 0)
{
    if (i >= size) // базовий випадок: елементи закінчилися
        return 0;
    int current = Criterion(t[i], i) ? 1 : 0;
    return current + Count(t, size, i + 1); // накопичення кількості на рекурсивному підйомі
}

// Рекурсивне обчислення суми елементів за критерієм
int Sum(const int* t, const int size, int i = 0)
{
    if (i >= size) // базовий випадок: елементи закінчилися
        return 0;
    int current = Criterion(t[i], i) ? t[i] : 0;
    return current + Sum(t, size, i + 1); // накопичення суми на рекурсивному підйомі
}

// Рекурсивна заміна нулями елементів, що задовольняють критерію
void Replace(int* t, const int size, int i = 0)
{
    if (i >= size) // базовий випадок: кінець масиву
        return;
    if (Criterion(t[i], i))
        t[i] = 0;
    Replace(t, size, i + 1); // рекурсивний спуск до наступного елемента
}

int main()
{
    // Ініціалізація генератора випадкових чисел
    srand(static_cast<unsigned>(time(nullptr)));

    const int size = 20;    // кількість елементів масиву
    int t[size];            // одновимірний масив t
    const int Low = -14;    // мінімальне можливе значення
    const int High = 7;     // максимальне можливе значення

    // 1. Формування та виведення початкового масиву
    Create(t, size, Low, High);
    cout << "Original array:" << endl;
    Print(t, size);

    // 2. Рекурсивний підрахунок кількості та суми
    int count = Count(t, size);
    int sum = Sum(t, size);

    cout << "Count = " << count << endl;
    cout << "Sum   = " << sum << endl;

    // 3. Рекурсивна заміна елементів нулями та виведення результату
    Replace(t, size);
    cout << "Modified array:" << endl;
    Print(t, size);

    return 0;
}
