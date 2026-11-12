#include <iostream> // Ввод и вывод.
#include <vector> // Массивы переменной длины.
using namespace std;

long long countPairs(vector<long long> &a, vector<long long> &tmp,
                     int left, int right) {
    if (right - left < 2) return 0; // В одном элементе пары нет.
    int mid = (left + right) / 2;
    long long count = countPairs(a, tmp, left, mid);
    count += countPairs(a, tmp, mid, right); // Пары внутри частей.
    int i = left, j = mid, k = left;
    while (i < mid && j < right) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++]; // Меньшее число из левой части.
        } else {
            count += mid - i; // Все оставшиеся слева больше a[j].
            tmp[k++] = a[j++];
        }
    }
    while (i < mid) tmp[k++] = a[i++]; // Дописываем левый хвост.
    while (j < right) tmp[k++] = a[j++]; // Дописываем правый хвост.
    for (int t = left; t < right; t++) a[t] = tmp[t];
    return count;
}

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    vector<long long> tmp(n); // Буфер для слияния.
    cout << countPairs(a, tmp, 0, n) << '\n'; // Правая граница исключена.
}
