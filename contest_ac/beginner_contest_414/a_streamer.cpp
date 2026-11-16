// Question: How many of the broadcast intervals completely cover the window from l to r?
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
  int n,l,r;
  cin>>n>>l>>r;
  int count = 0;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    if(x<=l and y>=r){
        count++;
    }
  }
  cout<<count<<endl;
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
// Space Complexity: O(1)
// Pattern: Brute Force - Interval cover
// explanation:
/*
Each of the n streamers is read as a range [x, y].
The counter increases when x <= l and y >= r, which means the range covers the whole segment.
Ranges are not stored.
The loop touches each streamer once.
The printed value is that counter.
*/
