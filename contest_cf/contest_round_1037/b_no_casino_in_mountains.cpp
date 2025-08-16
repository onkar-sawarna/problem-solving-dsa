#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "

using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;

void solve(){
   int n, k;
   cin >> n >> k;
   vi a(n);
   vin(a);

   int hikes = 0;
   int current_day = 0;

  for(int i=0;i<n;i++){
    if(a[i]==0)current_day++;
    else current_day=0;

    if(current_day == k){
        hikes++;
        current_day=0;
        i+=1;
    }
  }
   
   cout << hikes << endl;
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while(t--){
     solve();
    }
    return 0;
}