#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int comparisons = 0, exchanges = 0;

void SelectionSort(vector<int>& a) {
    int n = a.size();

    for (int i = 0; i < n - 1; i++) {

        int min_idx = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;

            if (a[j] < a[min_idx])
                min_idx = j;
        }

        if (min_idx != i) {
            swap(a[i], a[min_idx]);
            exchanges++;
        }
    }
}

int main() {
    const int N = 1000;
    vector<int> arr(N);

    srand(time(0));
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 10000;

    clock_t start = clock();
    SelectionSort(arr);
    clock_t end = clock();

    cout << "Selection Sort:\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Exchanges: " << exchanges << "\n";
    cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}
