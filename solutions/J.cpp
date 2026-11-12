#include <iostream> // Ввод и вывод.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n, m; cin >> n >> m; // Читаем размеры двух массивов.
    vector<long long> a(n), b(m);
    for (auto &x : a) cin >> x; // Первый массив.
    for (auto &x : b) cin >> x; // Второй массив.
    int i = 0, j = 0; // Позиции в двух массивах.
    for (int k = 0; k < n + m; k++) {
        if (k > 0) cout << ' ';
        if (j == m || (i < n && a[i] <= b[j])) {
            cout << a[i]; // Берём из A, если он доступен и меньше.
            i++;
        } else {
            cout << b[j]; // Иначе берём из B.
            j++;
        }
    }
    cout << '\n';
}
