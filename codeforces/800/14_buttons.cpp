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
   int a,b,c;
   cin>>a>>b>>c;

   if(c%2){
    if(b>a){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }
   }else{
    if(a>b){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
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