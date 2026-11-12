#include <iostream> // Ввод и вывод.
#include <vector> // Массивы переменной длины.
using namespace std;

int main() {
    int n; cin >> n; // Длина каждого массива.
    vector<vector<long long>> a(3, vector<long long>(n));
    for (int r = 0; r < 3; r++) {
        for (auto &x : a[r]) cin >> x; // Читаем очередной массив.
    }
    int pos[3] = {0, 0, 0}; // Первый доступный индекс в каждом.
    for (int k = 0; k < 3 * n; k++) {
        int best = -1; // Пока подходящий массив не найден.
        for (int r = 0; r < 3; r++) {
            if (pos[r] == n) continue; // Массив закончился.
            if (best == -1 || a[r][pos[r]] > a[best][pos[best]]) {
                best = r; // Запоминаем номер массива с максимумом.
            }
        }
        if (k > 0) cout << ' ';
        cout << a[best][pos[best]]; // Берём максимум.
        pos[best]++; // Двигаем только указатель выбранного ряда.
    }
    cout << '\n';
}
