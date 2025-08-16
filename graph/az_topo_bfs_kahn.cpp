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

int n,m;
vvi g;
vi indegree,topo; 

void kahn(){
   queue<int> q;
   for(int i=1;i<=n;i++){
    if(indegree[i]==0)q.push(i);
   }
   while(!q.empty()){
    int curr = q.front();
    q.pop();
    topo.push_back(curr);
    for(auto nbr:g[curr]){
     indegree[nbr]--;
     if(indegree[nbr] == 0)q.push(nbr);
    }
   }
}

signed main()
{  
    IOS;
    cin>>n>>m;
    g.resize(n+1);
    indegree.assign(n+1,0);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        g[x].push_back(y);
        indegree[y]++;
      }
    kahn();
    if(topo.size()!=n){
        cout<<"there is a cycle";
    }else{
        for(auto v:topo){
            cout<<v<<" ";
        }
    }
    return 0;
}