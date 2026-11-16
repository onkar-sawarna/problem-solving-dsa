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
   cin >> n;
   
   vi a(n);
   vin(a);
   if (a[0] == 1) {
       cout << "Yes" << endl;
   } else {
       cout << "No" << endl;
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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Greedy - Leading one
// explanation:
/*
The whole array is read, then only a[0] is tested.
When that first cell is 1, the answer is Yes.
Any other leading value prints No.
The later elements do not change that branch.
*/
