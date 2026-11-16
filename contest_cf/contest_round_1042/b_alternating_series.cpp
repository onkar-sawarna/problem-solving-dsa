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

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cout << -1;
        else {
            if (n == 2 || i== n-1) cout << 2;
            else cout << 3;
        }
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
}

signed main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}

// Time Complexity: O(T * N)
// Space Complexity: O(1)
// Pattern: Constructive - Alternating values
// explanation:
/*
One loop writes n integers.
Even indices always write -1.
An odd index writes 2 when n is 2 or the index is the last position, and writes 3 for every other odd index.
A space separates values, then a newline ends the test.
Only a handful of scalars are kept.
*/
