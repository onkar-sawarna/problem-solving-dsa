/*
 Problem Statement: Given a set of items, each with a weight and a value,
 determine the number of each item to include in a collection so that
 the total weight is less than or equal to a given limit and the total value is as large as possible.
 You cannot take a fraction of an item.
 
 Constraints:
 1 <= N <= 100
 1 <= W <= 10^5
 1 <= weight[i], value[i] <= 10^4

 Problem Source: Classic 0/1 Knapsack Problem.
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

int n,W; 
int w[105];
int v[105];
int dp[105][100005];

int rec(int level,int weight_taken){
   
   //1. pruning
   if(level > n)return 0;

   //2. base case
   if(level == n)return 0;

   //3. cache check
   if(dp[level][weight_taken]!=-1){
    return dp[level][weight_taken];
   }

   //4. transition/compute
   int ans = rec(level+1,weight_taken);
   if(weight_taken+w[level]<=W){
     ans = max(ans,v[level]+rec(level+1,weight_taken+w[level]));
   }
    
   //5. save and return
   return dp[level][weight_taken] = ans;
}

void generate() {
    int current_weight = 0;
    cout << "Items taken in the optimal solution:" << endl;
    for (int level = 0; level < n; ++level) {
        // We check if taking the current item was the optimal choice.
        // The optimal value from the current state is rec(level, current_weight).
        // The value if we skip item 'level' is rec(level + 1, current_weight).
        // If they are different, it implies taking item 'level' was the necessary and better choice.
        // These rec() calls are O(1) because the dp table is already filled.
        if (rec(level, current_weight) != rec(level + 1, current_weight)) {
            cout << "Item " << level << " (weight: " << w[level] << ", value: " << v[level] << ")" << endl;
            current_weight += w[level];
        }
    }
}

void solve(){
  cin>>n>>W;
 for(int i=0;i<n;i++){
  cin>>w[i]>>v[i];
 }
 memset(dp,-1,sizeof(dp));
 cout<<rec(0,0)<<endl;
 generate();
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