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
   int k;
   cin>>k;
   k++;

   int len=1;
   while(1LL<<(len-1)*len<k){
     k-=(1LL<<(len-1))*len;
     len++;
   }

   int num = ((k+len-1)/len);
   int val = (1LL<<(len-1))+num-1;

   int bitinval = (k-1)%len;

   cout<<((val>>(len-1-bitinval))&1)<<endl;
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