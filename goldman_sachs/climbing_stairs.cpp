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

int dp[50];
int rec(int level) {
    // base cases
    if(level == 0) return 1;  // 1 way to stand still
    if(level < 0) return 0;   // no ways for negative steps
    
    // check memo cache
    if(dp[level] != -1) return dp[level];
    
    // compute and cache
    int ans = 0;
    ans += rec(level - 1);
    ans += rec(level - 2);
    
    return dp[level]=ans;
}
void solve(){
    int n;
    cin>>n;
    memset(dp, -1, sizeof(dp));
    cout<<rec(n)<<endl;
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