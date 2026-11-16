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
int n,m;
int grid[1010][1010];
int dp[1010][1010];
int rec(int i,int j){
    //1. pruning 
    if(i>=n || j>=m || grid[i][j]==1)return 0;
    //2.base case
    if(i==n-1 and j== m-1)return 1;
    //3.cache check
    if(dp[i][j]!=-1)return dp[i][j];
    //4.transition/compute
    int ans = 0;
    if(grid[i][j]!=1){
        ans= (ans+ rec(i+1,j))%MOD;
        ans= (ans + rec(i,j+1))%MOD;
    }

    //5.save and return
    return dp[i][j]= ans;
}

void solve(){
  cin>>n>>m;
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>grid[i][j];
    }
  }
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,0)<<endl;
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

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Pattern: DP Form 2 - best that ends here (Kadane, LIS, grid cell)
// explanation:
/*
State dp[i][j] is the number of ways to reach the bottom-right starting from cell (i, j), moving only down or right.
A coordinate outside the grid, or a cell whose value is 1, returns 0.
The open cell (n-1, m-1) returns 1.
The transition adds the ways from the cell below and the ways from the cell to the right, modulo 1e9+7.
One state is stored per grid cell, and each state makes those two moves.
*/
