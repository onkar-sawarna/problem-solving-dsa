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
  int n,m;
  cin>>n;
  string a,b,c;
  cin>>a;
  cin>>m;
  cin>>b;
  cin>>c;
  string res=a;
  for(int i=0;i<m;i++){
    if(c[i]=='V'){
        //add b[i] to beginning of a
        res = b[i]+res;
    }else{
        //add b[i] to end of a
        res = res+b[i];
    }
  }
  cout<<res<<endl;
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

// Time Complexity: O(T * (N + M)^2)
// Space Complexity: O(N + M)
// Pattern: Constructive - End inserts
// explanation:
/*
res starts as a copy of a.
For each of the m characters, V builds a new string with b[i] on the front, and any other instruction builds one with b[i] on the back.
Each assignment copies the whole current string.
The lengths run from n through n + m, so the copies add up quadratically.
The printed line is the finished res.
*/
