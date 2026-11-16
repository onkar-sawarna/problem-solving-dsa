// Question: What is the length of the longest common subsequence of the two strings?
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

int rec(int i,int j){
    // two different arrays or string ,best lcs for A[i...n] and B[j...m]
    //1.pruning

    //2.base case
    if(i>=n || j>=m)return 0;

    //3.cache check
    if(dp[i][j]!=-1){
       return dp[i][j];
    }
    //4.compute/transition
    int ans = 0;
    ans = max(ans,rec(i+1,j));
    ans = max(ans,rec(i,j+1));
    if(a[i]==b[j]){
        ans = max(ans,1+rec(i+1,j+1));
    }
  
    //5.save and return
    return dp[i][j]=ans;
}

void solve(){
  cin>>n>>m;
  cin>>a>>b;
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,0);
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

// Time Complexity: O(n*m)
// Space Complexity: O(n*m)
// Pattern: DP Form 3 - two strings, state (i, j)
// explanation:
/*
State dp[i][j] is the longest common subsequence of the suffixes a[i..] and b[j..].
The transition keeps the better of skipping a[i] and skipping b[j].
When a[i] equals b[j] it also considers 1 plus the state of the two following suffixes.
An index past either string returns 0.
The table has one cell for each pair of positions, and each cell tries a constant number of moves.
*/
