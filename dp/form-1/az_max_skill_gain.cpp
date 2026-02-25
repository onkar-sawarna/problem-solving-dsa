/*
 Problem Statement: Given N problems, where the ith problem takes Ti time and gives Si skill points.
 You have a total of X time and can solve at most K problems.
 Find the maximum skill gain you can achieve.

 Problem Source: Variation of 0/1 Knapsack problem, inspired by AZ DP Workshop.
 
 TC: O(N * X * K)
 SC: O(N * X * K)
*/
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

int n;
int t[1001];
int s[1001];
int x,k;

int dp[101][101][101];

int rec(int level,int time_taken,int item_taken){
    //max skill i can make from [level...n-1]..if [0...level-1] is decided

    //1. pruning
    if(level>n){
        return 0;
    }

    //2. base case
    if(level==n){
        return 0;
    }

    //3. cache check
    if(dp[level][time_taken][item_taken]!=-1){
        return dp[level][time_taken][item_taken];
    }

    //4. transition
    int ans = rec(level+1,time_taken,item_taken);
    if(time_taken+t[level] <= x and item_taken+1 <= k){
        ans = max(ans,s[level]+rec(level+1,time_taken+t[level],item_taken+1));
    }
     
    //5. save and return
    return dp[level][time_taken][item_taken]=ans;
}

void solve(){
   cin>>n;

   for(int i=0;i<n;i++){
    cin>>t[i]>>s[i];
   }
   cin>>x>>k;
   memset(dp,-1,sizeof(dp));
   cout<<rec(0,0,0)<<endl;
}

signed main()
{
    IOS;
    int t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}