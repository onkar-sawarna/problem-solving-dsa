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

#include <bits/stdc++.h>
using namespace std;

signed main() {
    int tt; cin >> tt;
    while (tt--) {
        int a, b, k; 
        cin >> a >> b >> k;
        if (max(a, b) / __gcd(a, b) <= k)
            cout << 1 << endl;
        else
            cout << 2 << endl;
    }
}

// Time Complexity: O(T log A)
// Space Complexity: O(1)
// Pattern: Math - GCD test
// explanation:
/*
Each test reads a, b, and k.
__gcd(a, b) is the Euclidean algorithm, shrinking the pair by repeated division.
The test compares max(a, b) / gcd with k.
A ratio that fits in k prints 1. A larger ratio prints 2.
No arrays are allocated.
*/
