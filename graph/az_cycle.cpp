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
int n,m;
vi col;
vi parent;
vi any_cycle;
bool is_cycle=0;
void dfs(int node,int par){
    col[node]=2;
    parent[node]=par;
    //go through the neighbours
    for(auto nbr:g[node]){
       // if(nbr==parent[node])continue; --> for undirected graph
      if(col[nbr]==1){
        //nbr is unvisited
        dfs(nbr,node);
      }else if(col[nbr]==2){
        //nbr is a back edge -- a cycle
        cout<<"Hit at "<<node << " with back edge to " << nbr << endl;
        if(is_cycle==0){
            int temp = node;
            while(temp!=nbr){
              any_cycle.push_back(temp);
              temp=parent[temp];
            }
            any_cycle.push_back(temp);
            //we need to reverse as cycle is in reverse order because we are going backwards as temp=parent[temp]
            reverse(any_cycle.begin(),any_cycle.end()); 
        }
        is_cycle=1;
      }
    }
    col[node]=3;
}

void solve(){
  cin>>n>>m;
  g.resize(n+1);
  col.assign(n+1,1);
  parent.assign(n+1,0);
  //forming the graph from the edges
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
   // g[y].push_back(x); --> for undirected graph
  }
  for(int i=1;i<=n;i++){
    if(col[i]==1)dfs(i,0);
  }
  for(auto v:any_cycle){
    cout<<v<<" ";
  }
}

signed main()
{
    IOS;
    solve();
    return 0;
}