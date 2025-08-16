#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(){
   int n;
   cin>>n;
   int arr[n];
   for(int i=0;i<n;i++){
    cin>>arr[i];
   }
   sort(arr,arr+n);
   int ans;
   ans=n*(n-1)/2;
   if(arr[0]== arr[n-1]){
    cout<<"0"<<" "<<ans<<"\n";
    return;
   }
   int mincount=1;
   int maxcount=1;
   for(int i=1;i<n;){
    if(arr[0] == arr[i]){
        mincount++;
        i++;
    }
    else{
        break;
    }
   }
   for(int i=n-2;i<n;){
    if(arr[n-1] == arr[i]){
        maxcount++;
        i--;
    }else{
        break;
    }
   }
  cout<<arr[n-1]-arr[0]<<" "<<mincount*maxcount<<"\n";
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