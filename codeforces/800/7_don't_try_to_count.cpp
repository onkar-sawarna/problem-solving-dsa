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
  string x,s;
  cin>>x>>s;
  //base case
  if(x.find(s) != string::npos){
    cout<<0<<endl;
    return;
  }
  int operations = 0;
  for (int i = 1; i <= 6; ++i) { // Try up to 6 doublings
    x += x; 
    operations++; 
    if (x.find(s) != string::npos) {
        cout << operations << endl;
        return;
    }
  }
  cout<<-1<<endl;
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