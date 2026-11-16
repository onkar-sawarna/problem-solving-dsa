#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"

const int MOD = 1e9 + 7;

int grid[1001][1001];
int dp[1001][1001];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            dp[i][j] = 0;
        }
    }

    if (grid[0][0] == 1) {
        cout << 0 << endl;
        return;
    }

    dp[0][0] = 1;
    //1st row
    for (int j = 1; j < m; ++j) {
        if (grid[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
        } else {
            dp[0][j] = 0;
        }
    }
    //first column
    for (int i = 1; i < n; ++i) {
        if (grid[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
        } else {
            dp[i][0] = 0;
        }
    }

    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            if (grid[i][j] == 1) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n - 1][m - 1] << endl;
}

signed main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Pattern: DP Form 2 - best that ends here (Kadane, LIS, grid cell)
// explanation:
/*
State dp[i][j] is the number of ways to reach cell (i, j) from the top-left, moving only right or down.
An open start cell is 1. A cell whose grid value is 1 stores 0.
An open interior cell adds the ways stored in the left neighbor and the upper neighbor.
The first row copies only from the left, and the first column copies only from above.
One cell is filled per grid position, each in constant time, and sums are taken modulo 1e9+7.
*/
