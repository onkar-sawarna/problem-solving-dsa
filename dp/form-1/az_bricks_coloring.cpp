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