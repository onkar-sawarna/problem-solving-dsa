// Question: If every element from l to r were replaced by k, would the sum of the array be odd?
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
  int n,q;
  cin>>n>>q;
  vi a(n);
  vin(a);
   
  vi prefix(n,0);
  prefix[0] = a[0];
  for(int i=1;i<n;i++){
    prefix[i] = prefix[i-1] + a[i];
  }
  while(q--){
    int l,r,k;
    cin>>l>>r>>k;
    l--;
    r--;
    int sum_total = prefix[n-1];
    int sum_section;
    if (l == 0)
        sum_section = prefix[r];
    else
        sum_section = prefix[r] - prefix[l-1];
    int sum_k = (r-l+1)*k;
    int final = sum_total - sum_section + sum_k;
    if(final%2==1)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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

// Time Complexity: O(n + q)
// Space Complexity: O(n)
// Pattern: Prefix Sum - Range parity
// explanation:
/*
prefix[i] stores the sum of a[0..i], built in one forward pass.
Each query reads l, r, and k, then converts l and r to zero-based indexes.
The range sum is prefix[r] when l is 0, otherwise prefix[r] - prefix[l - 1].
Replacing that range by k keeps the total odd only when the rebuilt sum is odd, which prints YES.
*/
