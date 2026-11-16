// Question: Find the sum, over every subarray, of the number of inversions in that subarray.
#include <bits/stdc++.h>
using namespace std;
#define int long long 

//Atomic item contribution
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int ans=0;
    for(int i=0;i<n;i++){
       for(int j=i+1;j<n;j++){
           if(arr[i]>arr[j])
           ans+=((i+1)*(n-j));
       }
    }
    cout<<ans<<"\n";
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Pattern: Contribution - Inversion Weight
// explanation:
/*
Every pair i < j with arr[i] greater than arr[j] is one inversion.
A subarray contains that pair when its left end is in 0..i and its right end is in j..n-1.
The number of those subarrays is (i+1)*(n-j), and that weight is added for the pair.
The nested loops visit every pair, so the time is quadratic. Only a few integers are extra.
*/
