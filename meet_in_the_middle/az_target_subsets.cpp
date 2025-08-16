#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 
vector<int> generate(vector<int> arr){
  int n=arr.size(),sum;
  vector<int> subsetsum;
  for(int mask=0;mask<(1<<n);mask++){
    sum=0;
    for(int j=0;j<n;j++){
        if((mask>>j)&1)sum+=arr[j];
    }
    subsetsum.push_back(sum);
  }
  sort(subsetsum.begin(),subsetsum.end());
  return subsetsum;
}
int solve(){
   int n,x,ans=0;
   cin>>n>>x;
   vector<int> arr(n);
   vector<int> subarr[2];
   for(int i=0;i<n;i++){
     cin>>arr[i];
     subarr[i&1].push_back(arr[i]);
   }
   vector<int> sub0 = generate(subarr[0]);
   vector<int> sub1 = generate(subarr[1]);
   for(auto v:sub0){
     ans+=upper_bound(sub1.begin(),sub1.end(),x-v)-sub1.begin(); // <=x
   }
   return ans;
}

signed main(){

    IOS;
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
    return 0;
}