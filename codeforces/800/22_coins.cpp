// Question: Can you make exactly n using any number of coins of value 2 and value k?
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

  if((n%2 != 0) and (k%2 == 0)){
    cout<<"No"<<endl;
  }else{
    cout<<"Yes"<<endl;
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
// Pattern: Math - Coin parity
// explanation:
/*
n must be formed from coins of 2 and coins of k.
An odd n cannot be built when k is even, and that pair prints No.
Every other combination of parities prints Yes.
The decision is the one modulo test on n and k.
*/
