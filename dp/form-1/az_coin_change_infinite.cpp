/*
 Problem Statement: You are given an integer array of coins of different denominations
 and an integer amount representing a total amount of money.
 Return true if the amount can be made up by any combination of the coins.
 You may assume that you have an infinite number of each kind of coin.

 Problem Source: Classic Unbounded Knapsack/Coin Change problem.
*/
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

int n,m;
int x[1001];
int dp[1001][5];

int rec(int level,int sum_left){
    //1.pruning
    if(sum_left<0)return 0; 

    //2.base case
    if(level == n){
        if(sum_left==0){
            return 1;
        }else{
            return 0;
        }
    }

    //3.cache check
    if(dp[level][sum_left]!=-1){
        return dp[level][sum_left];
    }

    //4.compute
    int ans = 0;
    ans = rec(level+1,sum_left)||rec(level,sum_left-x[level]);

    //5.save and return
    return dp[level][sum_left] = ans;
}

void solve(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
     cin>>x[i];
    }
    memset(dp,-1,sizeof(dp));
    cout<<rec(0,m);
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

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Pattern: DP Form 1 - state is a level on one sequence
// explanation:
/*
State dp[level][sum_left] is 1 when coins from index level onward can make sum_left, with each coin usable any number of times.
The transition succeeds when skipping to level+1 succeeds, or when paying one x[level] and staying at level succeeds.
A negative sum_left returns 0. At level n the result is 1 only for a remaining sum of 0.
The table is indexed by the coin index and the remaining sum, and each cell tries those two branches.
*/
