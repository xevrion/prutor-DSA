// In a vast kingdom, there are n towns connected by a network of two-way roads, each with a specific difficulty level or travel weight. The roads between towns are recorded in the edges array, where each entry edges[i] = [fromi, toi, weighti] tells us that there is a road connecting towns fromi and toi, with a difficulty of weighti.

// The king sets a distance limit (referred to as distanceThreshold) beyond which travel is considered too challenging for the common people. He wants to find out which town has the fewest other towns reachable within this distance limit. If there are multiple towns with the same reachability, he prefers the town with the highest number.

// Your goal is to help the king identify this town, considering that the difficulty of travel between two towns is the total of road difficulties along any connecting path.


// INPUT-OUTPUT FORMAT
// 1. 2 <= n <= 100
// 2. 1 <= edges.length <= n * (n - 1) / 2
// 3. edges[i].length == 3
// 4. 0 <= fromi < toi < n
// 5. 1 <= weighti, distanceThreshold <= 10^4
// 6. All pairs (fromi, toi) are distinct.

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class CityIsolation {
public:
    int findIsolatedCity(int n, const vector<vector<int>>& edges, int distanceThreshold) {
        
        // Write your code here.
        const int INF = numeric_limits<int>::max()/2; // To prevent overflow
        vector<vector<int>> dist(n, vector<int>(n, INF));
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], weight = edge[2];
            dist[u][v] = weight;
            dist[v][u] = weight;
        }
        for (int i = 0; i < n; ++i) {
            dist[i][i] = 0;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int isolatedCity = -1;
        int minReachable = INF;
        for (int i = 0; i < n; ++i) {
            int reachableCount = 0;
            for (int j = 0; j < n; ++j) {
                if (dist[i][j] <= distanceThreshold) {
                    ++reachableCount;
                }
            }
            if (reachableCount < minReachable) {
                minReachable = reachableCount;
                isolatedCity = i;
            } else if (reachableCount == minReachable) {
                isolatedCity = max(isolatedCity, i);
            }
        }
        return isolatedCity;
    }
};

int main() {
    int n;
    cin>>n;
    vector<vector<int>> edges;
    for(int i=0;i<n;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        edges.push_back({u,v,weight});
    }
    int distanceThreshold;
    cin>>distanceThreshold;
    CityIsolation obj;
    int result = obj.findIsolatedCity(n, edges, distanceThreshold);
    cout<<result<<endl;
    return 0;
}