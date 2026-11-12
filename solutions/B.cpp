#include <iostream> // Ввод и вывод.
#include <utility> // Пары и обмен значений.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    for (int i = 0; i < n - 1; i++) {
        int best = i; // Пока максимум стоит на позиции i.
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[best]) best = j; // Обновляем индекс максимума.
        }
        long long saved = a[i];
        a[i] = a[best];
        a[best] = saved; // Ставим максимум в начало остатка.
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' '; // Пробел между числами.
        cout << a[i]; // Печатаем очередное число.
    }
    cout << '\n';
}
