// Question: How many paths go from the top-left to the bottom-right of the grid, moving only right or down and avoiding traps?
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
int n;
char grid[1010][1010];
int dp[1010][1010];

int rec(int i,int j){
    //1. pruning 
    if(i>=n || j>=n || grid[i][j] == '*')return 0;
    //2.base case
    if(i==n-1 and j== n-1)return 1;
    //3.cache check
    if(dp[i][j]!=-1)return dp[i][j];
    //4.transition/compute
    int ans = 0;
    if(grid[i][j]!='*'){
    ans= (ans+ rec(i+1,j))%MOD;
    ans= (ans + rec(i,j+1))%MOD;
    }
    //5.save and return
    return dp[i][j]= ans;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>grid[i][j];
        }
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,0)<<endl;
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

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// Pattern: DP Form 2 - best that ends here (Kadane, LIS, grid cell)
// explanation:
/*
State dp[i][j] is the number of paths from cell (i, j) to the opposite corner of the n by n grid.
A move goes one step down or one step right. A cell outside the grid, or a cell that holds '*', returns 0.
The corner (n-1, n-1) returns 1 when it is free.
The transition adds the downward path and the rightward path, modulo 1e9+7.
The table stores one value per cell, and each cell makes those two moves.
*/
