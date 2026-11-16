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

const int MOD = 1e9 + 7;
const int MAXN = 1e6 + 5;
vi memo(MAXN, -1);

// Helper function for the actual recursion
int get_ways(int n) {
    if (n == 0) return 1;
    if (n < 0) return 0;
    
    // Check memo
    if (memo[n] != -1) return memo[n];
    
    int res = 0;
    for (int i = 1; i <= 6; i++) {
        res = (res + get_ways(n - i)) % MOD;
    }
    
    return memo[n] = res;
}

// recursion + memoization
void solve() {
    int n;
    if (!(cin >> n)) return;

    cout << get_ways(n) << endl;
}

signed main()
{
    IOS;
    int t = 1; 
    // cin >> t; // Uncomment this if the input actually provides number of test cases
    while(t--){
        solve();
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: DP Form 1 - state is a level on one sequence
// explanation:
/*
State memo[s] is the number of ways to build sum s with dice faces from 1 through 6.
The transition adds the six states for s-1, s-2, s-3, s-4, s-5, and s-6.
Sum 0 has one way, the empty sequence of throws. A negative sum has zero ways.
There is one state for each sum up to n, the transition tries a constant number of faces, and the total is kept modulo 1e9+7.
*/
