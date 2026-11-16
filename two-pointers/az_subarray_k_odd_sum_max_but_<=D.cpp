// Question: What is the largest subarray sum that is at most D and contains at most K odd numbers?
#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int N, K, D;
    cin >> N >> K >> D;
    vector<int> A(N);
    for (int &x : A) cin >> x;

    vector<int> prefix(N + 1, 0);
    for (int i = 0; i < N; ++i) prefix[i + 1] = prefix[i] + A[i];

    multiset<int> ms;
    ms.insert(0);  // For subarrays starting at index 0.

    int left = 0, odd = 0, ans = LLONG_MIN / 2;
    for (int right = 0; right < N; ++right) {
        if (A[right] % 2) odd++;
        while (left <= right && odd > K) {
            ms.erase(ms.find(prefix[left]));
            if (A[left] % 2) odd--;
            left++;
        }
        // Now, [left, right] has <= K odd numbers.
        // To maximize (prefix[r+1] - s) ≤ D, find s ≥ (prefix[r+1] - D)
        int target = prefix[right + 1] - D;
        auto it = ms.lower_bound(target);
        if (it != ms.end()) {
            int candidate = prefix[right + 1] - *it;
            ans = max(ans, candidate);
        }
        ms.insert(prefix[right + 1]);
    }
    if (ans == LLONG_MIN / 2) cout << "IMPOSSIBLE\n";
    else cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Pattern: Sliding window - Prefix multiset
// explanation:
/*
prefix[i + 1] is the sum of A up to i, and ms holds prefixes of the open window, starting with 0.
right walks from 0 to N - 1, and each odd A[right] increases odd.
While odd is greater than K, the prefix at left is erased from ms and left steps forward.
lower_bound on ms finds the smallest kept prefix that is at least prefix[right + 1] - D, and the best difference is kept.
*/
