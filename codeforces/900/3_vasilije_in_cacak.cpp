// Question: Can you choose k distinct integers from 1 to n that add up to x?
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
  int n,k,x;
  cin>>n>>k>>x;
  int x_min = (k*(k+1)/2);
  int x_max = (n*(n+1)/2) - ((n-k)*(n-k+1)/2);
  if(x>=x_min and x<=x_max){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
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
// Pattern: Math - Sum bounds
// explanation:
/*
x_min is the sum of the first k positives, k * (k + 1) / 2.
x_max is the sum of the largest k values in 1..n, computed as the full sum minus the sum of the smallest n - k values.
x is accepted only when it lies between those two inclusive bounds.
The test is arithmetic on n, k, and x.
*/
