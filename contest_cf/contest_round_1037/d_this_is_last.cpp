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
  int n,k;
  cin>>n>>k;
  // [ L, R , T]
  vector<pair<pair<int,int>,int>> v(n);
  for(auto &[r,t]:v){
    cin>>r.first>>r.second>>t;
  }
  //sorted in ascending order of values of l
  sort(v.begin(),v.end());
  int ans=k;
  for(auto &[R,t]:v){
    int l=R.first;
    int r=R.second;
    if(l<=ans and ans<=r){
        ans = max(ans,t);
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

// Time Complexity: O(T * N log N)
// Space Complexity: O(N)
// Pattern: Greedy - Sort by left endpoint
// explanation:
/*
Each item stores L, R, and the teleport value t.
Sorting orders items by L, then by R, then by t.
ans begins at k.
An item applies only when ans already sits inside [L, R], and then ans becomes the larger of ans and t.
Later items see the raised value, so a chain of covering segments can keep lifting it.
*/
