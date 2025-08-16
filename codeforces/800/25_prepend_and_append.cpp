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
  string s;
  cin>>s;
  int i=0,j=n-1;

  while(i<j){
    if((s[i]=='0' and s[j]=='1') || (s[i]=='1' and s[j]=='0')){
        i++;
        j--;
    }else{
        break;
    }
  }
  if(i==j){
    cout<<1<<endl;
  }
  else if(i<j){
    cout<<j-i+1<<endl;
  }else{
    cout<<0<<endl;
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