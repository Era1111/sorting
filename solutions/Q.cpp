#include <iostream> // Ввод и вывод.
#include <utility> // Пары и обмен значений.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    for (int last = n - 1; last > 0; last--) {
        int best = 0; // Первый кандидат на максимум.
        for (int j = 1; j <= last; j++) {
            if (a[j] > a[best]) best = j;
        }
        long long saved = a[best];
        a[best] = a[last];
        a[last] = saved; // Максимум занимает позицию last.
        for (int i = 0; i < n; i++) {
            if (i > 0) cout << ' '; // Пробел между числами.
            cout << a[i]; // Печатаем очередное число.
        }
        cout << '\n';
    }
}
