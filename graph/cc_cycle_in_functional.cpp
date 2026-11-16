// Question: How many nodes lie on a cycle when each index i points to (i + 1 + a[i]) modulo n?
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl  "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;


void solve() {
    int n;
    cin >> n;
    vi a(n);
    vin(a);
    vi adj(n);
    vi ind(n, 0);
    for(int i = 0; i<n; i++){
        adj[i] = (i+1+a[i])%n;
        ind[adj[i]]++;
    }

    queue<int> q;
    for(int i = 0; i<n; i++){
        if(ind[i]==0){
            q.push(i);
        }
    }

    int cnt = 0;
    while(!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        ind[adj[u]]--;
        if(ind[adj[u]]==0){
            q.push(adj[u]);
        }
    }

    cout << n - cnt << endl;
}

signed main() {
    IOS;
    int T; cin >> T;
    while (T--) solve();
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Kahn - Functional graph cycles
// explanation:
/*
adj[i] is the single successor (i + 1 + a[i]) modulo n, and ind counts incoming edges.
Every node with indegree 0 starts in the queue.
Popping a node decreases the indegree of its successor, which is pushed if that count hits 0.
The printed value is n minus how many nodes were removed, the nodes that remain on cycles.
*/
