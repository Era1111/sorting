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
    vector<pair<long long, int>> events(2 * n);
    for (int i = 0; i < n; i++) {
        long long left, right; cin >> left >> right;
        events[2 * i] = {left, 1}; // В этот момент событие начинается.
        events[2 * i + 1] = {right, -1}; // В этот момент оно закончилось.
    }
    sortManual(events); // При равенстве −1 раньше +1.
    int active = 0, best = 0;
    for (auto event : events) {
        active += event.second; // Обновляем число активных событий.
        if (active > best) best = active; // Запоминаем максимум.
    }
    cout << best << '\n';
}
