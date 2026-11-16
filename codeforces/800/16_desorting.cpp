// Question: What is the fewest times you can add 1 to a prefix and subtract 1 from the suffix to make the array no longer non-decreasing?
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
  int operations = INT_MAX;
  for(int i=0;i<n-1;i++){
    if(a[i]<=a[i+1]){
       int diff = a[i+1]-a[i];
       int move = diff/2+1;
       operations = min(operations,move);
    }else{
        operations=0;
    }
  }
  cout<<operations<<endl;
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
// Pattern: Greedy - Adjacent descent
// explanation:
/*
Each neighbor pair is checked from left to right.
A pair that already decreases sets operations to 0, because the array is already unsorted.
A non-decreasing pair needs diff / 2 + 1 increments to create a descent there.
operations keeps the smallest of those costs.
*/
