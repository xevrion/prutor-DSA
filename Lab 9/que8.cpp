// Problem 7:
// You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.
// We will send a signal from a given node k. Return the minimum time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

// Example 1:

// Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
// Output: 2

// Example 1 input format:
// 4 3 2
// 2 1 1
// 2 3 1
// 3 4 1

// Example 2:
// Input: times = [[1,2,1]], n = 2, k = 1
// Output: 1

// Example 2 input format:
// 2 1 1
// 1 2 1

// Constraints:
// 1 <= k <= n <= 100
// 1 <= times.length <= 6000
// times[i].length == 3
// 1 <= ui, vi <= n
// ui != vi
// 0 <= wi <= 100
// All the pairs (ui, vi) are unique. (i.e., no multiple edges.)

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

class Solution
{
    int n;                                   // number of nodes
    unordered_map<int, vector<pii>> adjList; // adjacency list (node -> [(neighbor, weight)])

public:
    // Constructor initializes the graph with given number of nodes and edges
    Solution(int numVertices, vector<vector<int>> &edges)
    {
        n = numVertices;
        for (auto &edge : edges)
        {
            int u = edge[0], v = edge[1], w = edge[2];
            adjList[u].push_back({v, w});
        }
    }

    // Function to calculate the minimum time for all nodes to receive the signal
    int networkDelayTime(int k) {
        // write code here
        const int INF = numeric_limits<int>::max();
        vector<int> dist(n + 1, INF);
        dist[k] = 0;

        // Min-heap priority queue to process nodes based on the shortest distance
        // Dijkstra's algorithm
        priority_queue<pii, vector<pii>, greater<pii>> pq;
        pq.push({0, k}); // (distance, node)

        while (!pq.empty()) {
            auto [currDist, node] = pq.top();
            pq.pop();

            if (currDist > dist[node]) continue;

            for (auto &[neighbor, weight] : adjList[node]) {
                if (dist[node] + weight < dist[neighbor]) {
                    dist[neighbor] = dist[node] + weight;
                    pq.push({dist[neighbor], neighbor});
                }
            }
        }

        // Find the maximum delay time
        int maxDelay = *max_element(dist.begin() + 1, dist.end());
        return maxDelay == INF ? -1 : maxDelay;
    }
};

int main()
{
    int n, m, k;

    cin >> n >> m >> k;

    vector<vector<int>> times(m);

    for (int i = 0; i < m; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        times[i] = {u, v, w};
    }

    Solution sol(n, times);
    int result = sol.networkDelayTime(k);
    cout << result << "\n";

    return 0;
}