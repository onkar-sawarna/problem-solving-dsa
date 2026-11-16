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

// True if the array can be split into at most k contiguous pieces,
// each with sum <= limit.
bool can_divide(const vi& a, int k, int limit) {
    int pieces = 1;
    int sum = 0;
    for (int x : a) {
        if (sum + x > limit) {
            pieces++;
            sum = x;
        } else {
            sum += x;
        }
    }
    return pieces <= k;
}

// Binary search the smallest maximum subarray sum.
void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vi a(n);
    vin(a);

    int lo = *max_element(a.begin(), a.end());
    int hi = accumulate(a.begin(), a.end(), 0LL);
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (can_divide(a, k, mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << endl;
}

signed main()
{
    IOS;
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}

// Time Complexity: O(n log S)
// Space Complexity: O(1)
// Pattern: Binary Search on the Answer - greedy pack check
// explanation:
/*
The searched limit runs from the largest array value up to the sum of the array, and S is the width of that range.
can_divide scans left to right and starts a new contiguous piece whenever the next value would push the current piece over the candidate limit.
The candidate is accepted when the number of pieces is at most k.
A successful mid lowers the high end, and a failed mid raises the low end.
Each of the O(log S) candidates costs one O(n) scan, and only a few integers are stored besides the input array.
*/
