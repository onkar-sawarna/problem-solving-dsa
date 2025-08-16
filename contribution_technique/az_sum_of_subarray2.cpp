#include <bits/stdc++.h>
using namespace std;
#define int long long 

//Extending contribution
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int prev_sum=0;
    int ans = 0;
    for(int i=0;i<n;i++){
      prev_sum = prev_sum+arr[i]*(i+1);
      ans+=prev_sum;
    }
    cout<<ans<<"\n";
    return 0;
}
