// Question: What is the sum of the powers of two from 2^1 through 2^n?
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

// Time Complexity: O(n log n)
// Space Complexity: O(1)
// Pattern: Number Theory - Sum of powers of two
// explanation:
/*
The loop adds 2^1 + 2^2 + ... + 2^n.
Each term is computed from scratch by iterative binary exponentiation, which is O(log i) for exponent i.
Summing that cost from 1 to n is O(n log n).
The closed form 2^(n+1) - 2 is not used.
Only the running sum and the power routine's locals are stored.
*/
