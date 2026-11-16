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
  int a,b,n;
  cin>>a>>b>>n;
  vi x(n);
  vin(x);
  int sum = b;
  for(auto v:x){
    sum+=min(v,a-1);
  }
  cout<<sum<<endl;
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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Greedy - Timer cap
// explanation:
/*
sum starts at the initial timer b.
Each tool v adds min(v, a - 1), so a tool larger than a full cycle cannot push the timer through a reset.
The loop folds every tool into that running sum.
The printed total is b plus those capped additions.
*/
