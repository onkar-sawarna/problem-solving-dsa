// Question: What is the largest sum of any contiguous subarray?
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
   vi arr(n);
   vin(arr);

   vi dp(n);
   int ans=-1e9;

   for(int i=0;i<n;i++){
    if(i==0){
        dp[i]=arr[i];
    }else{
        dp[i]=max(dp[i-1]+arr[i],arr[i]);
    }
    ans=max(ans,dp[i]);
   }
  cout<<ans<<endl;
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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: DP Form 2 - best that ends here (Kadane, LIS, grid cell)
// explanation:
/*
State dp[i] is the largest subarray sum that ends at index i.
The transition chooses the larger of extending dp[i-1] by arr[i] and starting fresh at arr[i].
The answer is the maximum value written into dp.
The loop fills one cell per index from the previous cell only, so the table length is n.
*/
