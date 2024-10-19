#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>
using namespace std;

// ������� ��� ��������� ������
void PrintArray(double mas[], int size) {
    for (int i = 0; i < size; i++) {
        cout << setw(6) << mas[i] << " ";
    }
    cout << endl;
}

// ������� ��� ��������� ������� �������� ��������
int CountPositive(double mas[], int size) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (mas[i] > 0) {
            count++;
        }
    }
    return count;
}

// ������� ��� ���������� ���� �������� ���� ���������� ��������� ��������
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

// ������� ��� ������������ ��������: �������� �, ���� ������� ���� <= 1, ���� ����
void ReorderArray(double mas[], int size) {
    vector<double> lessOrEqualOne;
    vector<double> greaterThanOne;

    // ����������� �������� �� �� �����
    for (int i = 0; i < size; i++) {
        if (floor(mas[i]) <= 1) {
            lessOrEqualOne.push_back(mas[i]);
        }
        else {
            greaterThanOne.push_back(mas[i]);
        }
    }

    // ��'������ ����� ��������� ������� ������������
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
    cout << "������ ������� �������� ������ n: ";
    cin >> n;

    double* mas = new double[n];

    cout << "������ �������� ������: " << endl;
    for (int i = 0; i < n; i++) {
        cin >> mas[i];
    }

    cout << "���������� �����: " << endl;
    PrintArray(mas, n);

    // 1.1. ʳ������ �������� ��������
    int positiveCount = CountPositive(mas, n);
    cout << "ʳ������ �������� ��������: " << positiveCount << endl;

    // 1.2. ���� �������� ���� ���������� ��������� ��������
    double sumAfterZero = SumAfterLastZero(mas, n);
    cout << "���� �������� ���� ���������� ����: " << sumAfterZero << endl;

    // 2. ������������ ������
    ReorderArray(mas, n);

    cout << "������������ �����: " << endl;
    PrintArray(mas, n);

    delete[] mas;
    return 0;
}
