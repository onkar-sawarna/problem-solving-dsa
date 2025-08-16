#include <bits/stdc++.h>
using namespace std;
#define int long long 
 
void solve() {
    string s;
    cin >> s;
    int first = s[0] - 'a';
    int last = s[1] - 'a';
    int index = first * 25;
    if (first>last) {
        index += last+1;
    } else {
        index += last;
    }
    cout << index << "\n";
}
 
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}