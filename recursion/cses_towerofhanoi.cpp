// Question: What is the minimum number of moves, and the sequence of those moves, to transfer n disks from peg 1 to peg 3?
#include <bits/stdc++.h>
using namespace std;
#define int long long 

void solve(int disk,int left,int right,int middle){
   if(disk == 0)return;
   solve(disk-1,left,middle,right);
   cout<<left<<" "<<right<<"\n";
   solve(disk-1,middle,right,left);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    //cin>>t;
    t = 1;
    while(t--){
        int disk;
        cin>>disk;
        // (2^n)-1
        cout<<((1<<disk)-1)<<"\n";
        int left=1,middle=2,right=3;
        solve(disk,left,right,middle);
    }
    return 0;
}

// Time Complexity: O(2^n)
// Space Complexity: O(n)
// Pattern: Recursion - Tower of Hanoi
// explanation:
/*
Moving n disks recurses the n-1 tower onto the spare peg, prints the move of disk n, then recurses onto the target.
The move count printed first is 2^n - 1, and each call prints at most one line.
The recursion tree therefore has Theta(2^n) calls.
Only one path from the root is on the stack, which is n frames.
*/
