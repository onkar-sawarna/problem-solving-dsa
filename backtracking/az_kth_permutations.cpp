#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

void solve(int n, int k, vector<int>& arr, vector<int>& fact, vector<int>& ans) {
    if (n == 0) {
        return;
    }
    int f = fact[n - 1];
    int index = (k - 1) / f;// 0 based indexing
    ans.push_back(arr[index]);
    arr.erase(arr.begin() + index);
    solve(n - 1, k-f*index, arr, fact, ans);
}

signed main(){

    IOS;
    int n,k;
    cin>>n>>k;
    vector<int> arr,fact(n+1,1);
    for(int i=1;i<=n;i++){
      arr.push_back(i);
      fact[i]=i*fact[i-1];
    }
    vector<int> ans;
    solve(n,k,arr,fact,ans);
    for(int i=0;i<n;i++){
      cout<<ans[i]<<" ";
    }
    return 0;
}