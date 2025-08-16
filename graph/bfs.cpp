#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
vector<vector<int>> g;
vector<int> vis;
vector<int> dis;
int n,m;

void bfs(int sc_node){
    queue<int> q;
    vis[sc_node] = 1;
    dis[sc_node] = 0;
    q.push(sc_node);

    while(!q.empty()){
        int node = q.front();
        q.pop();

        for(auto v:g[node]){
            if(!vis[v]){
                vis[v]=1;
                dis[v]=dis[node]+1;
                q.push(v);
            }
        }
    }
}
void solve(){
    cin>>n>>m;
    g.resize(n+1);
    vis.resize(n+1,0);
    dis.resize(n+1,0);
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
            bfs(i);
           
        }
     }
     for(auto v:vis)cout<<v<<" ";
     cout<<"\n";
     for(auto v:dis)cout<<v<<" ";
   }

    signed main()
    {
        IOS;
        solve();
        return 0;
    }