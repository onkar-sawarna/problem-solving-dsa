#include <bits/stdc++.h>
using namespace std;
#define int long long 

int n,a[100];
vector<int> subsequence;
void recursion(int level){
    //base case
    if(level == n){
      for(auto s:subsequence){
        cout<<s<<" ";
      }
      cout<<"\n";
    }
    //recursive case 
    //take the current element in subsequence
   {
    subsequence.push_back(a[level]);
    recursion(level+1);
    subsequence.pop_back();
   }
   // do not take 
   {
    recursion(level+1);
   }

}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    recursion(0);
    return 0;
}

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n)
// Pattern: Backtracking - Take or Skip
// explanation:
/*
At each index one branch pushes a[level] and the other branch leaves it out.
Those two choices over n indexes are the 2^n subsequences.
A finished subsequence is printed, and printing it takes time linear in its length.
The current vector and the call stack both stay within depth n.
*/
