#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 
   bool check(vector<int>& arr,int mid,int t){
    int num=0;
    for(int i=0;i<arr.size();i++){
      num+=mid/arr[i];
      if(num>=t)return 1;
    }
    return 0;
   }
   void solve(){
     int n,t;
     cin>>n>>t;
     vector<int> arr(n);
     for(int i=0;i<n;i++){
        cin>>arr[i];
     }
     int hi,lo,mid,ans;
     hi=t*arr[0],lo=0,ans=-1;
     while(lo<=hi){
        mid=(lo+hi)/2;
        if(check(arr,mid,t)){
            ans=mid;
            hi=mid-1;
        }else{
            lo=mid+1;
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