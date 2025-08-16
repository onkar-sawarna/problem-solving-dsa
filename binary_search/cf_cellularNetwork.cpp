#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    int max_min_dist = 0;

    for (int i = 0; i < n; i++) {
        auto it = lower_bound(b, b + m, a[i]);
        int min_dist_city = 2e9;

        // Check the tower found by lower_bound (if any)
        if (it != b + m) {
            min_dist_city = min(min_dist_city, abs(*it - a[i])); // Use abs for distance
        }

        // Check the tower immediately before the one found (if any)
        if (it != b) {
            auto prev_it = it;
            prev_it--;
            min_dist_city = min(min_dist_city, abs(*prev_it - a[i])); // Use abs for distance
        }

        max_min_dist = max(max_min_dist, min_dist_city);
    }

    cout << max_min_dist << "\n";
}

signed main() {
    IOS;
    solve();
    return 0;
}