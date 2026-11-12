#include <iostream> // Ввод и вывод.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    int bad = 0;
    while (bad + 1 < n && a[bad] >= a[bad + 1]) bad++;
    if (bad + 1 < n) { // В этой паре нарушен порядок.
        int pos = bad; // Пробуем убрать левый элемент.
        bool fits = true;
        int prev = -1;
        for (int i = 0; i < n; i++) {
            if (i == pos) continue; // Временно пропускаем кандидата.
            if (prev >= 0 && a[prev] < a[i]) fits = false;
            prev = i;
        }
        if (!fits) pos = bad + 1; // Проверка указала на правый.
        long long key = a[pos];
        for (int i = pos; i + 1 < n; i++) a[i] = a[i + 1]; // Закрываем пропуск.
        int at = 0;
        while (at < n - 1 && a[at] >= key) at++;
        for (int i = n - 1; i > at; i--) a[i] = a[i - 1];
        a[at] = key; // Заполняем место вставки.
    }
    for (int i = 0; i < n; i++) {
        if (i > 0) cout << ' '; // Пробел между числами.
        cout << a[i]; // Печатаем очередное число.
    }
    cout << '\n';
}
