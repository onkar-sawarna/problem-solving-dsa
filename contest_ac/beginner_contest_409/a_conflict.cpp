#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
using pi = pair<int, int>;       // Alias for pair<long long, long long>
using vi = vector<int>;          // Alias for vector<long long>
using vvi = vector<vi>;          // Alias for vector<vector<long long>>

 

   void solve(){
    int n;
    string t,a;
    cin>>n>>t>>a;
    int flag = 0;
    for(int i=0;i<n;i++){
        if(t[i]=='o' and a[i] == 'o'){
            cout<<"Yes";
            flag=1;
            break;
        }
    }
    if(flag!=1)cout<<"No";
   }

    signed main()
    {
        IOS;
        solve();
        return 0;
    }