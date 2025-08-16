#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    

vector<vector<int>> g;
int n,m;
vector<int> vis;
vector<int> color;
int isBipartite=1;

void dfs(int node,int col){
   vis[node] = 1;
   color[node] = col;
   //go through all the neighbors
   for(auto nbrs:g[node]){
    if(!vis[nbrs]){
        dfs(nbrs,(1+2)-col);
    }else if(color[nbrs]==color[node]){
        isBipartite=0;
    }
   }
}

void solve(){
   cin>>n>>m;
    g.resize(n + 1);   // Resize adjacency list for n+1 nodes (1-indexed)
    vis.resize(n + 1, 0); // Resize visited array and initialize to 0 (unvisited)
    color.resize(n + 1, 0); 
   for(int i=0;i<m;i++){
     int a,b;
     cin>>a>>b;
     g[a].push_back(b);
     g[b].push_back(a);
   }
   //graph is ready
   int col = 1;
   for(int i=1;i<n;i++){
    if(!vis[i])
     dfs(i,col);
      if (!isBipartite)          // If a component is found not to be bipartite, no need to check further
       break;
   }
   if(isBipartite)cout<<"YES";
   else
   cout<<"NO BRO";
}

signed main(){
    IOS;
    solve();
    return 0;
}