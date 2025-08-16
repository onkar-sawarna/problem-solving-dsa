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