#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;

int comparisons = 0, exchanges = 0;

void BubbleSort(vector<int>& a) {

    int n = a.size();
    bool swapped = true;

    for (int pass = 0; pass < n - 1 && swapped; pass++) {

        swapped = false;

        for (int j = 0; j < n - pass - 1; j++) {
            comparisons++;

            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                exchanges++;
                swapped = true;
            }
        }
    }
}

void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": ";
    for (int val : arr)
        cout << val << " ";
    cout << endl;
}


int main() {
    const int N = 10;
    vector<int> arr(N);

    srand(time(0));
    for (int i = 0; i < N; i++)
        arr[i] = rand() % 100;  

    printArray(arr, "Unsorted Array");

    clock_t start = clock();
    BubbleSort(arr);  
    clock_t end = clock();

    printArray(arr, "Sorted Array");

    cout << "Comparisons: " << comparisons << "\n";
    cout << "Exchanges: " << exchanges << "\n";
    cout << "Execution Time: " << double(end - start) / CLOCKS_PER_SEC << " seconds\n";

    return 0;
}

