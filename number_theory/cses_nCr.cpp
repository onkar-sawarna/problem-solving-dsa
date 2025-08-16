#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod = 1e9 + 7;
const int MAXN = 1e6 + 5;
int fact[MAXN];

int iterativeBinpow(int a, int b, int mod) {
    int ans = 1;
    while (b) {
        if (b % 2) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b /= 2;
    }
    return ans;
}

int inverse(int b, int mod) {
    return iterativeBinpow(b % mod, mod - 2, mod);
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
}

int nCr() {
    int n, r;
    cin >> n >> r;
    if (r < 0 || r > n) {
        return 0;
    }
    int num = fact[n];
    int den = (fact[r] * fact[n - r]) % mod;
    return (num * inverse(den, mod)) % mod;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    precompute_factorials();
    int t;
    cin >> t;
    while (t--) {
        cout << nCr() << "\n";
    }
    return 0;
}