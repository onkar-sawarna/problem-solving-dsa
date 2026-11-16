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
  int n,a,b;
  cin>>n>>a>>b;

  if((a+b+2<=n) || (a==b and b==n)){
    cout<<"yEs"<<endl;
  }else{
    cout<<"nO"<<endl;
  }
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

// Time Complexity: O(1)
// Space Complexity: O(1)
// Pattern: Math - Shared prefix room
// explanation:
/*
a and b are the longest prefixes that match inside two permutations of length n.
They fit when a + b + 2 <= n, leaving a free index between the two blocks.
They also fit when a and b are both exactly n, so both permutations are fixed in full.
Every other pair of lengths fails the check.
*/
