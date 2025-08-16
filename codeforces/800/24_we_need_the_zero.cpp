#include <bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define endl "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;

void solve() {
    int n;
    cin >> n;
    vi a(n);
    vin(a);
    int running_xor = 0;
    for (int x : a) running_xor ^= x;
    if (n % 2 == 1) {
        cout << running_xor << endl;
    } else {
        if (running_xor == 0)
            cout << 0 << endl; 
        else
            cout << -1 << endl;
    }
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
