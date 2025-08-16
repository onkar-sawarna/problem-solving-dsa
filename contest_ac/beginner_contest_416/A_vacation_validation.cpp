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
  int n,l,r;
  cin>>n>>l>>r;
  string s;
  cin>>s;
  l--;
  r--;
  for(int i=l;i<=r;i++){
    if(s[i]!='o'){
        cout<<"No"<<endl;
        return;
    }
  }
  cout<<"Yes"<<endl;
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