#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin>>n;
    int base = 1378%10;
    if(n==0)
    {cout<<"1"<<"\n"; 
        return;
    }
    n=n%4;
    if(n==0)n=4;
    int last_digit = 1;
    for(int i=0;i<n;i++){
        last_digit = (last_digit*base)%10;
    }
    cout<<last_digit<<"\n";
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