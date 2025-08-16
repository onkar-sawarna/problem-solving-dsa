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
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   long long ans=0;
   for(int bit=0; bit<32; bit++){                  // For each bit
    int countSetBits = 0;
    for(int i=0; i<n; i++){                     // Count set bits
        if((a[i] >> bit) & 1) countSetBits++;
    }
    if(countSetBits > 0){
        ans += ((1LL << countSetBits) - 1) * (1LL << bit); // Add subset contribution
    }
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
