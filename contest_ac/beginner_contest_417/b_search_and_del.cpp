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
  cin>>n>>m;
  multiset<int> ms;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    ms.insert(x);
  }
  for(int i=0;i<m;i++){
    int x;
    cin>>x;
    if(ms.find(x)!=ms.end()){
        ms.erase(ms.find(x));
    }else{
        continue;
    }
  }
  for(auto v:ms){
    cout<<v<<" ";
  }
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

// Time Complexity: O((N + M) log N)
// Space Complexity: O(N)
// Pattern: Brute Force - Multiset delete
// explanation:
/*
The n numbers are inserted into a multiset, so equal values stay as separate copies.
Each of the m queries searches for one value.
A hit erases exactly one copy through erase of the found iterator. A miss leaves the multiset as it is.
The remaining values are printed in sorted order.
Insert, find, and erase each follow the tree.
*/
