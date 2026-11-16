// Question: How many triples of points have their two outermost points at most distance d apart?
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

   void solve(){
     int n,d;
     cin>>n>>d;
     vector<int> arr(n);
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     int ans = 0;
     for(int i=0;i<n;i++){
        int feasible = upper_bound(arr.begin(),arr.end(),arr[i]+d)-arr.begin()-(i+1);
        // number of elements <=x ---> upper bound
        // number of elements <x ----> lower bound
        ans+=(feasible)*(feasible-1)/2;
     }
     cout<<ans<<"\n";
   }
    signed main()
    {
        IOS;
        solve();
        return 0;
    }

// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Pattern: Binary search on index - Distance triples
// explanation:
/*
For each left index i, upper_bound finds the first position in arr strictly greater than arr[i] + d.
Subtracting i + 1 leaves feasible, the count of later points that still lie within distance d.
ans adds feasible * (feasible - 1) / 2, the triples that use i as the leftmost point.
i then steps forward and upper_bound runs again from that new left endpoint.
*/
