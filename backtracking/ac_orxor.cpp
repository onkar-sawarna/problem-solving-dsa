// Question: Split the array into contiguous segments so the XOR of the bitwise OR of each segment is minimized.
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

   void solve(int level,int n,vector<int>& a,int curr_or,int intv_xor,int& ans){
     if(level == n){
        ans=min(ans,curr_or^intv_xor);
        return;
     }
     solve(level+1,n,a,curr_or|a[level],intv_xor,ans);
     solve(level+1,n,a,a[level],intv_xor^curr_or,ans);
   }

    signed main()
    {
        IOS;
        int n,ans=INT_MAX;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++)cin>>a[i];
        solve(0,n,a,0,0,ans);
        cout<<ans<<"\n";
        return 0;
    }

// Time Complexity: O(2^n)
// Space Complexity: O(n)
// Pattern: Backtracking - Segment OR XOR
// explanation:
/*
At each index the search either ORs a[level] into the open segment or closes that segment.
Closing XORs the finished OR into the running total and starts a new OR at a[level].
Two branches on every index make 2^n leaves, and each leaf keeps the smaller final XOR.
Extra memory is the recursion depth n.
*/
