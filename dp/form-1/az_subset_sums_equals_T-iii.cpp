// There are N items [N <= 100 and Xi <= 10^4]
// Find if a subset of the items exists that sums up to the target T

// Now it has Q queries [Q <= 10^4]
// You need to print the subset

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
int t;
int q;
int x[101];

int dp[105][10100];

int rec(int level,int sum_left){
    //1. pruning
    if(sum_left<0)return 0;
    //2. base case
    if(level==n+1){
        if(sum_left==0){
            return 1;
        }else{
            return 0;
        }
    }
    //3. cache check
    if(dp[level][sum_left]!=-1){
        return dp[level][sum_left];
    }
    //4. transition/compute
    int ans = 0;
    if(rec(level+1,sum_left)==1){
        ans=1;
    }else if(rec(level+1,sum_left-x[level])==1){
       ans=1;
    }
    //5. save and return
    return dp[level][sum_left]=ans;
}
void printSubset(int level,int sum_left){
    if(level==n+1){
        return;
    }
    //find the correct transition
    if(rec(level+1,sum_left)==1){
        printSubset(level+1,sum_left);
    }else if(rec(level+1,sum_left-x[level])){
        cout<<x[level]<<" ";
        printSubset(level+1,sum_left-x[level]);
    }
}
void solve(){
   cin>>n;
   for(int i=1;i<=n;i++){
    cin>>x[i];
   }
   memset(dp,-1,sizeof(dp));
   // we will use this dp array accross all the queries
   // TC redues from O(n*t*q) to O(n*t+q)
   cin>>q;
   while(q--){
    cin>>t;
    if(rec(1,t)){
        printSubset(1,t);
        cout<<endl;
    }else{
        cout<<"no solution"<<endl;
    }
   }
}

signed main()
{
    IOS;
    int k;
    k=1;
    while(k--){
     solve();
    }
    return 0;
}