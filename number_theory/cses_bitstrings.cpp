#include <bits/stdc++.h>
using namespace std;
#define int long long 

int iterativeBinpow(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b%2) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}
void solve(){
   int n;
   cin>>n;
   int mod=1e9+7;
   cout<<iterativeBinpow(2,n,mod)<<"\n";
}

signed main(){
    int t;
    //cin>>t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}