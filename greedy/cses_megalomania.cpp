#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

   void solve(){
    int n;
    cin>>n;
    vector<pair<int,int>> p(n);
    for(int i=0;i<n;i++){
        cin>>p[i].second>>p[i].first;
    }
    sort(p.begin(),p.end());
    int start=0;
    for(auto it:p){
        if(it.first < it.second+start){
            cout<<"No";
            return;
        }
        else start+=it.second;
    }
    cout<<"Yes";
   }

    signed main()
    {
        IOS;
        solve();
        return 0;
    }