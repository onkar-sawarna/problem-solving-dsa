// Problem Statement: Given an integer n, return the number of binary strings of length n
// that do not contain the subsequence "0100".
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

int dp[100100][5];
int n;
string t = "0100"; //no use of this
int rec(int level,int match){
    //1.pruning
    if(match == 4){
        return 0;
    }
    //2.base case
    if(level == n){
        return 1;
    }
    //3.cache check
    if(dp[level][match]!=-1){
        return dp[level][match];
    }
    //4.compute
    int ans = rec(level+1,match+1)+rec(level+1,match);

    //5.save and return
    return dp[level][match] = ans;
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
State dp[level][match] counts binary strings on the remaining positions that have already matched match characters of the subsequence 0100.
A match of 4 returns 0 because that subsequence is complete.
The transition adds rec(level+1, match+1) and rec(level+1, match).
Reaching level n while match is still below 4 counts as one finished string.
Match runs only from 0 through 4, so the table is linear in n and each state does constant work.
*/
