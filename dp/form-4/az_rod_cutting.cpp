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
int x[1001];
int dp[1001][1001];
  // LR Dp
int rec(int l,int r){
    //minimum cost in order to cut the rod [l...r] with n-1 cuts
    //1.pruning

    //2.base case
    if(l+1 == r)return 0;

    //3.cache check
    if(dp[l][r]!=-1)return dp[l][r];

    //4.compute / transition
    int ans = 1e9;
    for(int p=l+1;p<=r-1;p++){
        ans = min(ans,x[r]-x[l]+rec(l,p)+rec(p,r));
    }

    //5.save and return
    return dp[l][r] = ans;
}

void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>x[i];
  }
  x[0] = 0;
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,n)<<endl;
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