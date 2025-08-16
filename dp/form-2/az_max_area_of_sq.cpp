#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"

int grid[1001][1001];
int dp[1001][1001];
int n_rows, m_cols;
int max_side_length_overall;

int rec(int r, int c) {
    //pruning and base case
    if (r < 0 || c < 0 || grid[r][c] == 0) {
        return 0;
    }
    // cache check
    if (dp[r][c] != -1) {
        return dp[r][c];
    }
    // compute
    int res = 1 + min({rec(r - 1, c), rec(r, c - 1), rec(r - 1, c - 1)});

    max_side_length_overall = max(max_side_length_overall, res);

    //save and return 
    return dp[r][c] = res;
}

void solve() {
    cin >> n_rows >> m_cols;

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            cin >> grid[i][j];
            dp[i][j] = -1;
        }
    }

    max_side_length_overall = 0;

    for (int i = 0; i < n_rows; ++i) {
        for (int j = 0; j < m_cols; ++j) {
            rec(i, j);
        }
    }

    cout << max_side_length_overall * max_side_length_overall << endl;
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