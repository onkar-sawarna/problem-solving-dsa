#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
using pi = pair<int, int>;       
using vi = vector<int>;         
using vvi = vector<vi>;          
vvi g;
vi vis,topo;
int n,m;

void dfs(int node){
  vis[node] = 1;
  for(auto v:g[node]){
    if(!vis[v]){
        dfs(v);
    }
  }
  topo.push_back(node);
            }                   //longest topological path starting at node
                                int dp[100100];
                                int rec(int node){
                                    if(dp[node]!=-1)return dp[node];
                                    int ans=1;
                                    for(auto v:g[node]){
                                        ans=max(ans,1+rec(v));
                                    }
                                    return dp[node]=ans;
                                }

void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
    }//graph is ready
                                //longest topological path starting at node
                                int ans=0;
                                memset(dp,-1,sizeof(dp));
                                for(int i=1;i<=n;i++){
                                    ans=max(ans,rec(i));
                                }
                                cout<<ans;
    for(int i=1;i<=n;i++){
    if(!vis[i]){
        dfs(i);  
    }
   }
    reverse(topo.begin(),topo.end());
    for(auto v:topo){
        cout<<v<<" ";
    }
 }

signed main()
{
    IOS;
    solve();
    return 0;
}