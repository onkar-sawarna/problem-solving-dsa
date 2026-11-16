#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 

   void solve(int current,int& ans,int seen3,int seen5,int seen7,int n){
     if(current>n)return;
     if(current <= n && seen3 && seen5 && seen7){
        ans++;
     }
     solve(current*10+3,ans,1,seen5,seen7,n);
     solve(current*10+5,ans,seen3,1,seen7,n);
     solve(current*10+7,ans,seen3,seen5,1,n);
   }

    signed main()
    {
        IOS;
        int n;
        cin>>n;
        int ans=0;
        solve(0,ans,0,0,0,n);
        cout<<ans<<"\n";
        return 0;
    }

// Time Complexity: O(3^d)
// Space Complexity: O(d)
// Pattern: Backtracking - Digits 3 5 7
// explanation:
/*
d is the number of digits of n.
From the current number the search appends 3, 5, or 7, giving three branches and depth d.
A number is counted when it is at most n and has already used all three digits.
A value past n is not expanded, and the stack holds d frames.
*/
