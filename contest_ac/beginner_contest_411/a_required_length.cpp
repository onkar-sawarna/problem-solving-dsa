#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;          

 

void solve(){
  string p;
  int l;
  cin>>p>>l;
  if(p.size()>=l)cout<<"Yes";
  else cout<<"No";
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

// Time Complexity: O(|P|)
// Space Complexity: O(|P|)
// Pattern: Math - Length check
// explanation:
/*
The password string and the limit l are read.
The decision compares p.size() with l.
A string at least that long prints Yes.
A shorter string prints No.
The stored data is the password itself.
*/
