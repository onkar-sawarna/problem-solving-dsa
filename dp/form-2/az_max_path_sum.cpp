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

int n,m;
int arr[1001][1001]; 
int dp[1001][1001];

int rec(int i,int j){
    // maximum path sum in a matrix ending at arr[i][j] if you are allowed to go down and right
    //1.pruning
    if(i<0 || j<0)
    return -1e9;

    //2.base case
    if(i==0 and j==0){
        return arr[0][0];
    }
    //3.cache check
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //4.transition/compute
    int ans = -1e9;
    if(i!=0){
        ans=max(ans,rec(i-1,j)+arr[i][j]);
    }
    if(j!=0){
        ans=max(ans,rec(i,j-1)+arr[i][j]);
    }
    
    //5.save and return
    return dp[i][j]=ans;
}

void solve(){
   cin>>n>>m;
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        cin>>arr[i][j];
        dp[i][j] = -1;
    }
   }
   cout<<rec(n-1,m-1)<<endl;
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