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

int n,W; 
int w[105];
int v[105];
int dp[105][100005];

int rec(int level,int weight_taken){
   
   //1. pruning
   if(level > n)return 0;

   //2. base case
   if(level == n)return 0;

   //3. cache check
   if(dp[level][weight_taken]!=-1){
    return dp[level][weight_taken];
   }

   //4. transition/compute
   int ans = rec(level+1,weight_taken);
   if(weight_taken+w[level]<=W){
     ans = max(ans,v[level]+rec(level+1,weight_taken+w[level]));
   }
    
   //5. save and return
   return dp[level][weight_taken] = ans;
}

void solve(){
  cin>>n>>W;
 for(int i=0;i<n;i++){
  cin>>w[i]>>v[i];
 }
 memset(dp,-1,sizeof(dp));
 cout<<rec(0,0)<<endl;
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