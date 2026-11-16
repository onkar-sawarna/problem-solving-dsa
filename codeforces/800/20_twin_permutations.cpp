// Question: What permutation adds with the given one to the same value in every position?
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
  vi b(n);
  for(int i=0;i<n;i++){
    cout<<n+1-a[i]<<" "; //n+1 - a[i] + a[i] = n+1 = a[i]+b[i] = k(constant)
  }
  cout<<endl;
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
// Pattern: Constructive - Fixed complement
// explanation:
/*
Each printed value is n + 1 - a[i].
Added back to a[i], every position sums to the same constant n + 1.
The loop writes that complement for every index.
a and b are both length n, which is the space this function keeps.
*/
