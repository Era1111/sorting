#include <iostream> // Ввод и вывод.
#include <utility> // Пары и обмен значений.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    for (int pass = 0; pass < n - 1; pass++) {
        // Готовая часть справа растёт на одну клетку.
        for (int j = 0; j < n - 1 - pass; j++) {
            if (a[j] > a[j + 1]) { // Сравниваем соседей.
                long long saved = a[j];
                a[j] = a[j + 1];
                a[j + 1] = saved; // Больший переходит вправо.
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' '; // Пробел между числами.
        cout << a[i]; // Печатаем очередное число.
    }
    cout << '\n';
}
