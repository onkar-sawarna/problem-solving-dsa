// Question: In how many ways can 3n children, split into groups of three, each receive 1, 2, or 3 candies so that at least one group does not sum to 6, modulo 10^9+7?
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

// Time Complexity: O(log n)
// Space Complexity: O(1)
// Pattern: Number Theory - Modular difference of powers
// explanation:
/*
The printed value is (27^n - 7^n) modulo 1000000007.
Each power is iterative binary exponentiation: square the base and halve the exponent.
The two loops together follow the bits of n.
A multiple of the modulus is added before the subtraction so the residue stays non-negative.
Only a few integers are stored.
*/
