#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
    int n;
    string s;
    cin>>n>>s;
    deque<int> left,right;
    int cur=0;
    for(int i=0;i<n;i++){
        if(s[i] == 'R')left.push_back(i);
        else right.push_front(i);
        cur+=1;
    }
    for(auto l:left)cout<<l<<" ";
    cout<<cur<<" ";
    for(auto r:right)cout<<r<<" ";
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