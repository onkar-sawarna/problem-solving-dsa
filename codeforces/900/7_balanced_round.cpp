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
  int n,k;
  cin>>n>>k;
  vi a(n);
  vin(a);
  int count=1;
  int max_count=1;
  sort(a.begin(),a.end());
  for(int i=1;i<n;i++){
    if(abs(a[i-1]-a[i]) <= k){
      count++;
    }else{
      count=1;
    }
    max_count=max(max_count,count);
  }
  cout<<n-max_count<<endl;
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

// Time Complexity: O(n log n)
// Space Complexity: O(n)
// Pattern: Greedy - Sorted streak
// explanation:
/*
The difficulties are sorted so only neighboring gaps matter.
count grows while |a[i] - a[i - 1]| stays within k, and drops back to 1 when a gap is too wide.
max_count keeps the longest surviving streak, including a single-element array.
The number of problems to remove is n - max_count.
*/
