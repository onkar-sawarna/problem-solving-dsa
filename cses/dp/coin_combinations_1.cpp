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


const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
vi memo(MAXN, -1);      

int get_ways(int n, const vi& coins) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    
    // Check memo
    if (memo[n] != -1) return memo[n];
    
    int res = 0;
    for (int coin : coins) {
        res = (res + get_ways(n - coin, coins)) % MOD;
    }
    
    return memo[n] = res;
}

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;
    vi coins(n);
    vin(coins);
    
    cout << get_ways(m, coins) << endl;
}

signed main() {
    IOS;

    int t = 1;
    // cin >> t; 

    while (t--) {
        solve();
    }

    return 0;
}