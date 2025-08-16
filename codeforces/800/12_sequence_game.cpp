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
  vi b(n);
  vin(b);

  vi a;
  a.push_back(b[0]);
  for(int i=1;i<n;i++){
    if(b[i]>=b[i-1]){
      a.push_back(b[i]);
    }else{
      a.push_back(b[i]); 
      a.push_back(b[i]); 
    }
  }
  cout<<a.size()<<endl;
  for(auto it : a){
    cout<<it<<" ";
  }
  cout<<endl;
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