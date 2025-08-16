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

// GREEDY + BINARY SEARCH
 

void solve(){
   int n;
   cin>>n;
   int arr[n];
   int insertedAt[n];
   vin(arr);
   vi lis;
   for(int i=0;i<n;i++){
    if(lis.empty() || lis.back()<arr[i]){
        lis.push_back(arr[i]);
        insertedAt[i] = lis.size()-1;
    }else{
        auto it = lower_bound(lis.begin(),lis.end(),arr[i]);
        *it = arr[i];
        insertedAt[i] = it-lis.begin();
    }
   }
   int curLen = lis.size()-1;
   vi final_lis;
   for(int i=n-1;i>=0;i--){
    if(insertedAt[i] == curLen){
        final_lis.push_back(arr[i]);
        curLen--;
    }
   }
   reverse(final_lis.begin(),final_lis.end());
   vout(final_lis);
   cout<<lis.size()<<endl;
}

signed main()
{
    IOS;
    int t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}