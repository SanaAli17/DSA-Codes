#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int comparisons = 0, exchanges = 0;

void Heapify(vector<int>& a, int n, int i) {
    int largest = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && ++comparisons && a[l] > a[largest]) largest = l;
    if (r < n && ++comparisons && a[r] > a[largest]) largest = r;

    if (largest != i) {
        swap(a[i], a[largest]);
        exchanges++;
        Heapify(a, n, largest);
    }
}

void HeapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(a, n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(a[0], a[i]);
        exchanges++;
        Heapify(a, i, 0);
    }
}

int main() {
    const int N = 1000;
    vector<int> arr(N);
    srand(time(0));
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 10000;

    clock_t start = clock();
    HeapSort(arr);
    clock_t end = clock();

    cout << "Heap Sort:\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Exchanges: " << exchanges << "\n";
    cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}
