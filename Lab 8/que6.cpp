// Given an array arr[] of size n, which can contain both positive and negative integers, your task is to find the k-th largest sum among all possible contiguous subarrays of the array.

// A contiguous subarray is a sequence of consecutive elements from the array.
// For example, for arr = [2, -1, 3], the possible contiguous subarrays are [2], [2, -1], [2, -1, 3], [-1], [-1, 3], and [3].

// Input

// An integer n, the size of the array.

// An array arr[] of n integers (can include negative numbers).

// An integer k, representing the order of the largest subarray sum to find

// Output
// k-th largest sum of contiguous subarrays.

#include <bits/stdc++.h>
using namespace std;

class KthLargestSubarraySum {
private:
    vector<int> arr;
    int k;

public:
    KthLargestSubarraySum(vector<int>& nums, int kth) {
        arr = nums;
        k = kth;
    }

    int findKthLargest() {
        int n = arr.size();
        // TODO: create prefix sum array // why a prefix sum array you may ask: // because it helps in calculating sum of any subarray in O(1) time after O(n) preprocessing.
        vector<long long> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++)
            prefix[i] = prefix[i - 1] + arr[i - 1];

        // TODO: create min-heap of size k
        priority_queue<long long, vector<long long>, greater<long long>> minheap;

        // TODO: loop through all subarrays 
        // calculate sum and maintain top k in min-heap
        for (int start = 0; start < n; start++) {
            for (int end = start + 1; end <= n; end++) {
                long long subSum = prefix[end] - prefix[start];
                if ((int)minheap.size() < k)
                    minheap.push(subSum);
                else if (subSum > minheap.top()) {
                    minheap.pop();
                    minheap.push(subSum);
                }
            }
        }

        return (int)minheap.top(); // placeholder
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    KthLargestSubarraySum solver(arr, k);
    cout << solver.findKthLargest() << endl;
}
