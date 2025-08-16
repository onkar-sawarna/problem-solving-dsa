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