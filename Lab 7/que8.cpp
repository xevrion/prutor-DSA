#include <bits/stdc++.h>
using namespace std;

// You are designing a smart search engine autocomplete system. Whenever a user types a query, the system tries to suggest meaningful completions.
// But this search engine has a special feature: it loves palindromes!
// A palindrome is a string that reads the same forward and backward (like madam, racecar, aba).
// The autocomplete system wants to suggest results where two words from its dictionary can be concatenated to form a palindrome.
// For example:
// If the dictionary has "race" and "car", the suggestion "racecar" should appear.
// If it has "ab" and "ba", then "abba" should be suggested.
// Given a list of unique words, find all pairs (i,j) such that words[i]+words[j] is a palindrome. Return list of pairs.
// Input
// First line: integer n (number of words)
// Next n lines: each a word (lowercase ASCII)
// Output
// Each pair as i j (0-based) on a separate line; in lexicographical sorted order of pairs (i,j) . If none, print -1.
// Constraints
// 1 <= n <= 10^5 (but sum lengths <= 2x10^5)
// Sample Input
// 5
// abcd                                 	
// dcba
// lls
// s
// sssll
// Output
// 0 1
// 1 0
// 2 4
// 3 2

vector<pair<int,int>> palindromePairs(const vector<string>& words) {
	// implement reversed-hash + prefix/suffix palindrome checks
    unordered_map<string, int> wordIndex;
    for (int i = 0; i < words.size(); ++i) {
        string rev = words[i];
        reverse(rev.begin(), rev.end());
        wordIndex[rev] = i;
    }

    set<pair<int, int>> result;

    auto isPalindrome = [](const string& s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) return false;
        }
        return true;
    };

    for (int i = 0; i < words.size(); ++i) {
        const string& word = words[i];
        for (int j = 0; j <= word.size(); ++j) {
            // Check prefix
            if (isPalindrome(word, j, word.size() - 1)) {
                string suffix = word.substr(0, j);
                if (wordIndex.count(suffix) && wordIndex[suffix] != i) {
                    result.emplace(i, wordIndex[suffix]);
                }
            }
            // Check suffix
            if (j > 0 && isPalindrome(word, 0, j - 1)) {
                string prefix = word.substr(j);
                if (wordIndex.count(prefix) && wordIndex[prefix] != i) {
                    result.emplace(wordIndex[prefix], i);
                }
            }
        }
    }

    if (!result.empty()) {
        return vector<pair<int, int>>(result.begin(), result.end());
    } else
    return {};
}
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n; if (!(cin >> n)) return 0;
	vector<string> words(n);
	for (int i = 0; i < n; ++i) cin >> words[i];
	auto res = palindromePairs(words);
	if (res.empty()) cout << -1 << "\n";
	else {
    	for (auto &p : res) cout << p.first << " " << p.second << "\n";
	}
	return 0;
}