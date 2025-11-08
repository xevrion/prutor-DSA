// You are given a directed graph consisting of n vertices, where each vertex is associated with a non-negative integer value. Your task is to compute the sum of the values of all vertices that can be reached from a specified starting vertex using a Depth-First Search (DFS) traversal. However, only include those vertex values that are greater than a given threshold.

// Input Format:
// An integer n, the number of vertices.
// A line containing n space-separated integers representing the values of the vertices.
// An integer k ,the threshold value.

// Output Format
// Print a single integer, the sum of the values of all reachable vertices greater than the threshold.

// Example
// 5
// 10 20 30 40 50
// 25
// Output
// 120 (30+40+50)

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// DFS function to calculate the sum of values greater than the threshold
void dfs(int node, const vector<vector<int>>& graph, const vector<int>& values, int threshold, int& sum, unordered_set<int>& visited) {
    for(int i = 0; i<graph.size(); i++) {
        if(visited.find(i) == visited.end()) {
            visited.insert(i);
            if(values[i] > threshold) {
                sum += values[i];
            }
            for(int neighbor : graph[i]) {
                dfs(neighbor, graph, values, threshold, sum, visited);
            }
        }
    }
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

    // Read the threshold value
    int threshold;
    cin >> threshold;

    // To keep track of visited nodes and the sum
    unordered_set<int> visited;
    int sum = 0;

    // Start DFS from the first node (0)
    dfs(0, graph, vertexValues, threshold, sum, visited);

    // Output the result
    cout << sum << endl;

    return 0;
}