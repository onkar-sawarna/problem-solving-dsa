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
  for(int i=0;i<n;i++){
    if(a[i]==1){
      a[i]++;
    }
    if(i>0 && a[i]%a[i-1]==0){
      a[i]++;
    }
  }
  vout(a);
  cout<<endl;
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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Greedy - Adjacent bump
// explanation:
/*
The pass walks i from left to right and edits a[i] in place.
A 1 is raised to 2 before the divisibility test, because 1 divides every neighbor.
If a[i] is still a multiple of a[i - 1], it is increased by one.
That single extra step is the whole repair at index i.
*/
