 /*
 Problem Statement: Given N bricks and M colors,
 find the number of ways to color the bricks such that 
 there are exactly K positions where adjacent bricks have different colors.
 (Bricks are arranged in a line and are 1-indexed)
 Each brick can be colored with any of the M colors.

 constraints:
 1 <= N <= 2000
 1 <= M <= 2000
 0 <= K < N 

 Problem Source: AZ Coding Contest 2023 (https://codeforces.com/contest/1811)
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

int N_bricks, M_colors, K_diff_positions; 

int dp[2005][2005]; 

const int MOD = 1e9 + 7;

int rec(int i, int j) {
    //1. pruning
    //--- negative differnce
    if (j < 0) {
        return 0;
    }
    //--- number of bricks less than number of colors
    if (j >= i && i > 0) {
        return 0;
    }
    //2. base case 
    // for single brick case
    if (i == 1) {
        if (j == 0) {
            return M_colors; 
        } else {
            return 0;
        }
    }
    //3. cache check
    if (dp[i][j] != -1) {
        return dp[i][j];
    }
    //4. transition/compute
    // Case 1: The ith brick has the same color as (i-1)th brick
    // So, the number of different positions remains j
    // Case 2: The ith brick has a different color than (i-1)
    // So, the number of different positions reduces by 1 (j-1)
    // And we have (M_colors - 1) choices for coloring the ith brick
    int ans = 0;
    ans = (ans + rec(i - 1, j)) % MOD;
    ans = (ans + (rec(i - 1, j - 1) * (M_colors - 1)) % MOD) % MOD;
    //5. save and return
    return dp[i][j] = ans;
}

void solve(){
    cin >> N_bricks >> M_colors >> K_diff_positions;
    //initialize it with -1
    for (int i = 0; i <= N_bricks; ++i) {
        for (int j = 0; j <= K_diff_positions; ++j) {
            dp[i][j] = -1;
        }
    }
    //call the recursion
    cout << rec(N_bricks, K_diff_positions) << endl;
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}