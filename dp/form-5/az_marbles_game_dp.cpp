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

int x,y;
int dp[1001][1001];
int rec(int x,int y){
    //1.pruning

    //2.base case
    if(x == 0 and y==0)return 0;

    //3.cache check
    if(dp[x][y]!=-1){
        return dp[x][y];
    }

    //4.transition/compute
    int ans = 0;
    for(int m=0;m<x;m++){
        if(rec(m,y) == 0){
            ans = 1;
            break;
        }z
    }
    for(int m=0;m<y;m++){
        if(rec(x,m) == 0){
            ans = 1;
            break;
        }
    }
    for(int m=1;m<=min(x,y);m++){
        if(rec(x-m,y-m) == 0){
            ans = 1;
            break;
        }
    }
    //5.save and return
    return dp[x][y]=ans;
}

void solve(){
 cin>>x>>y;
 memset(dp,-1,sizeof(dp));
 cout<<rec(x,y);
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

// Time Complexity: O(x*y*(x+y))
// Space Complexity: O(x*y)
// Pattern: DP Form 5 - game, opponent plays optimally
// explanation:
/*
State dp[x][y] is 1 when the player to move can force a win from piles of size x and y.
A move leaves the first pile at any smaller size, leaves the second pile at any smaller size, or reduces both piles by the same positive amount.
The transition writes 1 as soon as one of those moves reaches a cell whose value is 0.
The cell (0, 0) returns 0 because every move loop is empty.
Each pair of pile sizes is cached once, and filling that pair scans O(x+y) moves.
*/
