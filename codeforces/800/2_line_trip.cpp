#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl  "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;    

 

void solve(){
   int n,x;
   cin>>n>>x;
   vi a(n);
   a.push_back(0);
   for(int i=0;i<n;i++){
    int point;
    cin>>point;
    a.push_back(point);
   }
   a.push_back(x);
   n = a.size();
   int ans=INT_MIN;
   
   for(int i=1;i<n;i++){
       if(i==n-1){
           ans=max(ans,2*(a[i]-a[i-1]));
       }else{
          ans=max(ans,a[i]-a[i-1]);  
       }
   }
   cout<<ans<<endl;
}

signed main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}