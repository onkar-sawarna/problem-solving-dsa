#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
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
    string res = "";
    bool too_long = false;

    for (int i = 0; i < n; i++) {
        char c;
        int l;
        cin >> c >> l;

        if (too_long) {
            break; 
        }

        int chars_to_add = l;
        if (res.length() + chars_to_add > 100) {
            too_long = true;
            break;
        }
        
        for (int j = 0; j < chars_to_add; j++) {
            res += c;
        }
    }

    if (too_long) {
        cout << "Too Long" << endl;
    } else {
        cout << res << endl;
    }
}

signed main() {
    IOS;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}