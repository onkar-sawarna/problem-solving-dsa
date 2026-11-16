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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Deque - LR placement
// explanation:
/*
Each character of the length-n string is one index from 0 to n-1.
R pushes that index onto the back of left, and L pushes it onto the front of right.
The print is left, then n, then right, which is the final order of those positions.
Every index is pushed once and printed once.
The two deques together store n integers.
*/
