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
int arr[10010];
int dp[10010];
 
int rec(int level){
    //best LIS ending at level
    //1. pruning
    if(level<0)return 0;

    //2.base case

    //3.cache check
    if(dp[level]!=-1){
        return dp[level];
    }

    //4.compute/transition
    int ans=1;
    for(int prev_taken = 0;prev_taken<level;prev_taken++){
        if(arr[prev_taken]<arr[level]){
            ans=max(ans,1+rec(prev_taken));
        }
    }

    //5.save and return 
    return dp[level]=ans;
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  memset(dp,-1,sizeof(dp));
  int best=0;
  for(int i=0;i<n;i++){
    best=max(best,rec(i));
  }
  cout<<best<<endl;
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