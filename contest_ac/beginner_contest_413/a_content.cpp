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
   int n,m;
   cin>>n>>m;
   vi a(n);
   int sum=0;
   for(int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
   }
   if(sum<=m)cout<<"Yes";
   else cout<<"No";
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

// Time Complexity: O(N)
// Space Complexity: O(N)
// Pattern: Math - Sum compare
// explanation:
/*
The n values are stored and added into sum in the same loop.
The decision is one comparison of that sum with m.
sum <= m prints Yes.
A larger sum prints No.
The loop body is constant work per index.
*/
