#include <bits/stdc++.h>
using namespace std;
#define int long long 
int mod = 1e9+7;
int iterativeBinpow(int a,int b,int mod){
    int ans=1;
    while(b){
        if(b%2) ans=(ans*a)%mod;
        a=(a*a)%mod;
        b=b/2;
    }
    return ans;
}

int recursiveBinpow(int a,int b,int mod){
    int ans=1;
    if(b==0 || (a==0 &&  b == 0))return 1;
    else if(b%2) return (a*recursiveBinpow(a,b-1,mod))%mod;
    else{
        int temp = (a*a)%mod;
        return recursiveBinpow(temp,b/2,mod);
    }
}
int inverse(int b,int mod){
    return iterativeBinpow(b%mod,mod-2,mod);
}

int fact(int x) { 
	int ans = 1; 
	for(int i=2; i<=x; i++) { 
		ans = (ans * i) % mod;
	} 
	return ans; 
}

int ncr(int n, int r) {    // O(n + r)
	int num = fact(n);
	int den = (fact(r) * fact(n-r)) % mod;
	return (num * inverse(den,mod))% mod;
}
signed main()
{
   int a,b,n;
   cin>>n;
   while(n--){
    cin>>a>>b;
    int mod = 1e9+7;
    cout<<iterativeBinpow(a%mod,b,mod)<<"\n";
   }
   
//   cout<<recursiveBinpow(a%mod,b,mod)<<"\n";
   // cout<<inverse(b,mod)<<"\n";
   
   return 0;
}