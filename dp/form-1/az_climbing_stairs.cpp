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

int n;
int dp[100100];

int rec(int level){
   //1. pruning
   if(level>n){
    return 0;
   }
   //2. base case
   if(level==n){
    return 1;
   }
   //3. cache check
   if(dp[level]!=-1){
    return dp[level];
   }
   int ans = 0;
   //4. transition i.e loop over choice
   for(int step=1;step<=3;step++){
    if(level+step<=n){
        //check if its valid choice
        int ways = rec(level+step);//move
        ans+=ways;
    }
   }
   //5. save and return
   return dp[level]=ans;
}
 

void solve(){
   cin>>n;
   memset(dp,-1,sizeof(dp));
   rec(1);
}

signed main()
{
    IOS;
    int t;
    // cin>>t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}