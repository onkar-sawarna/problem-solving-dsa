#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
 
vector<vector<int>> g;
vector<int> vis;
vector<int> comp_number;
vector<int> comp_size;
int n,m;
   void dfs(int node,int comp_num){
    vis[node] = 1;
    comp_number[node] = comp_num;
    comp_size[comp_num]++;
    for(auto nbrs : g[node]){
        if(!vis[nbrs])
        dfs(nbrs,comp_num);
    }
   }
   void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    comp_number.resize(n+1);
    comp_size.resize(n+1);
    int count=0;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }//graph is ready
     for(int i=1;i<=n;i++){
        if(!vis[i]){
            count++;
            dfs(i,count);  
        }
     }
     for(auto v:comp_number)cout<<v<<" ";
     cout<<"\n";
     for(auto v:comp_size)cout<<v<<" ";
   }

    signed main()
    {
        IOS;
        solve();
        return 0;
    }