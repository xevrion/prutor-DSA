// Your task is to develop a program that finds the Minimum Spanning Tree (MST) of a given connected, undirected graph using Kruskal’s algorithm. Implement the solution explicitly using Krusal's algorithm. The input will consist of the number of vertices, the number of edges, and a list of edges with their weights.

// Requirements:

// Implement classes for:
// Edge: To store edge information.
// Graph: To store the graph and implement Kruskal's algorithm.
// Solution: To manage operations for cycle detection and MST calculation.

// The output should display the edges in the MST and their total weight.
// Input Format:
// The first line contains two integers: V (number of vertices) and E (number of edges).
// The next E lines each contain three integers: u, v, and w (representing an edge between vertices u and v with weight w).

// Output Format:
// Print the edges included in the MST in the format (u, v) followed by the total weight of the MST.

// Sample Input:
// 4 5
// 0 1 10
// 0 2 6
// 0 3 5
// 1 3 15
// 2 3 4

// Expected Output:
// Your task is to develop a program that finds the Minimum Spanning Tree (MST) of a given connected, undirected graph using Kruskal’s algorithm. Implement the solution explicitly using Krusal's algorithm. The input will consist of the number of vertices, the number of edges, and a list of edges with their weights.

// Requirements:

// Implement classes for:
// Edge: To store edge information.
// Graph: To store the graph and implement Kruskal's algorithm.
// Solution: To manage operations for cycle detection and MST calculation.

// The output should display the edges in the MST and their total weight.
// Input Format:
// The first line contains two integers: V (number of vertices) and E (number of edges).
// The next E lines each contain three integers: u, v, and w (representing an edge between vertices u and v with weight w).

// Output Format:
// Print the edges included in the MST in the format (u, v) followed by the total weight of the MST.

// Sample Input:
// 4 5
// 0 1 10
// 0 2 6
// 0 3 5
// 1 3 15
// 2 3 4

// Expected Output:
// 2 3 4
// 0 3 5
// 0 1 10
// 19

// Explanation:
// Edges in the MST:
// (2, 3) Weight: 4
// (0, 3) Weight: 5
// (0, 1) Weight: 10
// Total Weight of MST: 19

#include <iostream>
#include <vector>
#include <algorithm>

class Edge
{
public:
    int u, v, weight;
    Edge(int u, int v, int weight) : u(u), v(v), weight(weight) {}
};

class DisjointSet
{
private:
    std::vector<int> parent, rank;

public:
    DisjointSet(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i; // Initialize each node as its own parent
        }
    }

    // Find function with path compression
    int find(int u)
    {
        // TODO: Implement path compression logic
        // Hint: If u is not the parent of itself, set parent[u] to the result of find(parent[u]).
        if (u != parent[u])
        {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    void unite(int u, int v)
    {
        // TODO: Implement union by rank logic
        // Hint: Find the roots of u and v and attach the smaller tree under the larger tree.
        int rootU = find(u);
        int rootV = find(v);
        if (rootU != rootV)
        {
            if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

class Graph
{
private:
    int V;
    std::vector<Edge> edges;

public:
    Graph(int V) : V(V) {}

    void addEdge(int u, int v, int weight)
    {
        edges.emplace_back(u, v, weight);
    }

    // Function to find the MST using Kruskal's algorithm
    void kruskalMST()
    {
        // TODO: Sort the edges based on their weight
        // Hint: Use std::sort and a lambda function to sort edges by weight
        std::sort(edges.begin(), edges.end(), [](Edge a, Edge b)
                  { return a.weight < b.weight; });

        DisjointSet ds(V);
        std::vector<Edge> mst;
        int totalWeight = 0;

        // TODO: Iterate over the edges and construct the MST
        // Hint: Use the DisjointSet to check if including an edge forms a cycle
        for (const auto &edge : edges)
        {
            if (ds.find(edge.u) != ds.find(edge.v))
            {
                ds.unite(edge.u, edge.v);
                mst.push_back(edge);
                totalWeight += edge.weight;
            }
        }

        // Print the MST edges
        for (const auto &edge : mst)
        {
            std::cout << edge.u << " " << edge.v << " " << edge.weight << std::endl;
        }

        // Print the total weight of the MST
        std::cout << totalWeight << std::endl;
    }
};

int main()
{
    int V, E;
    std::cin >> V >> E;
    Graph graph(V);

    for (int i = 0; i < E; i++)
    {
        int u, v, weight;
        std::cin >> u >> v >> weight;
        graph.addEdge(u, v, weight);
    }

    graph.kruskalMST();
    return 0;
}