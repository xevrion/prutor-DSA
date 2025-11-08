#include <bits/stdc++.h>
using namespace std;

struct State
{
    int node;
    double prob;
    int time;
};

class Solution
{
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target)
    {
        vector<vector<int>> adj(n);
        for (auto &e : edges)
        {
            int u = e[0] - 1;
            int v = e[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<State> q;
        vector<int> visited(n, 0);

        q.push({0, 1.0, 0});
        visited[0] = 1;

        target--; // 0-based

        while (!q.empty())
        {
            auto [node, prob, time] = q.front();
            q.pop();

            // count unvisited neighbors
            int unvisited = 0;
            for (int nei : adj[node])
                if (!visited[nei])
                    unvisited++;

            // case 1: reached target
            if (node == target)
            {
                if (time == t)
                    return prob;
                if (unvisited == 0)
                    return prob; // frog stuck
                return 0.0;      // will jump away
            }

            // case 2: still exploring
            if (time < t)
            {
                for (int nei : adj[node])
                {
                    if (!visited[nei])
                    {
                        visited[nei] = 1;
                        q.push({nei, prob / unvisited, time + 1});
                    }
                }
            }
        }

        return 0.0;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, t, target;
    cout.setf(std::ios::fixed);
    cout << setprecision(10);

    while (cin >> n >> t >> target)
    {
        vector<vector<int>> edges;
        for (int i = 0; i < n - 1; ++i)
        {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution sol;
        double ans = sol.frogPosition(n, edges, t, target);
        cout << ans << "\n";
    }

    return 0;
}
