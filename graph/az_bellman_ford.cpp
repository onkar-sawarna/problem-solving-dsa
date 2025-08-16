#include <bits/stdc++.h>

using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

#define int long long

const long long INF = 4e14;

struct Edge {
    int u, v, weight;
};

void solve() {
    int n, m;
    cin >> n >> m;

    vector<Edge> edges;
    for (int i = 0; i < m; ++i) {
        int u, v, x;
        cin >> u >> v >> x;
        edges.push_back({u, v, x}); 
    }

    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    for (int k = 1; k <= n; ++k) {
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            int weight = edge.weight;

            if (dist[u] != INF && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                if (k == n) {
                    dist[v] = -INF;
                }
            }
        }
    }

    for (int k = 1; k <= n; ++k) {
        for (const auto& edge : edges) {
            int u = edge.u;
            int v = edge.v;
            if (dist[u] == -INF) {
                dist[v] = -INF;
            }
        }
    }

    if (dist[n] == -INF) {
        cout << -1 << endl; //contains cycle
    } else {
        cout << dist[n] << endl; //shortest path 
    }
}

signed main() {
    IOS;
    solve();
    return 0;
}