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