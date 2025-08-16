#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

void solve(){
    int N;
    cin >> N;
   // Handle the base case for a single node tree
    if (N == 1) {
        cout << 1 << "\n";
        return;
    }
    // A vector to store the degree of each node.
    // Initialize with 0. Size N+1 for 1-based indexing.
    vector<int> degree(N + 1, 0);
    // Read N-1 edges
    for (int i = 0; i < N - 1; ++i) {
        int u, v;
        cin >> u >> v;
        // For each edge, increment the degree of both connected nodes
        degree[u]++;
        degree[v]++;
    }
    // Find the maximum degree among all nodes
    int max_degree = 0;
    for (int i = 1; i <= N; ++i) { // Iterate from 1 to N for 1-based indexing
        if (degree[i] > max_degree) {
            max_degree = degree[i];
        }
    }
    // The minimum number of colors required is (maximum_degree + 1)
    cout << max_degree + 1 << "\n";
}


signed main(){

    IOS;
    int t;
    t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}