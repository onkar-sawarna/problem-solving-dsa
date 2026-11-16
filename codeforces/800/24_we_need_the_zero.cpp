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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Math - Total xor
// explanation:
/*
running_xor folds every a[i] with xor.
An odd length can use that xor as the added value, so it is printed directly.
An even length works when the fold is already 0, which prints 0.
A nonzero fold on an even length prints -1.
*/
