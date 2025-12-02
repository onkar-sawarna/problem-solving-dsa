#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl  "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;

void solve() {
    int n;
    cin >> n;
    set<int> answers;

    int power_of_10 = 10;
    for (int k = 1; k <= 18; ++k) {
        int divisor = 1 + power_of_10;

        if (n % divisor == 0) {
            int x = n / divisor;
            if (x % 10 != 0) {  
                answers.insert(x);
            }
        }
        power_of_10 *= 10;
    }

    cout << answers.size() << "\n";
    bool first = true;
    for (int val : answers) {
        if (!first) cout << " ";
        cout << val;
        first = false;
    }
    if (!answers.empty()) cout << "\n";
}

signed main() {
    IOS;
    int t; cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
