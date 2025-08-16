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

void solve(){
    int N;
    cin >> N;

    vi S(N + 1); 
    set<pi> remaining_dominoes; //size and original index not yet visted by bfs

    for (int i = 1; i <= N; ++i) {
        cin >> S[i];
        remaining_dominoes.insert({S[i], i});
    }

    vi dist(N + 1, -1); //min number of dominos
    queue<int> q; //store original index

    dist[1] = 1; 
    q.push(1);
    
    remaining_dominoes.erase({S[1], 1}); //1 is processed so removed 

    while (!q.empty()) {
        int curr_id = q.front();
        q.pop();

        long long current_domino_size = S[curr_id];
        long long max_reachable_size = 2 * current_domino_size;

        for (auto it = remaining_dominoes.begin(); it != remaining_dominoes.end(); ) {
            if (it->first <= max_reachable_size) {
                int next_id = it->second; 
                
                dist[next_id] = dist[curr_id] + 1; 
                q.push(next_id);                   
                
                it = remaining_dominoes.erase(it); 
            } else {
                break;
            }
        }
    }

    if (dist[N] != -1) {
        cout << dist[N] << endl;
    } else {
        cout << -1 << endl;
    }
}

signed main()
{
    IOS; 
    int t;
    cin >> t; 
    while (t--) {
        solve(); 
    }
    return 0;
}