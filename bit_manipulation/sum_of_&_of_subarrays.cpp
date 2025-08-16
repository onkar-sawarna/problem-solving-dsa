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
   for(int bit=0;bit<30;bit++){
     long long subcnt = 0;
     long long last = 0;
     for(int i=0;i<n;i++){
        if((a[i]>>bit)&1){ 
            //only set bits contribution will be counted in sum of & of all subarrays
            last++;
        }else{
            if(last>0){
                subcnt = last*(last+1)/2;
                last = 0;
            }
        }
     }
     if(last>0){
        subcnt = last*(last+1)/2;
        last = 0;
    }
    ans+=(subcnt)*(1<<bit);
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