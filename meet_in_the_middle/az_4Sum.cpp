#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

void solve(){
    int n,x;
    cin>>n>>x;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    map<int,int> position;
    for(int b=n-2;b>=1;b--){
        for(int a=b+1;a>=0;a--){
          if(position[x-arr[a]-arr[b]]){
            cout<<"YES";
            return;
          }
        }
        int c=b;
        for(int d=c+1;d<n;d++){
            position[arr[c]+arr[d]]=1;
        }
    }
    cout<<"NO";
}

signed main(){

    IOS;
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}