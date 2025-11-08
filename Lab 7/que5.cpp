#include <bits/stdc++.h>
using namespace std;
 
// Function to find the longest duplicate DNA substring
string longestDupSubstring(const string &s) {
	// TODO: Implement using binary search + rolling hash
	int totalSize = s.size();
    const long long modulus = (1LL << 61) - 1;
    const long long baseVal = 131;

    auto checkFxn = [&](int length) {
        if (length == 0) return string();
        long long hash = 0, power = 1;
        for (int i = 0; i < length; i++) {
            hash = (hash * baseVal + s[i]) % modulus;
            power = (power * baseVal) % modulus;
        }
        unordered_map<long long, vector<int>> seen;
        seen[hash].push_back(0);

        for (int i = length; i < totalSize; i++) {
            hash = (hash * baseVal - s[i - length] * power % modulus + modulus) % modulus;
            hash = (hash + s[i]) % modulus;
            if (seen.count(hash)) {
                for (int start : seen[hash]) {
                    if (s.compare(start, length, s, i - length + 1, length) == 0)
                        return s.substr(start, length);
                }
            }
            seen[hash].push_back(i - length + 1);
        }
        return string();
    };

    int L = 0, R = totalSize;
    string ans;
    while (L <= R) {
        int middle = (L + R) / 2;
        string tmp = checkFxn(middle);
        if (!tmp.empty()) {
            ans = tmp;
            L = middle + 1;
        } else {
            R = middle - 1;
        }
    }
    // if(ans == "") return ans;
    // else return "";
    return ans;
// 	return "";
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	string s;
	if (!(cin >> s)) return 0;
 
	// Validate DNA input
	for (char c : s) {
    	if (c != 'A' && c != 'T' && c != 'C' && c != 'G') {
        	cout << "Invalid DNA sequence\n";
        	return 0;
    	}
	}
 
	cout << longestDupSubstring(s) << "\n";
	return 0;
}