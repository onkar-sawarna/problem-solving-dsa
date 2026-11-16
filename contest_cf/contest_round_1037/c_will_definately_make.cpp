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
  vi a(n);
  vin(a);

  int init = a[k-1];
  set<int> st;
  for(auto x:a){
    if(x>=init)st.insert(x);
  }
  bool isPossible = true; 
  int prev = init;
  for(auto x:st){
    if(x-prev > init){
        isPossible=false;
        break;
    }
    prev = x;
  }
  if(isPossible)cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
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
// Pattern: Greedy - Sorted gap check
// explanation:
/*
init is a[k - 1].
The set keeps every a[i] that is at least init, in increasing order, with duplicates collapsed.
The walk starts at init and steps through that set.
A step fails when the new value minus the previous one is greater than init.
If every consecutive gap fits, the answer is Yes.
*/
