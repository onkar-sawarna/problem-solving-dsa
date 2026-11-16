// Question: How many contiguous segments of length at least k have every temperature at most q?
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int ans = 0;
    int current_streak = 0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] <= q) {
            current_streak++;
        } else {
            if (current_streak >= k) {
                ans += (current_streak - k + 1) * (current_streak - k + 2) / 2;
            }
            current_streak = 0;
        }
    }

    if (current_streak >= k) {
        ans += (current_streak - k + 1) * (current_streak - k + 2) / 2;
    }

    cout << ans << "\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// Time Complexity: O(t * n)
// Space Complexity: O(n)
// Pattern: Counting - Temperature runs
// explanation:
/*
Each test scans its array once and grows a streak while arr[i] is at most q.
When the streak breaks, a length L of at least k adds (L-k+1)*(L-k+2)/2 segments.
The same formula runs again if the array ends inside a valid streak.
Over t tests the work is linear in the total length of the arrays.
Each test stores its own n temperatures.
*/
