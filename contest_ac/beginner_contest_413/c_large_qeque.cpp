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

// Time Complexity: O(Q)
// Space Complexity: O(Q)
// Pattern: Constructive - Run-length deque
// explanation:
/*
The deque stores runs as pairs of value and copy count.
Type 1 appends one run at the back.
Type 2 subtracts k from the front: a run that is fully covered is popped, and a run that is only partly covered keeps the leftover count.
The sum adds value times the number of copies taken.
Each run is created once and popped at most once over the whole query list, so the front loop stays linear in Q.
*/
