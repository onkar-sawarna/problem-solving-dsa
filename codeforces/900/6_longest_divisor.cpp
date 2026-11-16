// Question: What is the longest run of consecutive positive integers that all divide n?
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
  int i=1;
  while(n%i==0){
    i++;
  }
  cout<<i-1<<endl;
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

// Time Complexity: O(d)
// Space Complexity: O(1)
// Pattern: Math - Divisor prefix
// explanation:
/*
i starts at 1 and advances while n % i is 0.
d is that first i which does not divide n, so the loop body runs d times.
The longest prefix of divisors is i - 1, which is what gets printed.
No array is stored; n and i are enough.
*/
