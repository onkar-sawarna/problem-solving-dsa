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

int n,m;
string a,b;
int dp[1001][1001];
int max_lcsb_overall;

int rec(int i,int j){
    if(i>=n || j>=m)return 0;

    if(dp[i][j]!=-1){
       return dp[i][j];
    }
    
    int current_suffix_len = 0;
    rec(i+1,j); 
    rec(i,j+1);
    //adding +1 only when both characters of each string match
    if(a[i]==b[j]){
        current_suffix_len = 1 + rec(i+1,j+1);
    }
    max_lcsb_overall = max(max_lcsb_overall,current_suffix_len);

    return dp[i][j]=current_suffix_len;
}

void solve(){
  cin>>a>>b;
  n=a.size();
  m=b.size();
  memset(dp,-1,sizeof(dp));
  max_lcsb_overall = 0;
  rec(0,0);
  cout<<max_lcsb_overall<<endl;
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

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Pattern: DP Form 3 - two strings, state (i, j)
// explanation:
/*
State dp[i][j] is the length of the common contiguous segment that starts at a[i] and b[j].
When a[i] equals b[j] the transition is 1 plus the length from (i+1, j+1). Differing characters give length 0.
The calls to (i+1, j) and (i, j+1) evaluate every later starting pair.
max_lcsb_overall stores the largest of those lengths. An index past either string returns 0.
The table has one cell per pair of positions and each cell does constant work.
*/
