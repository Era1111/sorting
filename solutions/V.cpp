#include <iostream> // Ввод и вывод.
#include <utility> // Пары и обмен значений.
#include <vector> // Массивы переменной длины.
using namespace std;

// Сортируем отрезок [left, right). Правая граница не входит.
template <class T, class Before>
void mergeRange(vector<T>& a, vector<T>& buffer,
                int left, int right, Before before) {
    if (right - left < 2) return; // Ноль или один элемент уже в порядке.
    int mid = left + (right - left) / 2;
    mergeRange(a, buffer, left, mid, before);
    mergeRange(a, buffer, mid, right, before);
    int i = left, j = mid, k = left;
    while (i < mid && j < right) {
        // При равенстве берём левый элемент: исходный порядок сохраняется.
        if (before(a[j], a[i])) buffer[k++] = a[j++];
        else buffer[k++] = a[i++];
    }
    while (i < mid) buffer[k++] = a[i++];
    while (j < right) buffer[k++] = a[j++];
    for (int p = left; p < right; p++) a[p] = buffer[p];
}

template <class T, class Before>
void sortManual(vector<T>& a, Before before) {
    vector<T> buffer(a.size());
    mergeRange(a, buffer, 0, static_cast<int>(a.size()), before);
}

template <class T>
void sortManual(vector<T>& a) {
    sortManual(a, [](const T& x, const T& y) { return x < y; });
}

int main() {
    int n; cin >> n;
    vector<pair<long long, long long>> a(n);
    for (auto &p : a) cin >> p.first >> p.second;
    sortManual(a); // Сортируем по началу отрезка.
    vector<pair<long long, long long>> merged(n);
    int used = 0;
    for (auto p : a) {
        if (used == 0 || p.first > merged[used - 1].second) {
            merged[used] = p;
            used++; // Начинаем новый отрезок.
        } else {
            auto &last = merged[used - 1];
            if (p.second > last.second) last.second = p.second; // Расширяем конец.
        }
    }
    cout << used << '\n';
    for (int i = 0; i < used; i++) {
        auto p = merged[i];
        cout << p.first << ' ' << p.second << '\n';
    }
}
