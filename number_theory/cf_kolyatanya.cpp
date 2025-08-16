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
    int mod = 1e9+7;
    int exp1 = 27;
    int exp2 = 7;

    int ans = ((iterativeBinpow(exp1,n,mod) - iterativeBinpow(exp2,n,mod))+mod)%mod;
    cout<<ans<<"\n";
    return;
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