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


int rec(int n, const vi& coins, vector<int>& memo) {
    if (n == 0) return 0; // 0 coins needed to make sum 0
    if (n < 0) return LLONG_MAX; // impossible case
    
    // Check memo
    if (memo[n] != -1) return memo[n];
    
    int res = LLONG_MAX;
    for (int coin : coins) {
        int sub_res = rec(n - coin, coins, memo);
        if (sub_res != LLONG_MAX) {
            res = min(res, sub_res + 1); // +1 for the current coin
        }
    }
    
    return memo[n] = res;
}

void solve(){
    int n, m;
    if (!(cin >> n >> m)) return;
    vi coins(n);
    vin(coins);
    
    vector<int> memo(m + 1, -1);
    int ans = rec(m, coins, memo);
    cout << (ans == LLONG_MAX ? -1 : ans) << endl; // If impossible, print -1
}

signed main()
{
    IOS;
    int t = 1;
    //cin>>t;
    while(t--){
     solve();
    }
    return 0;
}