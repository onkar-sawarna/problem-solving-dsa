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

string a,b,c;
int dp[101][101][101];

int rec(int i,int j,int k){
    //1.pruning

    //2.base case
    if(i>=a.size() || j>=b.size() || k>=c.size())return 0;

    //3.cache check
    if(dp[i][j][k]!=-1){
       return dp[i][j][k];
    }
    //4.compute/transition
    int ans = 0;
    ans = max(ans,rec(i+1,j,k));
    ans = max(ans,rec(i,j+1,k));
    ans = max(ans,rec(i,j,k+1));
    if(a[i]==b[j] and b[j]==c[k]){
        ans = max(ans,1+rec(i+1,j+1,k+1));
    }
  
    //5.save and return
    return dp[i][j][k]=ans;
}

void solve(){
  cin>>a>>b>>c;
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,0,0)<<endl;
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