#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"
#define vin(a) for (auto &i : a) cin >> i
#define vout(a) for (const auto &i : a) cout << i << " "
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

void solve() {
    int n, c;
    cin >> n >> c;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ms.insert(x);
    }
    int cnt = 0;
    while (!ms.empty()) {
        auto it = ms.upper_bound(c);  
        if (it == ms.begin()) {
            cnt++;
            ms.erase(ms.begin());
        } else {
            it--;
            ms.erase(it);
        }
        multiset<int> temp;
        for (auto x : ms) {
            temp.insert(x * 2);
        }
        ms = move(temp);
    }
    cout << cnt << endl;
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
