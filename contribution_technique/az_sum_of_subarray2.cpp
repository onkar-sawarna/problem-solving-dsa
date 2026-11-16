// Question: Find the sum of all subarray sums.
#include <bits/stdc++.h>
using namespace std;
#define int long long 

//Extending contribution
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int prev_sum=0;
    int ans = 0;
    for(int i=0;i<n;i++){
      prev_sum = prev_sum+arr[i]*(i+1);
      ans+=prev_sum;
    }
    cout<<ans<<"\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Contribution - Ending Subarray Sum
// explanation:
/*
prev_sum carries the sum of the subarray sums that end at the previous index.
Those sums remain, and arr[i] is added once for each of the i+1 subarrays that now end at i.
ans adds the updated prev_sum, so every ending position is included exactly once.
One pass keeps two running integers besides the input array.
*/
