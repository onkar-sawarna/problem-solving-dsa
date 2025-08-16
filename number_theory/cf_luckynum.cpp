#include <iostream>
using namespace std;
#define int long long

int iterativeBinpow(int a, int b) { // Remove mod parameter
    int ans = 1;
    while (b) {
        if (b % 2) ans = ans * a; // Remove mod operation
        a = a * a; // Remove mod operation
        b = b / 2;
    }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += iterativeBinpow(2, i); // Remove mod operation
    }
    cout << sum << "\n";
}

signed main() {
    solve();
    return 0;
}