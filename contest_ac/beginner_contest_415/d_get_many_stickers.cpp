#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"
using pi = pair<int, int>;
using vi = vector<int>;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<pi> offers(M);
    for (auto &[A, B] : offers) cin >> A >> B;

    // Correct: sort by (A - B), smallest "net loss" first!
    sort(offers.begin(), offers.end(), [](pi &x, pi &y) {
        return (x.first - x.second) < (y.first - y.second);
    });

    int bottled = N, empty = 0, stickers = 0;
    bool changed;
    do {
        changed = false;
        // Drink all bottled colas to get empty bottles
        if (bottled > 0) {
            empty += bottled;
            bottled = 0;
            changed = true;
        }
        // Try to find the best possible exchange
        for (const auto &[A, B] : offers) {
            if (A > empty) continue;
            // Perform as many as possible for current empty
            int times = empty / A;
            if (times == 0) continue;
            stickers += times;
            empty -= times * A;
            bottled += times * B;
            changed = true;
            break; // At each step, best offer is used as much as possible
        }
    } while (changed);

    cout << stickers << endl;
}

signed main() {
    IOS;
    int t = 1;
    while (t--) solve();
    return 0;
}
