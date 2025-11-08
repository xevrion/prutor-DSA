#include <bits/stdc++.h>
using namespace std;

#define MAX_CHAR 256 // Assuming ASCII character set

int lengthOfLongestSubstring(string s)
{
    map<char, int> charIndexMap;
    int i = 0, j = 1;
    int n = s.length();
    if (n == 1)
        return 1;
    charIndexMap.insert({s[i], i});
    int maxCount = 0;
    while (j < n)
    {
        if (charIndexMap.find(s[j]) != charIndexMap.end() && charIndexMap[s[j]] >= i)
        {
            i = charIndexMap[s[j]] + 1;
        }
        charIndexMap[s[j]] = j;
        maxCount = max(maxCount, j - i + 1);
        j++;
    }
    return maxCount;
}

// Notes
//  This problem tests your ability to utilize hash maps to keep track of characters and their indices.
//  Consider how you can use a sliding window technique in conjunction with a hash map to efficiently solve this problem.
//  Hint
//  Start by initializing a hash map to store characters and their most recent indices. Then, use two pointers to represent the current window of characters without repetition. Move the right pointer to expand the window and update the hash map. If a repeating character is found, move the left pointer to shrink the window.

int main()
{
    string str;
    getline(cin, str);
    cout << lengthOfLongestSubstring(str) << endl;
    return 0;
}
