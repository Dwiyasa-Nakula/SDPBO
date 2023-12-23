#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        vector<int> graph[1001];
        bool visited[1001];

        for (int i = 0; i < m; i++) {
            int x, y;
            cin >> x >> y;
            graph[x].push_back(y);
            graph[y].push_back(x);
        }

        for (int i = 1; i <= k; i++) {
            int x;
            cin >> x;
            visited[x] = true;
        }

        // Memeriksa apakah semua node telah dikunjungi
        bool is_optimal = true;
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                is_optimal = false;
                break;
            }
        }

        if (is_optimal) {
            cout << "Gokil Wang" << endl;
        } else {
            cout << "Hadeuh Wang" << endl;
        }
    }

    return 0;
}