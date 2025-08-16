#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;          


void prefixsum(vector<int>& arr,int index,int n){
  vector<int> sum(n);
  sum[0] = arr[index];
  cout<<sum[0]<<" ";
  for(int i=1;i<n;i++){
    sum[i] = sum[i-1]+arr[i+index];
    cout<<sum[i]<<" ";
  }
  cout<<"\n";
} 

void solve(){
  int n;
  cin>>n;
  vector<int> arr(n-1,0);
  for(int i=0;i<n-1;i++){
    cin>>arr[i];
  }
  for(int i=0;i<n-1;i++){
    prefixsum(arr,i,n-1-i);
  }
  
}

signed main()
{
    IOS;
    int t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}