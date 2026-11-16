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
  int sum = 0;
  for(int i=0;i<n-1;i++){
    int x;
    cin>>x;
    sum+=x;
  }
  cout<<-1*sum<<endl;
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
// Space Complexity: O(1)
// Pattern: Math - Missing total
// explanation:
/*
The n efficiencies sum to zero, and only n - 1 of them are given.
sum accumulates those given values one by one.
The missing efficiency is the negation of that sum.
No array is stored; the running total is the only state.
*/
