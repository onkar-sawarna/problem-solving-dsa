#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
using pi =  pair<int,int>;
using  vec = vector<int>;

void solve(){
    int n, m;
    cin >> n >> m;

    // Correctly initialize v with size m + 1 (or m depending on precise indexing needs)
    // The maximum index for v is m-p[i].first. If p[i].first can be 1, max index is m-1.
    // If p[i].first can be 0, max index is m. So, m+1 covers all cases.
    vector<vec> v(m + 1);

    for(int i = 0; i < n; i++){
        int first_val, second_val;
        cin >> first_val >> second_val;
        if(first_val > m) continue;
        // Store 'second_val' in the list corresponding to 'm - first_val' days left.
        v[m - first_val].push_back(second_val);
    }

    priority_queue<int> pq;
    int ans = 0;

    // Iterate backwards from m-1 down to 0 (or 1 depending on problem context)
    // Assuming 'i' represents the number of days remaining.
    for(int i = m - 1; i >= 0; i--){ // Changed from i>=1 to i>=0 to cover day 0 if needed
                                     // Based on original problem, iterating down to 1 might be correct.
                                     // If days are 1 to m, then m-1 to 0 makes sense for 0-indexed array.
                                     // The current i in the loop means "days remaining for the task to be done by deadline m".
                                     // If a task has deadline `d` and takes `t` days, `m-t` means `t` days before deadline.
                                     // Original `i >= 1` might be correct for a 1-indexed "day" concept.
                                     // Let's stick to original `i >= 1` for now, assuming problem context makes it valid.
        for(auto x : v[i]){
            pq.push(x);
        }
        if(pq.size() > 0){
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans << "\n"; // Removed the extra space after ans and " " before \n
}

    signed main()
    {
        IOS;
        solve();
        return 0;
    }