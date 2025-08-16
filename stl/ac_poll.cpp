
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    string s;
    cin>>n;
    map<string,int> mp;
    int max_len=0;
    for(int i=0;i<n;i++){
        cin>>s;
        mp[s]++;
        max_len = max(max_len,mp[s]);
    }
    for(auto freq:mp){
        if(freq.second == max_len)cout<<freq.first<<"\n";
    }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    //cin>>t;
     t = 1;
    while(t--){
        solve();
    }
    return 0;
}