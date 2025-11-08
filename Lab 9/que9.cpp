// A walk is a sequence of vertices in a graph such that any two consecutive vertices in the sequence are connected by an edge.
// A walk is said to be a hamiltonian cycle if it visits each and every vertex exactly once and returns to the starting vertex in the end.
// That is, all vertices except the first and the last are visited exactly once, while the first and the last vertices are visited exactly twice.

// Given a graph of n vertices (each having a unique label from 1 to n), and m edges, Find whether a given sequence of vertices is a valid hamiltonian cycle.

// Function description
// Complete the function bool verifyHamiltonianCycle(vector& seq) that takes as input a sequence of vertices, and returns whether the sequence is a hamiltonian cycle.

// The solution class has been constructed for you.
// Following are its private parameters :

// class Solution{
// private:
// 	int n;						// the number of vertices
// 	set> Edges;		// set of edges
// ...
// ...

// }

// Input Format
// First line contains 2 integers - n and m : number of vertices and number of edges in the graph.

// Each of the m lines that follow contain 2 integers u and v indicating that there is an edge between u and v.

// The next line contains a single integer tt, the number of sequences you need to test on.

// Each test case that follows has integer w in the first line - the number of vertices in the sequence, and w integers in the second line corresponding to the vertex sequence.

// Output format
// For each test sequence, output “YES” if the sequence is a hamiltonian cycle, else output “NO” in a new line each time.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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
    bool isValidEdge(pii e)
    {
        return Edges.find(e) != Edges.end();
    }
    bool verifyHamiltonianCycle(vector<int> &seq)
    {
        // TODO

        if (seq.size() != n + 1)
            return false;

        if (seq.front() != seq.back())
            return false;

        // set<int> visited;
        // for (int i = 0; i < seq.size() - 1; i++)
        // {
        //     int u = seq[i];
        //     int v = seq[i + 1];
        //     if (!isValidEdge({u, v}) && !isValidEdge({v, u}))
        //         return false;
        //     visited.insert(u);
        // }
        // visited.insert(seq.back());

        // return visited.size() == n && isValidEdge({seq.back(), seq[0]});

        for (int i = 0; i < seq.size() - 1; i++)
        {
            int u = seq[i];
            int v = seq[i + 1];
            if (!isValidEdge({u, v}) && !isValidEdge({v, u}))
                return false;
        }

        set<int> visited(seq.begin(), seq.end() - 1);
        if (visited.size() != n)
            return false;

        return true;
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

        bool ans = sol.verifyHamiltonianCycle(seq);
        cout << (ans ? "YES" : "NO") << "\n";
    }
    return 0;
}