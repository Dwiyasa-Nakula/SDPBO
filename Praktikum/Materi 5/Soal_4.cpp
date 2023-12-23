#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

void DFS(vector<vector <int> > & grid, int row, int col, int& count) {
    if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
        return;
    }

    count++;
    grid[row][col] = 0;

    // horizontal and vertical neighbors
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            DFS(grid, row + i, col + j, count);
        }
    }
}

int TemukanMaxCount(vector<vector <int> > & grid) {
    int maxCount = 0;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (grid[i][j] == 1) {
                int count = 0;
                DFS(grid, i, j, count);
                maxCount = max(maxCount, count);
            }
        }
    }
    return maxCount;
}

int main() {
    int a, b;
    cin >> a >> b;

    vector<vector <int> > grid(a, vector<int>(b));
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cin >> grid[i][j];
        }
    }

    cout << TemukanMaxCount(grid) << endl;
    return 0;
}