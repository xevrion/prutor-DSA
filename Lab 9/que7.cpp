// In a busy city, a logistics company is designing a new delivery system to optimize the routes between various distribution centers. The city layout is represented as a directed weighted graph, where:
// Each node represents a distribution center.
// Each edge represents a one-way road connecting two centers, and its weight represents the travel cost.
// Some streets have tolls (positive weights), while others offer company vehicle discounts (negative weights).

// Due to potential tolls or discounts, the company needs an efficient way to compute the shortest delivery cost between each pair of distribution centers, ensuring every delivery path has a positive cycle (otherwise, it's impossible to calculate meaningful shortest paths)

// Input:
// 1. The first line contains two integers V and E, the number of distribution centers and roads, respectively.
// 2. The following E lines contain three integers u, v, and w, indicating a one-way road from center u to center v with a travel cost of w burler. The travel cost w may be harmful, zero, or positive, but no negative cycles exist in the network

// Objective:
//  Determine the minimum delivery cost between each pair of distribution centers.
//  Output:
//  If a solution exists, output a V x V matrix where the entry at row i and column j is the minimum cost to travel
//  from center i to center j.
//  If it is less than or equal to zero, fill 0 in its place.
//  If there is no possible path from center i to center j, keep its corresponding entry as -1.

// Input:4 5
// 1 2 4
// 1 3 -2
// 2 3 3
// 2 4 2
// 3 4 5

// Output:
// 0 4 0 3
// -1 0 3 2
// -1 -1 0 5
// -1 -1 -1 0

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, M;
    cin >> N >> M;
    vector<vector<int>> edges;
    for (int i = 1; i <= M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }

    // complete the logic
    const int INF = numeric_limits<int>::max() / 2; // To prevent overflow
    vector<vector<int>> dist(N, vector<int>(N, INF));
    for (const auto &edge : edges)
    {
        int u = edge[0] - 1, v = edge[1] - 1, weight = edge[2];
        dist[u][v] = weight;
    }
    for (int i = 0; i < N; ++i)
    {
        dist[i][i] = 0;
    }
    for (int k = 0; k < N; ++k)
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    // print the output
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (dist[i][j] >= INF)
                cout << -1 << " ";
            else if (dist[i][j] <= 0)
                cout << 0 << " ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}