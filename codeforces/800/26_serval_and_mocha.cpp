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
   int flag = 0;
   for(int i=0;i<n;i++){
    for(int j=i+1;j<n;j++){
     if(__gcd(a[i],a[j])<=2){
        flag=1;
     }
    }
   }
   if(flag == 0)cout<<"No"<<endl;
   else cout<<"Yes"<<endl;
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

// Time Complexity: O(n^2)
// Space Complexity: O(n)
// Pattern: Brute Force - Pair gcd
// explanation:
/*
The outer index i and the inner index j walk every unordered pair.
flag is set when __gcd(a[i], a[j]) is at most 2.
One such pair is enough, and the loops still finish the scan.
flag still 0 after every pair prints No.
*/
