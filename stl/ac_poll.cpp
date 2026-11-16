
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

// Time Complexity: O(n * L * log n)
// Space Complexity: O(n * L)
// Pattern: STL Map - Vote frequency
// explanation:
/*
Each of the n strings is inserted into a std::map, which keeps the keys sorted and increments that key's count.
max_len tracks the highest count seen while reading.
A second walk prints every key whose count equals that maximum, already in sorted order.
Map operations compare whole strings, so a string of length L adds that factor.
The map stores each distinct string once.
*/
