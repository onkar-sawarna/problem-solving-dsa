#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    

 
   bool check(int mid,int n,int m,int k){
    int cnt=0;
    for(int i=1;i<=n;i++){
       cnt+=min(mid/i,m); //numbers <=x in each row
    }
    return cnt>=k;// (total numbers <=x) >=k
   } 
   void solve(){
     int n,m,k;
     cin>>n>>m>>k;
     int lo,hi,mid;
     lo = 1,hi=n*m;
     int ans = -1;
     while(lo<=hi){
        mid = (lo+hi)/2;
        if(check(mid,n,m,k)){
            ans = mid;
            hi = mid-1;
        }else {
            lo = mid+1;
        }
     }
     cout<<ans<<"\n";
   }

    signed main()
    {
        IOS;
        solve();
        return 0;
    }