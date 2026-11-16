#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
using pi = pair<int, int>;       // Alias for pair<long long, long long>
using vi = vector<int>;          // Alias for vector<long long>
using vvi = vector<vi>;          // Alias for vector<vector<long long>>

 

   void solve(){
     int n;
     cin>>n;
     map<int,int> mp;
     for(int i=0;i<n;i++){
        int val;
        cin>>val;
        mp[val]++;
     }
     int max_x = 0;

     for(int x = 0; x <= n; ++x){
         int count_greater_or_equal = 0; 
         for(auto [key, val] : mp){ 
            if(key >= x){
                count_greater_or_equal += val; 
            }
        }
         if(count_greater_or_equal >= x){
             max_x = x; 
         }
     }
 
     cout << max_x << "\n";
   }

    signed main()
    {
        IOS;
        solve();
        return 0;
    }

// Time Complexity: O(N^2)
// Space Complexity: O(N)
// Pattern: Brute Force - Citation sweep
// explanation:
/*
A map counts how many papers share each citation value.
x then runs from 0 through n.
For a fixed x the inner loop adds frequencies of keys that are >= x.
x is recorded whenever that total is at least x, and the increasing scan leaves max_x at the largest success.
Distinct keys are at most n, so the nested scans are quadratic when every citation value differs.
*/
