#include <iostream>
#include <vector>
#include <algorithm>
#include <climits> // Include <climits> for INT_MAX
using namespace std;

void printMatrix(const vector<vector<int>>& matrix) {
    for (const auto& row : matrix) {
        cout << "  ";
        for (int cost : row) {
            cout << cost << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

void printPath(const vector<int>& path) {
    for (int city : path) {
        cout << city << " ";
    }
    cout << path[0] << endl;
}

int kalkulasi(const vector<int>& path, const vector<vector<int>>& matrix) {
    int cost = 0;
    for (vector<int>::size_type i = 0; i < path.size() - 1; ++i) {
        cost += matrix[path[i] - 1][path[i + 1] - 1];
    }
    cost += matrix[path.back() - 1][path.front() - 1];
    return cost;
}



void findShortestPath(int n, const vector<vector<int>>& matrix) {
    vector<int> kota;
    for (int i = 1; i <= n; ++i) {
        kota.push_back(i);
    }

    int minCost = INT_MAX;
    vector<int> minPath;

    do {
        int currentCost = kalkulasi(kota, matrix);

        if (currentCost < minCost) {
            minCost = currentCost;
            minPath = kota;
        }

    } while (next_permutation(kota.begin(), kota.end()));

    printMatrix(matrix);

    printPath(minPath);

    cout << minCost << endl;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> matrix(n, vector<int>(n));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> matrix[i][j];
        }
    }

    findShortestPath(n, matrix);

    return 0;
}
