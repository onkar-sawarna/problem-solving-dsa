#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"

void solve() {
    int n;
    cin >> n;
    string S;
    cin >> S;
    map<char, int> last_pos;
    for (char c = 'a'; c <= 'z'; ++c)
        last_pos[c] = -1; // initialize all to -1

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        char c = S[i];
        //i-last_pos[c] indicates how many possible starting positions a substring can have, 
        //such that S[i] is the rightmost (last) occurrence of character c in that substring.
        //n - i counts how many possible ending positions a substring can have, given that it includes index i
        ans += (i - last_pos[c]) * (n - i);
        last_pos[c] = i; // update only after usage
    }
    cout << ans << endl;
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
