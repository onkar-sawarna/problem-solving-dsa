#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
   int n,m;
   cin>>n>>m;
   int k_min,k_max;
   int r=n%m;
   int q=n/m;
   int mod = 1e9+7;
   k_min = (r*(q*(q+1)/2)+(m-r)*(q*(q-1)/2));
   k_max = ((n-m+1)*(n-m)/2);
   cout<<k_min<<" "<<k_max<<"\n";
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}