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
  int n;
  cin>>n;
  vi a(n);
  vin(a);

  int operations=0;
  for(int i=0;i<n-1;i++){
    if((a[i]&1) == (a[i+1]&1)){
       operations++;
    }
  }
  cout<<operations<<endl;
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
// Pattern: Greedy - Adjacent parity
// explanation:
/*
The loop compares each element with the next one.
Matching least bits mean the two neighbors have the same parity.
Every such pair increments operations.
The printed count is how many adjacent pairs must be broken.
*/
