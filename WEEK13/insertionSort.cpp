#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int comparisons = 0, exchanges = 0;

void InsertionSort(vector<int>& a) {

    int n = a.size();

    for (int k = 1; k < n; k++) {

        int y = a[k];
        int j = k - 1;

        while (j >= 0 && ++comparisons && y < a[j]) {
            a[j + 1] = a[j];
            j--;
            exchanges++;
        }
        a[j + 1] = y;
    }
}

int main() {
    const int N = 1000;
    vector<int> arr(N);
    srand(time(0));
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 10000;

    clock_t start = clock();
    InsertionSort(arr);
    clock_t end = clock();

    cout << "Insertion Sort:\n";
    cout << "Comparisons: " << comparisons << "\n";
    cout << "Exchanges: " << exchanges << "\n";
    cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";
    return 0;
}