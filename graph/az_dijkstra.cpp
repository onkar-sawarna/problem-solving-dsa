#include <bits/stdc++.h> 

using namespace std; 

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

#define int long long 

using pi = pair<int, int>; 

const long long INF = 1e18; 

vector<long long> dijkstra(int n, const vector<vector<pi>>& adj, int source) {
    vector<long long> dist(n + 1, INF); 
    vector<bool> visited(n + 1, false); // Add visited array

    priority_queue<pi, vector<pi>, greater<pi>> pq;

    dist[source] = 0;
    pq.push({0, source}); 

    while (!pq.empty()) {
        long long d = pq.top().first; 
        int u = pq.top().second;      
        pq.pop();

        // Check if already finalized (visited)
        if (visited[u]) { // If already processed with its final shortest distance
            continue;
        }
        visited[u] = true; // Mark as visited (distance finalized)

        for (const auto& edge : adj[u]) {
            int v = edge.first;         
            int weight = edge.second;   

            if (dist[u] + weight < dist[v]) { 
                dist[v] = dist[u] + weight; 
                pq.push({dist[v], v});      
            }
        }
    }

    return dist; 
}

void solve(){
    int n, m;
    cin >> n >> m;

    vector<vector<pi>> graph_adj(n + 1); 

    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph_adj[u].push_back({v, w});
    }

    int source_node = 1; 

    vector<long long> shortest_distances = dijkstra(n, graph_adj, source_node);

    cout << "Shortest distances from node " << source_node << ":" << endl;
    for (int i = 1; i <= n; ++i) {
        if (shortest_distances[i] == INF) {
            cout << "To node " << i << ": Unreachable" << endl;
        } else {
            cout << "To node " << i << ": " << shortest_distances[i] << endl;
        }
    }
}

signed main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}