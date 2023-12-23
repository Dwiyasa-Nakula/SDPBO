#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
#include <stack>
using namespace std;

void printPaths(const map<int, vector<int>>& paths) {
    for (const auto& entry : paths) {
        int current = entry.first;
        const vector<int>& neighbors = entry.second;

        for (int neighbor : neighbors) {
            cout << current << " " << neighbor << endl;
        }
    }
}

void findShortestPaths(const map<int, vector<int>>& paths, int start, int destination) {
    stack<vector<int>> s;
    vector<int> visited(paths.size(), false);
    s.push({start});

    while (!s.empty()) {
        vector<int> currentPath = s.top();
        s.pop();
        int currentCity = currentPath.back();

        if (currentCity == destination) {
            for (int i = 0; i < currentPath.size(); ++i) {
                cout << currentPath[i];
                if (i % 2 == 0 && i + 1 < currentPath.size()) {
                    cout << " ";
                }
            }
            cout << endl;
            continue;
        }

        for (int nextCity : paths.at(currentCity)) {
            if (!visited[nextCity]) {
                visited[nextCity] = true;
                vector<int> newPath = currentPath;
                newPath.push_back(nextCity);
                s.push(newPath);
            }
        }
    }
}

int main() {
    vector<pair<int, int>> edges;
    int u, v;

    while (cin >> u >> v && !(u == -1 && v == -1) && (u != v)) {
        edges.push_back({u, v});
    }

    map<int, vector<int>> paths;

    for (const auto& edge : edges) {
        paths[edge.first].push_back(edge.second);
    }

    printPaths(paths);

    findShortestPaths(paths, 0, 5);

    return 0;
}
