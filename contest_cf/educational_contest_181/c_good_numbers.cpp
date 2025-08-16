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


int func(int x){
    int cnt[4]={};
    cnt[0]=x/2;
    cnt[1]=x/3-x/6;
    cnt[2]=x/5-x/10-x/15+x/30;
    cnt[3]=x/7-x/14-x/21-x/35+x/42+x/105+x/70-x/210;
    for(int i=0;i<4;i++) x-=cnt[i];
    return x;
}
void solve(){
    int l,r; cin>>l>>r;
    l--;
    cout<<func(r)-func(l)<<'\n';
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