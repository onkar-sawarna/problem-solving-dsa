// There are N items [N <= 100 and Xi <= 10^4]
// Find if a subset of the items exists that sums up to the target T

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
int t;
int x[101];

int dp[105][10100];

int rec(int level,int taken){
    //1. pruning
    if(taken>t)return 0;
    //2. base case
    if(level==n+1){
        if(t==taken){
            return 1;
        }else{
            return 0;
        }
    }
    //3. cache check
    if(dp[level][taken]!=-1){
        return dp[level][taken];
    }
    //4. transition/compute
    int ans = 0;
    if(rec(level+1,taken)==1){
        ans=1;
    }else if(rec(level+1,taken+x[level])==1){
       ans=1;
    }
    //5. save and return
    return dp[level][taken]=ans;
}

void solve(){
   cin>>n;
   for(int i=1;i<=n;i++){
    cin>>x[i];
   }
   cin>>t;
   memset(dp,-1,sizeof(dp)); 
   cout<<rec(1,0);
}

signed main()
{
    IOS;
    int k;
    k=1;
    while(k--){
     solve();
    }
    return 0;
}