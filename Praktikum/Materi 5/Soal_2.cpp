#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v;
    long long speed;
};

bool compareEdges(const Edge& a, const Edge& b) {
    return a.speed < b.speed;
}

int findParent(int node, vector<int>& parent) {
    if (parent[node] == node) {
        return node;
    }
    return parent[node] = findParent(parent[node], parent);
}

void unionSets(int u, int v, vector<int>& parent, vector<int>& rank) {
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);

    if (rootU != rootV) {
        if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else {
            parent[rootU] = rootV;
            rank[rootV]++;
        }
    }
}

long long findMinSpeed(vector<Edge>& edges, int N) {
    sort(edges.begin(), edges.end(), compareEdges);

    vector<int> parent(N + 1);
    vector<int> rank(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        parent[i] = i;
    }

    for (const auto& edge : edges) {
        int u = edge.u;
        int v = edge.v;
        long long speed = edge.speed;

        int rootU = findParent(u, parent);
        int rootV = findParent(v, parent);

        if (rootU != rootV) {
            unionSets(u, v, parent, rank);
            if (findParent(1, parent) == findParent(N, parent)) {
                return speed;
            }
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; ++t) {
        int N, M;
        cin >> N >> M;

        vector<Edge> edges(M);
        for (int i = 0; i < M; ++i) {
            cin >> edges[i].u >> edges[i].v >> edges[i].speed;
        }

        long long minSpeed = findMinSpeed(edges, N);

        cout << minSpeed << endl;
    }

    return 0;
}
