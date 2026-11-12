#include <iostream> // Ввод и вывод.
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

int rankOf(const vector<long long>& values, int count, long long x) {
    int left = 0, right = count; // Ищем в полуинтервале [left, right).
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (values[mid] < x) left = mid + 1;
        else right = mid;
    }
    return left + 1; // Индекс с нуля превращаем в ранг с единицы.
}

struct Fenwick {
    vector<long long> tree;
    Fenwick(int n) : tree(n + 1, 0) {} // Индексы начинаются с 1.
    void add(int i, long long value) {
        for (; i < (int)tree.size(); i += i & -i) {
            tree[i] += value; // Обновляем блоки с этим рангом.
        }
    }
    long long prefix(int i) {
        long long sum = 0;
        for (; i > 0; i -= i & -i) {
            sum += tree[i]; // Складываем блоки от 1 до i.
        }
        return sum;
    }
};

int main() {
    int n; cin >> n; // Читаем размер массива.
    vector<long long> a(n); // Создаём массив из n чисел.
    for (auto &x : a) cin >> x; // Вводим числа по порядку.
    vector<long long> values = a; // Создаём таблицу рангов.
    sortManual(values);
    int distinct = 0;
    for (int i = 0; i < (int)values.size(); i++) {
        if (distinct == 0 || values[i] != values[distinct - 1]) {
            values[distinct] = values[i];
            distinct++;
        }
    }
    Fenwick counts(distinct), sums(distinct);
    long long seen = 0, total = 0, answer = 0;
    for (long long x : a) {
        int rank = rankOf(values, distinct, x);
        long long greaterCount = seen - counts.prefix(rank);
        long long greaterSum = total - sums.prefix(rank);
        answer += greaterSum - x * greaterCount; // Вклад числа x.
        counts.add(rank, 1); // Добавляем число в дерево счётчиков.
        sums.add(rank, x); // Добавляем его значение в дерево сумм.
        seen++;
        total += x;
    }
    cout << answer << '\n';
}
