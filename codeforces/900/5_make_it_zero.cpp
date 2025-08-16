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
  vi a(n);
  vin(a);

  if(n%2==0){
    cout<<2<<endl;
    cout<<1<<" "<<n<<endl;
    cout<<1<<" "<<n<<endl;
  }else{
    cout<<4<<endl;
    cout<<2<<" "<<n<<endl;
    cout<<2<<" "<<n<<endl;
    cout<<1<<" "<<2<<endl;
    cout<<1<<" "<<2<<endl;
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