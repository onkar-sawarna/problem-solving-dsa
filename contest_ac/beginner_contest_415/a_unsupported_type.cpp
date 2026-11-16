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
  int x;
  cin>>x;

  set<int> st(a.begin(),a.end());
  if(st.find(x)!=st.end()){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
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

// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Pattern: Brute Force - Set lookup
// explanation:
/*
The n numbers are copied into a set, which orders them and drops duplicates.
find(x) searches that tree.
A hit prints Yes.
A miss prints No.
Building the set dominates the single lookup.
*/
