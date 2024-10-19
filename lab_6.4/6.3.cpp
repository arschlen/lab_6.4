#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

// Функція для виведення масиву
void PrintArray(double mas[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(6) << mas[i] << " ";
    }
    cout << endl;
}

// Функція для підрахунку кількості додатних елементів
int CountPositive(double mas[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] > 0) {
            count++;
        }
    }
    return count;
}

// Функція для обчислення суми елементів після останнього нульового елемента
double SumAfterLastZero(double mas[], int size) {
    int lastZeroIndex = -1;
    for (int i = 0; i < size; i++) {
        if (mas[i] == 0) {
            lastZeroIndex = i;
        }
    }
    double sum = 0;
    if (lastZeroIndex != -1) {
        for (int i = lastZeroIndex + 1; i < size; i++) {
            sum += mas[i];
        }
    }
    return sum;
}

// Функція для перестановки елементів: спочатку ті, ціла частина яких <= 1, потім інші
void ReorderArray(double mas[], int size) {
    vector<double> lessOrEqualOne;
    vector<double> greaterThanOne;

    // Розподіляємо елементи на дві групи
    for (int i = 0; i < size; i++) {
        if (floor(mas[i]) <= 1) {
            lessOrEqualOne.push_back(mas[i]);
        }
        else {
            greaterThanOne.push_back(mas[i]);
        }
    }

    // Об'єднуємо групи зберігаючи відносне розташування
    int index = 0;
    for (double val : lessOrEqualOne) {
        mas[index++] = val;
    }
    for (double val : greaterThanOne) {
        mas[index++] = val;
    }
}

int main() {
    setlocale(LC_CTYPE, "ukr");

    int n;
    cout << "Введіть кількість елементів масиву n: ";
    cin >> n;

    double* mas = new double[n];

    cout << "Введіть елементи масиву: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "Початковий масив: " << endl;
    PrintArray(mas, n);

    // 1.1. Кількість додатних елементів
    int positiveCount = CountPositive(mas, n);
    cout << "Кількість додатних елементів: " << positiveCount << endl;

    // 1.2. Сума елементів після останнього нульового елемента
    double sumAfterZero = SumAfterLastZero(mas, n);
    cout << "Сума елементів після останнього нуля: " << sumAfterZero << endl;

    // 2. Перетворення масиву
    ReorderArray(mas, n);

    cout << "Перетворений масив: " << endl;
    PrintArray(mas, n);

    delete[] mas;
    return 0;
}
