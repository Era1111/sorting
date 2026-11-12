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
    vector<pair<long long, long long>> points(n);
    for (auto &p : points) cin >> p.first >> p.second;
    auto earlier = [](const auto &a, const auto &b) {
        long long sumA = a.first + a.second;
        long long sumB = b.first + b.second;
        if (sumA != sumB) return sumA < sumB; // Сравниваем суммы.
        return a < b; // При равенстве сравниваем пары (x, y).
    };
    sortManual(points, earlier);
    for (const auto &p : points) {
        cout << p.first << ' ' << p.second << '\n'; // Печатаем x и y.
    }
}
