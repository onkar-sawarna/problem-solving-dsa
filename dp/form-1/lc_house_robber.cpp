/*
  Problem Statement: You are a professional robber planning to rob houses along a street.
    Each house has a certain amount of money stashed, the only constraint stopping you from robbing
    each of them is that adjacent houses have security systems connected and it will automatically
    contact the police if two adjacent houses were broken into on the same night.
    Given an integer array nums representing the amount of money of each house,
    return the maximum amount of money you can rob tonight without alerting the police. 

    constraints:
    1 <= nums.length <= 100
    0 <= nums[i] <= 400 

    Problem Source: Classic Dynamic Programming problem (LeetCode #198).
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
using vvvi = vector<vvi>;       
using vpi = vector<pi>;         
using vvpi = vector<vpi>;       
using vs = vector<string>;      
using vvs = vector<vs>;    

int n;
int nums[105];
int dp[105];
int rec(int level){
    //1. pruning
    if(level >= n){
        return 0;
    }
    //2. base case
    // Already handled by pruning
    //3. cache check
    if(dp[level] != -1){
        return dp[level];
    }
    //4. transition/compute
    // Option 1: Rob current house (level)
    // Then we cannot rob the next house (level+1), so we move to level+2
    int rob_current = nums[level] + rec(level + 2);
    // Option 2: Skip current house (level)
    // Then we can rob the next house (level+1), so we move to level+1
    int skip_current = rec(level + 1);
    
    int ans = max(rob_current, skip_current);

    //5. save and return
    return dp[level] = ans;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> nums[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << rec(0) << endl;
}

signed main(){
    IOS ;
    int t;          
    t = 1;
    while(t--){
        solve();
    }
    return 0;
}