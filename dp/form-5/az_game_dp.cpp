// Problem Statement: Two players play a game where they take turns removing
//  a number of stones from a pile. On each turn, a player can remove any
//  power of two number of stones (1, 2, 4, 8, ...).
// The player who cannot make a move (because there are no stones left) loses.
// Given the initial number of stones x, determine if the first player has a winning strategy.  
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

int x;
int dp[100100];
int rec(int x){
    //1.pruning

    //2.base case
    if(x == 0)return 0;

    //3.cache check
    if(dp[x]!=-1){
        return dp[x];
    }

    //4.transition/compute
    int ans = 0;
    for(int m=0;(1<<m)<=x;m++){
        if(rec(x-(1<<m)) == 0){
            ans = 1;
            break;
        }
    }
    //5.save and return
    return dp[x]=ans;
}
 

void solve(){
 cin>>x;
 memset(dp,-1,sizeof(dp));
 cout<<rec(x);
}

signed main()
{
    IOS;
    int t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}