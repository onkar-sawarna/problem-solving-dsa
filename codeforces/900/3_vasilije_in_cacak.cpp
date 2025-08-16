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
  int n,k,x;
  cin>>n>>k>>x;
  int x_min = (k*(k+1)/2);
  int x_max = (n*(n+1)/2) - ((n-k)*(n-k+1)/2);
  if(x>=x_min and x<=x_max){
    cout<<"Yes"<<endl;
  }else{
    cout<<"No"<<endl;
  }
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