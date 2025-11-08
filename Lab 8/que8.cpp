// You are given two binary max-heaps represented as arrays a[] and b[].
// Your task is to merge these two heaps into a single max-heap that satisfies the heap property:
// each parent node’s value should be greater than or equal to its child nodes.

// You must return the merged heap as an array in level order.

// Input Format

// First line: integer n (size of first heap)

// Second line: n space-separated integers representing the first max heap

// Third line: integer m (size of second heap)

// Fourth line: m space-separated integers representing the second max heap

// Output Format

// Print the merged max-heap elements in level order.

// Sample Input:
// 4
// 10 5 6 2
// 3
// 12 7 9


// Expected Output:
// 12 10 9 2 5 7 6

#include <iostream>
#include <vector>
using namespace std;

void heapify(vector<int>& arr, int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

int main() {
    int n, m;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for (int i = 0; i < m; i++) cin >> b[i];

    vector<int> merged = a;
    merged.insert(merged.end(), b.begin(), b.end());

    int size = merged.size();
    for (int i = size / 2 - 1; i >= 0; i--)
        heapify(merged, size, i);

    for (int x : merged)
        cout << x << " ";
    cout << endl;
}
