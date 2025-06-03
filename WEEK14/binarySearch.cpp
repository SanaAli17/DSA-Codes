#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

int comparisons = 0;

int BinarySearch(vector<int>& arr, int key) {
    comparisons = 0;
    int low = 0, high = arr.size() - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        comparisons++;
        if (arr[mid] == key)
            return mid;

        comparisons++;
        if (key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

void printArray(const vector<int>& arr, const string& label) {
    cout << label << ": ";
    for (int val : arr)
        cout << val << " ";
    cout << "\n";
}

int main() {
    const int N = 10;
    vector<int> arr(N);
    srand(time(0));

    for (int i = 0; i < N; i++)
        arr[i] = rand() % 50;

    sort(arr.begin(), arr.end());
    printArray(arr, "Sorted Array");

    int key;
    cout << "Enter key to search (Binary Search): ";
    cin >> key;

    int pos = BinarySearch(arr, key);
    if (pos != -1)
        cout << "Key found at index " << pos << "\n";
    else
        cout << "Key not found.\n";

    cout << "Comparisons made: " << comparisons << "\n";
    return 0;
}
