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

//   GOT  TLE 
void solve(){
    int H, W, K;
    cin >> H >> W >> K;

    set<pi> obstacles;
    for (int i = 0; i < K; ++i) {
        int r, c;
        cin >> r >> c;
        obstacles.insert({r, c});
    }

    if (H == 1 && W == 1) {
        cout << "Yes\n";
        return;
    }

    queue<pi> q;
    set<pi> visited;

    int start_r = 1;
    int start_c = 1;

    q.push({start_r, start_c});
    visited.insert({start_r, start_c});

    int dr[] = {-1, 1, 0, 0};
    int dc[] = {0, 0, -1, 1};

    bool found = false;

    while (!q.empty()) {
        pi current_cell = q.front();
        q.pop();

        int r = current_cell.first;
        int c = current_cell.second;

        if (r == H && c == W) {
            found = true;
            break;
        }

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= 1 && nr <= H && nc >= 1 && nc <= W) {
                if (obstacles.find({nr, nc}) == obstacles.end() && visited.find({nr, nc}) == visited.end()) {
                    visited.insert({nr, nc});
                    q.push({nr, nc});
                }
            }
        }
    }

    if (found) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }
}

signed main()
{
    IOS;
    int t = 1;
    while(t--){
     solve();
    }
    return 0;
}