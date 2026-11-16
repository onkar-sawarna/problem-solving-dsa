// Question: Find the sum of the products of all contiguous subarrays.
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
      prev_sum = (prev_sum+1)*arr[i];
      ans+=prev_sum;
    }
    cout<<ans<<"\n";
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Contribution - Running Product
// explanation:
/*
prev_sum is the sum of the products of all subarrays that end at the previous index.
Multiplying by arr[i] extends each of those products through i.
The added 1 inside (prev_sum+1) starts the new single-element product arr[i], and ans accumulates every ending position.
The pass is linear and the extra state is two integers.
*/
