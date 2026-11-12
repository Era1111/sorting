#include <iostream> // Ввод и вывод.
#include <utility> // Пары и обмен значений.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    int swaps = 0;
    for (int i = 0; i < n; i++) {
        while (a[i] != i + 1) { // На позиции i должно быть i + 1.
            int target = a[i] - 1; // Индекс для текущего числа.
            long long saved = a[i];
            a[i] = a[target];
            a[target] = saved; // Одно число встало на своё место.
            swaps++;
        }
    }
    cout << swaps << '\n';
}
