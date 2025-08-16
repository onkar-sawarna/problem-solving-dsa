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
    int Q;
    cin >> Q;

    deque<pi> A_blocks;

    while(Q--) {
        int type;
        cin >> type;

        if (type == 1) {
            int c, x;
            cin >> c >> x;
            A_blocks.push_back({x, c});
        } else {
            int k;
            cin >> k;

            int total_sum = 0;
            int remaining_k = k;

            while (remaining_k > 0) {
                int value = A_blocks.front().first;
                int count = A_blocks.front().second;

                if (remaining_k >= count) {
                    total_sum += value * count;
                    remaining_k -= count;
                    A_blocks.pop_front();
                } else {
                    total_sum += value * remaining_k;
                    A_blocks.front().second -= remaining_k;
                    remaining_k = 0;
                }
            }
            cout << total_sum << endl;
        }
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