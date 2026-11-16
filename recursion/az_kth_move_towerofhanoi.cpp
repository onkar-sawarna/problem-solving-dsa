// Question: Which pegs does the k-th move travel between when solving the Tower of Hanoi for the given number of disks?
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(int disk,int left,int right,int middle,int k){
   if(k<=((1<<(disk-1))-1))solve(disk-1,left,middle,right,k);
   else if(k==(1<<(disk-1)))cout<<left<<" "<<right;
   else solve(disk-1,middle,right,left,k-(1<<(disk-1)));
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t--){
        int disk,k;
        cin>>disk>>k;
        int left=1,middle=2,right=3;
        solve(disk,left,right,middle,k);
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Recursion - Kth Hanoi move
// explanation:
/*
Disk n moves on step 2^(n-1). A smaller k stays in the first sub-tower, and a larger k subtracts that step.
Each call drops one disk and follows only the half that still contains k.
The walk stops when k is the single move of the current disk.
The stack holds one frame per disk, with a few integers in each frame.
*/
