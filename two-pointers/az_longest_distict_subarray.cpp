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
   vin(a);
   //head and tail pointers
   int tail = 0;
   int head = -1; 
   //compute answer
   int ans = 0;
   //data structure
   map<int,int> mp;
   while(tail<n){
     
     //expansion of window
     while(head+1 < n and mp[a[head+1]]==0){
        head++;
        mp[a[head]]++;
     }
     ans = max(ans,head-tail+1);
     if(tail > head){
        tail++;
        head = tail-1;
     }else{//shrinking the window
        mp[a[tail]]--;
        tail++;
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