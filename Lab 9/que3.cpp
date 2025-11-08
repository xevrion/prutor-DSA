// Given a graph of n vertices (each having a unique label from 1 to n), and m edges, Find whether a given sequence of vertices is a valid Eulerian cycle.

// Input Format :
// First line contains 2 integers - n and m : number of vertices and number of edges in the graph.Each of the m lines that follow contain 2 integers u and v indicating that there is an edge between u and v.

// The next line contains a single integer tt, the number of sequences you need to test on.

// Each test case that follows has integer w in the first line - the number of vertices in the sequence, and w integers in the second line corresponding to the vertex sequence.

// Output format:

// For each test sequence, output “YES” if the sequence is an Eulerian cycle; else output “NO” in a new line each time.

// Example

// Input :

// 5 5
// 1 2
// 2 3
// 3 4
// 4 5
// 1 5
// 3
// 6
// 1 2 3 4 5 1
// 6
// 1 5 4 3 2 1
// 4
// 1 3 4 2

// Output :
// YES
// YES
// NO

#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

class Solution
{
    set<pii> Edges;
    int n;

public:
    Solution(int numVertices, set<pii> &E)
    {
        // Constructor initialises the graph

        n = numVertices;
        Edges = E;
    }

    bool isValidEdge(pii e); // Checks if an edge exists in the graph

    bool verifyEuleriancycle(vector &seq)
    {

        // Write your code here. Feel free to use the isValidEdge helper
    }
};

int main()
{

    int n, m;
    cin >> n >> m;
    set<pii> E;

    while (m--)
    {
        int u, v;
        cin >> u >> v;
        E.insert({u, v});
        E.insert({v, u});
    }

    int tt;
    cin >> tt;

    while (tt--)
    {
        int w;
        cin >> w;
        vector<int> seq(w, 0);
        for (int i = 0; i < w; i++)
            cin >> seq[i];

        Solution sol(n, E);
        bool ans = sol.sol.verifyEuleriancycle(seq);
        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;
}