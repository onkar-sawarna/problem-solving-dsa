// Question: What is the shortest sequence of forward jumps that adds up to x if no jump length is divisible by k?
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
  int x,k;
  cin>>x>>k;
  int moves=0;
  if(x%k!=0){
    cout<<1<<endl;
    cout<<x<<endl;
  }else{
    cout<<2<<endl;
    cout<<x-1<<" "<<1<<endl;
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
// Pattern: Constructive - Safe jumps
// explanation:
/*
A jump length divisible by k is forbidden.
When x % k is nonzero, one jump of length x lands legally.
When x is a multiple of k, that single jump is blocked.
The code then prints two jumps, x - 1 and 1, which add to x and avoid the multiple.
*/
