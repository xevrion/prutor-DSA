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
typedef pair<int,int> pii;

class Solution{
    set<pii> Edges; // normalized undirected edges (first <= second)
    int n;
    int m; // number of undirected edges

public:

    Solution(int numVertices, set<pii>& E){
        // Constructor initialises the graph
        n = numVertices;
        Edges = E;
        m = (int)Edges.size();
    }

    bool isValidEdge(pii e){
        if(e.first > e.second) swap(e.first, e.second);
        return Edges.find(e) != Edges.end();
    } // Checks if an edge exists in the graph

    bool verifyEuleriancycle(vector<int>& seq){
        // Check trivial conditions
        if(seq.size() < 2) return false;
        if(seq.front() != seq.back()) return false;

        // For an Eulerian cycle in an undirected graph with m edges,
        // sequence should traverse exactly m edges => seq.size() == m+1
        if((int)seq.size() != m + 1) return false;

        map<pii,int> used;
        for(size_t i = 0; i + 1 < seq.size(); ++i){
            int a = seq[i], b = seq[i+1];
            pii key = {min(a,b), max(a,b)};
            if(!isValidEdge(key)) return false;
            used[key]++;
            if(used[key] > 1) return false; // edge used more than once
        }

        // All undirected edges must be used exactly once
        if((int)used.size() != m) return false;
        return true;
    }
};

int main(){

    int n,m; cin >> n >> m;
    set<pii> E;

    // store undirected edges normalized once
    int mu = m;
    while(mu--){
        int u,v; cin >> u >> v;
        if(u > v) swap(u,v);
        E.insert({u,v});
    }

    int tt; cin >> tt;

    while(tt--){
        int w; cin >> w;
        vector<int> seq(w,0); for(int i=0;i<w;i++) cin >> seq[i];

        Solution sol(n,E);
        bool ans = sol.verifyEuleriancycle(seq);
        cout << (ans ? "YES" : "NO") << "\n";
    }

    return 0;
}