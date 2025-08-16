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
  int n1=n;
  int cnt=0;
  while(n1>0){
    int r = n%10;
    cnt++;
    n1/=10;
  }
  int cnt1=cnt-1;
  int quotient = 1;
  while(cnt1!=0){
    quotient *= 10;
    cnt1--; 
  }
  int ans = 9*(cnt-1)+(n/quotient);
  cout<<ans<<endl;

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