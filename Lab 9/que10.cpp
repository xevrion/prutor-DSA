// The government of the country Wakanda, post WW3, is trying to set up a road network between its cities. Due to budget constraints, it wants to minimize the road making costs, while maintaining connectivity between all cities. The chief consultant wants to use Prim's algorithm to determine the optimal road layout. Help him build the code.

// Input format:
// 1st line contains Number of cities 'N', and Number of possible roads 'M' 
// Next M lines contain 2 city_numbers and the cost of making road between them (city_numbers go from 1 to N inclusive)

// Output format:
// One integer giving total road cost

// Example:
// Input:
// 4 5
// 1 2 3
// 1 3 1
// 2 3 3
// 3 4 6
// 2 4 5

// Output:
// 9

// Explanation:
// Here, the set of roads (1, 3), (1, 2) and (2, 4) ensure connectivity between all cities, while being lowest cost possible (1 + 3 + 5 = 9).

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Class to represent an edge
class Edge {
public:
    int node;
    int weight;
    Edge(int n, int w) : node(n), weight(w) {}
};


// Solution (Road Graph) class
class Solution {
private:
    int numCities;
    vector<vector<Edge>> adjList;

public:
    Solution(int N) : numCities(N) {
        adjList.resize(N + 1);
    }

    // Method to add a road to the road graph
    void addRoad(int u, int v, int weight) {
        adjList[u].emplace_back(v, weight);
        adjList[v].emplace_back(u, weight);
    }

    // To Do: Method to find optimal road layout using Prim's algorithm and print cost
    void prim() {
        vector<bool> inMST(numCities + 1, false);
        vector<int> minEdgeCost(numCities + 1, INT_MAX);
        minEdgeCost[1] = 0; // Start from city 1

        int totalCost = 0;

        for (int i = 1; i <= numCities; ++i) {
            int u = -1;
            for (int j = 1; j <= numCities; ++j) {
                if (!inMST[j] && (u == -1 || minEdgeCost[j] < minEdgeCost[u])) {
                    u = j;
                }
            }

            inMST[u] = true;
            totalCost += minEdgeCost[u];

            for (const Edge &edge : adjList[u]) {
                if (!inMST[edge.node] && edge.weight < minEdgeCost[edge.node]) {
                    minEdgeCost[edge.node] = edge.weight;
                }
            }
        }

        cout << totalCost << endl;
    }
};

int main() {
    int N, M;
    cin >> N >> M;

    // Create a road graph with N cities
    Solution solver(N);

    for (int i = 0; i < M; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        solver.addRoad(u, v, w);
    }

    // Run Prim's algorithm and print the cost
    solver.prim();

    return 0;
}