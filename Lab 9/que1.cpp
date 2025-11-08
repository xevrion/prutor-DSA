// You are given a directed graph with n vertices, where each vertex has a non-negative integer value. The graph is a single connected component, and you need to determine the k-th largest value among all vertices reachable from a specified starting vertex using a Breadth-First Search (BFS) traversal.

// Input Format
// An integer the number of vertices.
// A line containing n space-separated integers representing the values of the vertices.
// An integer k , the position of the largest value to retrieve.
// Output Format
// Print the k-th largest value from the reachable vertices starting from vertex 0.
// Example
// 5
// 10 20 15 25 5
// 2
// Output
// 20


#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

// Function to perform BFS and find the k-th largest element
int kthLargestBFS(int startNode, const vector<vector<int>>& graph, const unordered_map<int, int>& values, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    vector<bool> visited(graph.size(), false);
    queue<int> q;

    q.push(startNode);
    visited[startNode] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();

        
        minHeap.push(values.at(currentNode));
        if (minHeap.size() > k) {
            minHeap.pop(); 
        }

        // Explore neighbors
        for (int neighbor : graph[currentNode]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }

    
    return minHeap.top();
    
}

int main() {
    int n; // Number of vertices
    cin >> n;

    // Read the values of the vertices
    vector<int> vertexValues(n);
    for (int i = 0; i < n; ++i) {
        cin >> vertexValues[i];
    }

    // Sample graph as an adjacency list for a single component
    vector<vector<int>> graph(n);
    for (int i = 0; i < n - 1; ++i) {
        graph[i].push_back(i + 1);
        graph[i + 1].push_back(i);
    }

    // Create a mapping of vertex indices to their values
    unordered_map<int, int> values;
    for (int i = 0; i < n; ++i) {
        values[i] = vertexValues[i];
    }

    // Read the value of k
    int k;
    cin >> k;

    // Starting BFS from the first node (0)
    int result = kthLargestBFS(0, graph, values, k);
    cout << result << endl;

    return 0;
}