// Question: What is the largest k such that swapping elements k positions apart can sort the permutation?
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
  int k = abs(a[0]-1);
  for(int i=1;i<n;i++){
    k = __gcd(k,abs(a[i]-(i+1)));
  }
  cout<<k<<endl;
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
// Pattern: Math - Offset gcd
// explanation:
/*
k must divide every distance from a value to its target index.
The running gcd starts at |a[0] - 1| and folds in |a[i] - (i + 1)| for each later i.
A fixed point adds a 0 offset and leaves the gcd unchanged.
The value printed after the single pass is that gcd.
*/
