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
  int a,b;
  cin>>a>>b;
  int xk,yk;
  cin>>xk>>yk;
  int xq,yq;
  cin>>xq>>yq;

  int dx[4]={-1,1,-1,1};
  int dy[4]={-1,-1,1,1};

  set<pi> king,queen;
  int ans = 0;
  
  for(int i=0;i<4;i++){
    king.insert({xk+a*dx[i],yk+b*dy[i]});
    king.insert({xk+b*dx[i],yk+a*dy[i]});

    queen.insert({xq+a*dx[i],yq+b*dy[i]});
    queen.insert({xq+b*dx[i],yq+a*dy[i]});
  }
  for(auto it:king){
    if(queen.find(it)!=queen.end())
      ans++;
  }
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