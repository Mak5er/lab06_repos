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

// Рекурсивний збір усіх невід'ємних елементів (a[i] >= 0) у масив temp
void CollectNonNegative(const int* a, int* temp, const int n, int i, int& k)
{
    if (i >= n)
        return;
    if (a[i] >= 0)
        temp[k++] = a[i];
    CollectNonNegative(a, temp, n, i + 1, k);
}

// Рекурсивний збір усіх від'ємних елементів (a[i] < 0) у масив temp
void CollectNegative(const int* a, int* temp, const int n, int i, int& k)
{
    if (i >= n)
        return;
    if (a[i] < 0)
        temp[k++] = a[i];
    CollectNegative(a, temp, n, i + 1, k);
}

// Рекурсивне копіювання елементів із тимчасового масиву temp назад у масив a
void CopyBack(int* a, const int* temp, const int n, int i = 0)
{
    if (i >= n)
        return;
    a[i] = temp[i];
    CopyBack(a, temp, n, i + 1);
}

// 2. Рекурсивне перетворення масиву зі збереженням відносного порядку елементів
void Transform(int* a, const int n)
{
    int* temp = new int[n];
    int k = 0; // лічильник заповнення temp (передається за посиланням)

    CollectNonNegative(a, temp, n, 0, k); // спочатку додатні та нулі
    CollectNegative(a, temp, n, 0, k);    // потім від'ємні
    CopyBack(a, temp, n, 0);              // копіювання результату назад у масив a

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
