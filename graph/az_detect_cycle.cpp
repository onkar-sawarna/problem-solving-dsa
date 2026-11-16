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
bool is_cycle;

bool dfs(int node) {
    col[node] = 2; 

    for(auto nbr : g[node]) {
        if(col[nbr] == 1) { 
            if(dfs(nbr)) { 
                return true; 
            }
        } else if(col[nbr] == 2) { 
            return true; 
        }
    }
    col[node] = 3; 
    return false; 
}

void solve(){
  cin>>n>>m;
  g.assign(n + 1, vi()); 
  col.assign(n+1,1); 
  is_cycle = false; 

  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
  }

  for(int i=1;i<=n;i++){
    if(col[i]==1) { 
        if (dfs(i)) { 
            is_cycle = true;
            break; 
        }
    }
  }

  if(is_cycle) cout << "Yes\n"; 
  else cout << "No\n"; 
}

signed main()
{
    IOS;
    int t ;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(n + m)
// Pattern: DFS - Directed cycle
// explanation:
/*
col begins at 1 for every node.
dfs paints the node 2, then a neighbor still at 1 is entered recursively.
A neighbor that is already 2 means the walk has returned to the current stack, so a cycle is reported.
The node is painted 3 after its adjacency list, and the outer loop starts a walk only at nodes still colored 1.
*/
