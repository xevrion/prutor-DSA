#include <bits/stdc++.h>
using namespace std;
 
// You are analyzing sensor data that is stored in an integer array. Each subarray is a "pattern" of sensor readings. You want to count how many unique patterns exist among all contiguous subarrays. That is, given an integer array a of length n (n <= 2000), count the number of distinct contiguous subarrays. Two subarrays are considered equal if they have exactly same sequence of numbers. Return the count.
// Input
// First line: n 
// Second line: n integers (-1e^9 <= a[i] <= 1e^9)
//  Output
// Single integer: number of distinct contiguous subarrays.
// Sample Input
// 3
// 1 2 1
// Output
// 5

long long countDistinctSubarrays(const vector<long long>& a) {
	// implement rolling hash enumeration
    const int n = a.size();
    const long long p = 31; // a small prime number because input numbers can be large
    const long long m = 1e9 + 9; // a large prime number because input numbers can be large

    long long count = 0;
    unordered_set<long long> seen;

    for (int i = 0; i < n; ++i) {
        long long hash = 0;
        long long p_pow = 1;

        for (int j = i; j < n; ++j) {
            hash = (hash + (a[j] + 1) * p_pow) % m;
            if (seen.insert(hash).second) {
                ++count;
            }
            p_pow = (p_pow * p) % m;
        }
    }

	return count;
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; if (!(cin >> n)) return 0;
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	cout << countDistinctSubarrays(a) << "\n";
	return 0;
}