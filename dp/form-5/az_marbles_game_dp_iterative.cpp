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

int a,b;
int dp[1001][1001];


void solve(){
 cin>>a>>b;
 //memset(dp,-1,sizeof(dp));
 for(int x=0;x<=a;x++){
    for(int y=0;y<=b;y++){
       //2.base case
    if(x == 0 and y==0)dp[x][y]=0;

    //4.transition/compute
    int ans = 0;
    for(int m=0;m<x;m++){
        if(dp[m][y] == 0){
            ans = 1;
            break;
        }
    }
    for(int m=0;m<y;m++){
        if(dp[x][m] == 0){
            ans = 1;
            break;
        }
    }
    for(int m=1;m<=min(x,y);m++){
        if(dp[x-m][y-m] == 0){
            ans = 1;
            break;
        }
    }
     dp[x][y]=ans;
    }
 }

 cout<<dp[a][b];
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