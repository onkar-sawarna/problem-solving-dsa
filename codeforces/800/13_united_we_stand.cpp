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

  vi b;
  vi c;

  int mx = *max_element(a.begin(),a.end());

  for(int i=0;i<n;i++){
    if(a[i]!=mx){
        b.push_back(a[i]);
    }else{
        c.push_back(a[i]);
    }
  }
  if(b.size() == 0){
    cout<<-1<<endl;
  }else{
    cout<<b.size()<<" "<<c.size()<<endl;
    for(auto it: b){
        cout<<it<<" ";
    }cout<<endl;
    for(auto it: c){
        cout<<it<<" ";
    }cout<<endl;
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