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
  int n,k;
  cin>>n>>k;
  vi a(n);
  vin(a);
  int count=1;
  int max_count=1;
  sort(a.begin(),a.end());
  for(int i=1;i<n;i++){
    if(abs(a[i-1]-a[i]) <= k){
      count++;
    }else{
      count=1;
    }
    max_count=max(max_count,count);
  }
  cout<<n-max_count<<endl;
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