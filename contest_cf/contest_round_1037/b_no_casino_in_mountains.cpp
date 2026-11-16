// Question: How many hikes of k consecutive clear days can you take if each hike must be followed by one rest day?
#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "

using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;

void solve(){
   int n, k;
   cin >> n >> k;
   vi a(n);
   vin(a);

   int hikes = 0;
   int current_day = 0;

  for(int i=0;i<n;i++){
    if(a[i]==0)current_day++;
    else current_day=0;

    if(current_day == k){
        hikes++;
        current_day=0;
        i+=1;
    }
  }
   
   cout << hikes << endl;
}

signed main()
{
    IOS;
    int t;
    cin >> t;
    while(t--){
     solve();
    }
    return 0;
}

// Time Complexity: O(T * N)
// Space Complexity: O(N)
// Pattern: Greedy - Zero streak
// explanation:
/*
current_day counts consecutive zeros and drops back to 0 on any other value.
Reaching exactly k records one hike and clears the streak.
i is then increased by one inside the body, and the for-loop increases it again, so the next day is skipped as rest.
That skipped index is never added into the next streak.
The printed number is how many times a streak of k was completed.
*/
