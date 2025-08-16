#include<bits/stdc++.h>
using namespace std;

struct mexfinder{
    map<int,int> freq;
    set<int> np;
    mexfinder(int n){
        for(int i=0;i<=n;i++){
            np.insert(i);
        }
    }
    void insert(int x){
        freq[x]++;
        if(freq[x]==1){
            np.erase(x);
        }
    }
    void erase(int x){
        freq[x]--;
        if(freq[x]==0){
            np.insert(x);
        }
    }
    int getmex(){
        return *np.begin();
    }
};

void solve(){
    int n,m;
    cin>>n>>m;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int minmex = 1e9;
    mexfinder ds(n);
    for(int i=0;i<n;i++){
        ds.insert(arr[i]);
        if(i-m>=0)ds.erase(arr[i-m]);
        if(i-m+1>=0){
            minmex = min(minmex,ds.getmex());
        }
    }
    cout<<minmex<<endl;

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t=1;
    while(t--){
        solve();
    }
}