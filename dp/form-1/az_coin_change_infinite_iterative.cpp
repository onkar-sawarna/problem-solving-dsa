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
   int n,m;
   int x[n];
   for(int i=0;i<n;i++){
    cin>>x[i];
   }
   int dp[n+1][m+1];

   for(int l=n;l>=0;l--){
    for(int s=0;s<=m;s++){
        //compute for (l,s)
        if(l==n){
            if(s==0){
                dp[l][s]=1;
            }else{
                dp[l][s]=0;
            }
        }
        //general
        dp[l][s]=0;
        if(dp[l+1][s]){
          dp[l][s]=1;
        }
        if(s>=x[l] and dp[l][s-x[l]]){
            dp[l][s]=1;
        }
      }
   }
   cout<<dp[0][m]<<endl;
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