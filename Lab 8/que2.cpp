// Given an unsorted array of integers and two integers k1 and k2, find the sum of all elements that lie strictly between the k1’th and k2’th smallest elements using a min-heap.
// Do not sort the array directly.

// You must not include the k1’th and k2’th smallest elements themselves in the sum.

// Input Format:

// The first line contains an integer n, the number of elements.

// The second line contains n space-separated integers (the array elements).

// The third line contains two integers k1 and k2.

// Output Format:

// A single integer, the sum of all elements between the k1’th and k2’th smallest elements.

// Sample input:
// 7
// 20 8 22 4 12 10 14
// 3 6

// Output:
// 26


#include <iostream>
#include <vector>
using namespace std;

// TODO: Write a function to min-heapify a subtree rooted at index 'i'
void minheapify(vector<int>& heap, int nodeIdx, int activeSize) {
    // Your code here
    int smallest = nodeIdx;
    int leftKid = 2 * nodeIdx + 1;
    int rightKid = 2 * nodeIdx + 2;

    if (leftKid < activeSize && heap[leftKid] < heap[smallest])
        smallest = leftKid;

    if (rightKid < activeSize && heap[rightKid] < heap[smallest])
        smallest = rightKid;

    if (smallest != nodeIdx) {
        swap(heap[nodeIdx], heap[smallest]);
        minheapify(heap, smallest, activeSize);
    }
}

int extractMin(vector<int>& heap, int& sizeRef) {
    int rootVal = heap[0];
    heap[0] = heap[sizeRef - 1];
    sizeRef--;
    minheapify(heap, 0, sizeRef);
    return rootVal;
}

// TODO: Write function to compute sum between k1-th and k2-th smallest
int sumBetweenK1K2(vector<int>& elements, int k1, int k2) {
    // Step 1: Build the min-heap
    // Step 2: Remove smallest elements until k1-th smallest
    // Step 3: Continue removing and summing until (k2 - 1)-th smallest
    // Step 4: Return the total sum
    int total = elements.size();

    for (int i = total / 2 - 1; i >= 0; i--)
        minheapify(elements, i, total);

    int currentSize = total;
    for (int i = 0; i < k1; i++)
        extractMin(elements, currentSize);

    long long betweenSum = 0;
    for (int j = k1 + 1; j < k2; j++)
        betweenSum += extractMin(elements, currentSize);

    return static_cast<int>(betweenSum);
    // return 0;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int k1, k2;
    cin >> k1 >> k2;

    cout << sumBetweenK1K2(arr, k1, k2);

    return 0;
}