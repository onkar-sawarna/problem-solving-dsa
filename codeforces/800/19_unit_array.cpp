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
   int plus=0;
   int minus=0;
   int move=0;
   for(int i=0;i<n;i++){
     cin>>a[i];
     if(a[i]==-1)minus++;
     else plus++;
   }
   while(minus>plus || minus%2==1){
     move++;
     minus--;
     plus++;
   }
  cout<<move<<endl;
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