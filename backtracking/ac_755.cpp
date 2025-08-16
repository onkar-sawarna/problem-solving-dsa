#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

   void solve(int current,int& ans,int seen3,int seen5,int seen7,int n){
     if(current>n)return;
     if(current <= n && seen3 && seen5 && seen7){
        ans++;
     }
     solve(current*10+3,ans,1,seen5,seen7,n);
     solve(current*10+5,ans,seen3,1,seen7,n);
     solve(current*10+7,ans,seen3,seen5,1,n);
   }

    signed main()
    {
        IOS;
        int n;
        cin>>n;
        int ans=0;
        solve(0,ans,0,0,0,n);
        cout<<ans<<"\n";
        return 0;
    }