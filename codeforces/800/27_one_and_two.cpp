#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"
#define vin(a) for (auto& i : a) cin >> i

using pi = pair<int, int>;
using vi = vector<int>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vin(a);
    int total = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) total++;
    }
    if (total & 1) {
        cout << -1 << endl;
        return;
    }
    if (total == 0) {
        cout << 1 << endl;
        return;
    }
    int need = total / 2;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 2) cnt++;
        if (cnt == need) {
            cout << i+1 << endl;
            return;
        }
    }
    cout << -1 << endl;
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
