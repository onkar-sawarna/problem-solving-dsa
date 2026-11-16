/*
 Problem Statement: Given an integer array nums, return the length of the
 longest strictly increasing subsequence.

 Problem Source: Classic Dynamic Programming problem (LeetCode #300).
*/
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

int n;
int arr[10010];
int dp[10010];
 
int rec(int level){
    //best LIS ending at level
    //1. pruning
    if(level<0)return 0;

    //2.base case

    //3.cache check
    if(dp[level]!=-1){
        return dp[level];
    }

    //4.compute/transition
    int ans=1;
    for(int prev_taken = 0;prev_taken<level;prev_taken++){
        if(arr[prev_taken]<arr[level]){
            ans=max(ans,1+rec(prev_taken));
        }
    }

    //5.save and return 
    return dp[level]=ans;
}
void solve(){
  cin>>n;
  for(int i=0;i<n;i++){
    cin>>arr[i];
  }
  memset(dp,-1,sizeof(dp));
  int best=0;
  for(int i=0;i<n;i++){
    best=max(best,rec(i));
  }
  cout<<best<<endl;
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

// Time Complexity: O(n^2)
// Space Complexity: O(n)
// Pattern: DP Form 2 - best that ends here (Kadane, LIS, grid cell)
// explanation:
/*
State dp[level] is the longest strictly increasing subsequence that ends at index level.
The transition checks every earlier index and, when arr[prev] is smaller than arr[level], takes 1 plus that earlier length.
Before any extension the length is 1, and an index below 0 returns 0.
The printed value is the maximum of dp[i] over every index.
There are n ending positions, each scans O(n) earlier indexes, and the table stores one length per index.
*/
