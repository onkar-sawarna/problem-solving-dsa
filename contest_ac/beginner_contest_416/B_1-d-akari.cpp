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