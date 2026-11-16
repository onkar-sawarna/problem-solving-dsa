// Question: Two players take turns adding or subtracting 1, and whoever first makes the number divisible by 3 wins; who wins if the first player starts from n?
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
  if(n%3 == 0)cout<<"Second"<<endl;
  else cout<<"First"<<endl;
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
// Pattern: Math - Multiple of three
// explanation:
/*
Each turn adds or subtracts 1, and the winner is whoever first makes the number divisible by 3.
When n % 3 is already 0, the second player can always answer and keep that property, so the answer is Second.
Otherwise the first player can step onto a multiple of 3 immediately.
The branch is that single remainder.
*/
