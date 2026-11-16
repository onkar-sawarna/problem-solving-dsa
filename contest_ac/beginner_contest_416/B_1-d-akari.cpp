// Question: Where should lamps be placed on the empty cells so that every empty cell is lit and a lamp cannot shine past a block?
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
  string s;
  cin>>s;
  int n=s.size();
  string t=s;
  int last_hash = -1;
  int last_o = -1;
  for(int i=0;i<n;i++){
    if(s[i]=='#'){
        t[i]='#';
        last_hash = i;
    }else if(last_o == -1 || last_hash>last_o){
        t[i]='o';
        last_o = i;
    }
  }
  cout<<t<<endl;
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
// Pattern: Greedy - Leftmost lamp
// explanation:
/*
t starts as a copy of s and is edited in one left-to-right pass.
A hash mark is kept, and its index is saved in last_hash.
A dot becomes o when no lamp exists yet, or when last_hash is strictly to the right of last_o.
That new lamp index is stored, so later dots stay dots until another hash mark passes the previous lamp.
The printed string is t after this single pass.
*/
