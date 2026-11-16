// Question: How many bit strings of length n are there, modulo 10^9+7?
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

// Time Complexity: O(log n)
// Space Complexity: O(1)
// Pattern: Number Theory - Modular power of two
// explanation:
/*
The number of bit strings of length n is 2^n, printed modulo 1000000007.
iterativeBinpow squares the base and halves the exponent, multiplying the answer when the current bit is set.
The loop follows the bits of n.
A few integers hold the base, the exponent, and the running product.
*/
