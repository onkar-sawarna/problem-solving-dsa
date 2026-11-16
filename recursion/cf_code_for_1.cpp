// Question: How many ones are in the substring from l to r of the string formed by n/2, the bit n mod 2, and n/2 again?
#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
    
   int length(int n){
    if(n<=1)return 1;
    return 2*length(n/2)+1;
   }

   int solve(int n,int l,int r){
      if(n == 0)return 0;
      if(n == 1)return 1;

      int len_half = length(n/2); // l to len_half->first half , len_half+1->middle element , len_half+2 to r->2nd half
      //(l,r) lies in the first half
      if(r<len_half) return solve(n/2,l,r);
      //(l,r) lies in the 2nd half 
      else if(l>len_half+1)return solve(n/2,l-len_half-1,r-len_half-1);
      //(l,r) lies in both including middle element 
      else {
        int count = 0;
        if(l<=len_half)count+=solve(n/2,l,r);
        if(l<=len_half+1 and r>=len_half+1)count+=(n%2);
        if(r>=len_half+2)count+=solve(n/2,1,r-len_half-1);
        return count;
      }
   }

    signed main()
    {
        IOS;
        int n,l,r;
        cin>>n>>l>>r;
        cout<<solve(n,l,r)<<"\n";
        return 0;
    }

// Time Complexity: O(n)
// Space Complexity: O(log n)
// Pattern: Recursion - Constructed binary string
// explanation:
/*
The string for n is the string for n/2, then the bit n%2, then the string for n/2 again.
A query that misses the middle makes one recursive call on n/2.
A query that covers the middle adds n%2 and then searches both halves.
Covering the whole string visits Theta(n) calls, and the length() work over that tree is also O(n).
The two half-calls run one after the other, so the stack stays O(log n) deep.
*/
