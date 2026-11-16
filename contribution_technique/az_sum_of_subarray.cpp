// Question: Find the sum of all subarray sums.
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
        ans+=arr[i]*(i+1)*(n-i);
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// Pattern: Contribution - Element Span
// explanation:
/*
arr[i] sits in every subarray whose start is in 0..i and whose end is in i..n-1.
The start has i+1 choices and the end has n-i choices, so the element is counted (i+1)*(n-i) times.
Adding arr[i] times that product, for every i, totals the sum of all subarray sums.
The loop allocates nothing beyond the input array.
*/
