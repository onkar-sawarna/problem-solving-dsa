#include <bits/stdc++.h>
using namespace std;

// #define int long long
vector<vector<int>> allsols;
vector<int> curr_prem;
map<int,int> mp;
void solve(int level,int n){
  //base case
  if(level == n){
    allsols.push_back(curr_prem);
    return;
  }
  //recursive case
  //go through all the choices
  for(auto v:mp){
    if(v.second != 0){
        mp[v.first]--;
        curr_prem.push_back(v.first);
        solve(level+1,n);
        curr_prem.pop_back();
        mp[v.first]++;
    }
  }
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
    }
    solve(0,n);
    for (int i = 0; i < allsols.size(); ++i) {
        for (int j = 0; j < n; ++j) {
            cout << allsols[i][j];
            if (j < n - 1) {
                cout << " ";
            }
        }
        cout << "\n";
    }
}