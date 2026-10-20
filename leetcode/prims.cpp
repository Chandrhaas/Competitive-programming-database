#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> pii; // {weight, node}

int prim(int n, vector<vector<pii>>& adj) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<bool> visited(n, false);
    int mst_weight = 0;
    int edges_count = 0;

    // Start from node 0
    pq.push({0, 0}); 

    while (!pq.empty() && edges_count < n) {
        int w = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (visited[u]) continue; // Skip if node is already in MST

        visited[u] = true;
        mst_weight += w;
        edges_count++;

        for (auto& edge : adj[u]) {
            if (!visited[edge.second]) {
                pq.push(edge);
            }
        }
    }
    return mst_weight;
}

int main() {
    int nodes = 4;
    vector<vector<pii>> adj(nodes);

    // Adding edges: {weight, destination}
    adj[0].push_back({10, 1}); adj[1].push_back({10, 0});
    adj[0].push_back({6, 2});  adj[2].push_back({6, 0});
    adj[0].push_back({5, 3});  adj[3].push_back({5, 0});
    adj[1].push_back({15, 3}); adj[3].push_back({15, 1});
    adj[2].push_back({4, 3});  adj[3].push_back({4, 2});

    cout << "Total Weight of MST: " << prim(nodes, adj) << endl;

    return 0;
}