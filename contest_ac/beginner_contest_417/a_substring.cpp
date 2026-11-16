// Question: What remains of the string after the first a characters and the last b characters are removed?
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
  string s;
  cin>>s;
  // a will be inclusive here
  string s1 = s.substr(a,n-a-b);
  cout<<s1<<endl;
}

signed main()
{
    IOS;
    int t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}

// Time Complexity: O(N)
// Space Complexity: O(N)
// Pattern: Constructive - Slice
// explanation:
/*
The full string is read.
substr(a, n - a - b) drops the first a characters and the last b characters.
The kept middle is copied into s1.
That copy is printed.
Reading s and copying the slice are both linear in the string length.
*/
