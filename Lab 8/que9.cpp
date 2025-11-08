// A string s is called happy if it satisfies all of the following:

// s only contains the characters 'a', 'b', and 'c'.

// s does not contain "aaa", "bbb", or "ccc" as a substring.

// s contains at most a occurrences of 'a'.

// s contains at most b occurrences of 'b'.

// s contains at most c occurrences of 'c'.

// Given three integers a, b, and c, your task is to find the number of distinct happy strings that have the maximum possible length.

// If no happy string exists, print 0.

// Input Format:
// a b c

// Output Format:
// number of largest strings

// Sample Input:
// 1 1 7

// Expected Output:
// 2

// As there may exist 2 largest such strings: ccbccacc and ccaccbcc

#include <bits/stdc++.h>
using namespace std;
class HappyStringGenerator
{
public:
    int a, b, c;
    // TODO: Add data structures to store results and max length
    HappyStringGenerator(int x, int y, int z)
    {
        a = x;
        b = y;
        c = z;
    }
    // TODO: Write a recursive function to generate all valid happy strings
    // Use constraints: no "aaa", "bbb", "ccc"
    // At most a 'a's, b 'b's, c 'c's
    void generateStrings(string current, int countA, int countB, int countC, set<string> &results, int &maxLength)
    {
        // Base case: update results if current string is valid
        if (countA > a || countB > b || countC > c)
            return;

        if (current.length() > maxLength)
        {
            maxLength = current.length();
            results.clear();
            results.insert(current);
        }
        else if (current.length() == maxLength)
        {
            results.insert(current);
        }

        // Recursive case: try adding 'a', 'b', 'c' if valid
        if (current.length() < 2 || current.substr(current.length() - 2) != "aa")
        {
            generateStrings(current + 'a', countA + 1, countB, countC, results, maxLength);
        }
        if (current.length() < 2 || current.substr(current.length() - 2) != "bb")
        {
            generateStrings(current + 'b', countA, countB + 1, countC, results, maxLength);
        }
        if (current.length() < 2 || current.substr(current.length() - 2) != "cc")
        {
            generateStrings(current + 'c', countA, countB, countC + 1, results, maxLength);
        }
    }
    // TODO: Keep track of maximum length and all strings of that length
    int countLongestHappyStrings()
    {
        // TODO: Start DFS / backtracking from empty string
        // Return the number of distinct longest happy strings
        set<string> results;
        int maxLength = 0;
        generateStrings("", 0, 0, 0, results, maxLength);
        return results.size();
    }
};
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    HappyStringGenerator gen(a, b, c);
    cout << gen.countLongestHappyStrings() << endl;
    return 0;
}