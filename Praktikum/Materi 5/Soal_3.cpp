#include<bits/stdc++.h>
using namespace std;

#define INF INT_MAX

// Fungsi untuk menemukan jalur terpendek menggunakan algoritma Dijkstra
void shortestPath(vector<pair<int, int>> adj[], int V, int src, int dest) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V + 1, INF);
    vector<int> parent(V + 1, -1);

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (auto i : adj[u]) {
            int v = i.first;
            int weight = i.second;

            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
                pq.push({dist[v], v});
            }
        }
    }

    if (dist[dest] == INF) {
        cout << "-1\n";
    } else {
        vector<int> path;
        for (int i = dest; i != -1; i = parent[i]) {
            path.push_back(i);
        }

        reverse(path.begin(), path.end());

        for (int i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i < path.size() - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> adj[n + 1];

    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
        adj[y].push_back({x, z});
    }

    int src = 1;
    int dest = n;

    shortestPath(adj, n, src, dest);

    return 0;
}
