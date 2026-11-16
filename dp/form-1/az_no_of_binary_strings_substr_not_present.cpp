// Problem Statement: Given an integer n, return the number of binary strings of length n
// that do not contain the substring "0100".
// Problem Source: AZ Coding Contest 2023 (https://codeforces.com/contest/1811)     

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

int dp[100100][16];
int n;
string t = "0100"; //no use of this
int rec(int level,int lastthree){
    //1.pruning
   
    //2.base case
    if(level == n){
        return 1;
    }
    //3.cache check
    if(dp[level][lastthree]!=-1){
        return dp[level][lastthree];
    }
    //4.compute
    int ans = 0;
    if(level>=3 and lastthree==2){
        //don't allow 0
        ans = rec(level+1,5);
    }else{
        //add a zero
        ans = rec(level+1,(lastthree<<1|0)&7);
        //add a one
        ans+= rec(level+1,(lastthree<<1|1)&7);
    }
    //5.save and return
    return dp[level][lastthree] = ans;
}

void solve(){
  cin>>n;
  memset(dp,-1,sizeof(dp));
  cout<<rec(0,0)<<endl;
}

signed main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: DP Form 1 - state is a level on one sequence
// explanation:
/*
State dp[level][lastthree] counts binary strings on the remaining positions whose previous three bits are lastthree.
The blocked substring is 0100. When level is at least 3 and lastthree equals 2, the only move appends 1 and stores mask 5.
Every other state appends 0 or appends 1 and keeps the new low three bits with a mask of 7.
Reaching level n counts as one finished string.
The bit mask has a fixed number of values, so the table is linear in n and each state branches a constant number of times.
*/
