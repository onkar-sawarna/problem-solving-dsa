#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;          

const int INF = 1e18; 

void solve(){
    int n, m, q;
    cin >> n >> m >> q;

    vvi dp(n + 1, vi(n + 1, INF)); 

    for(int i = 1; i <= n; ++i){
        dp[i][i] = 0;
    }

    for(int i = 0; i < m; ++i){
        int u, v, c;
        cin >> u >> v >> c;
        dp[u][v] = min(dp[u][v], c); 
        dp[v][u] = min(dp[v][u], c); 
    }

    for(int k = 1; k <= n; ++k){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                if(dp[i][k] != INF && dp[k][j] != INF){
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
                }
            }
        }
    }

    for(int i = 0; i < q; ++i){
        int a, b;
        cin >> a >> b;
        if(dp[a][b] == INF){
            cout << -1 << "\n";
        } else {
            cout << dp[a][b] << "\n";
        }
    }
}

signed main()
{
    IOS;
    int t = 1; 
    // cin >> t; 
    while(t--){
     solve();
    }
    return 0;
}