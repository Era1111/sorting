#include <iostream> // Ввод и вывод.
#include <utility> // Пары и обмен значений.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    int best = 0; // Индекс первого кандидата на минимум.
    for (int j = 1; j < n; j++) {
        if (a[j] < a[best]) best = j; // Нашли меньший элемент.
    }
    long long saved = a[0];
    a[0] = a[best];
    a[best] = saved; // Минимум занимает первую клетку.
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' '; // Пробел между числами.
        cout << a[i]; // Печатаем очередное число.
    }
    cout << '\n';
}
