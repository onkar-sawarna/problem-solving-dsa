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
    vector<string> s(n);
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    set<string> unique_concatenations;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (i == j) {
                continue; 
            }
            unique_concatenations.insert(s[i] + s[j]);
        }
    }

    cout << unique_concatenations.size() << endl;
}

signed main()
{
    IOS;
    int t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}

// Time Complexity: O(N^2 * L * log N)
// Space Complexity: O(N^2 * L)
// Pattern: Brute Force - All ordered pairs
// explanation:
/*
i and j both run over the n strings, and the case i == j is skipped.
Each remaining pair is concatenated and inserted into a set.
Equal concatenations collapse to one entry.
The printed number is the size of that set.
L is one input string length; storing and comparing a concatenation scales with L and with the logarithm of the set.
*/
