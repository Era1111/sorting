#include <iostream> // Ввод и вывод.
#include <utility> // Пары и обмен значений.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    int swaps = 0; // Число выполненных обменов.
    for (int i = 0; i < n - 1; i++) {
        int best = i; // Пока минимум стоит на позиции i.
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[best]) best = j; // Обновляем индекс минимума.
        }
        if (best != i) { // Минимум стоит на другой позиции.
            long long saved = a[i];
            a[i] = a[best];
            a[best] = saved;
            swaps++; // Считаем только фактический обмен.
        }
    }
    cout << swaps << '\n';
}
