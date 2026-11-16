// Question: Find the sum, over every substring, of the number of distinct characters in that substring.
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

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Contribution - Last Occurrence Span
// explanation:
/*
At index i, character c is the rightmost c for some substrings.
The left end can start anywhere after the previous c, which is i - last_pos[c] choices.
The right end can stop anywhere from i through the last index, which is n - i choices.
The product of those ranges is added, then last_pos[c] moves to i. The map has one entry per letter.
*/
