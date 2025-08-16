#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long // As per your template
#define endl "\n"
#define vin(a) for (auto& i : a) cin >> i
#define vout(a) for (const auto& i : a) cout << i << " "
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

void solve()
{
    int n, k;
    cin >> n >> k;
    // Using std::vector is safer and more flexible than C-style arrays
    // when 'n' is determined at runtime.
    vi arr(n);
    vin(arr); // Read array elements using your macro

    // head and tail
    int tail = 0, head = -1;

    // datastructure for the window: We need to track the current sum.
    int current_sum = 0;

    // answer maintain
    int ans = 0; // This will store the count of valid subarrays

    // for every start (tail pointer)
    while (tail < n)
    {
        // eat as many elements as possible till its valid
        // The condition for eating is:
        // 1. There is a next element (`head + 1 < n`).
        // 2. Adding the next element keeps the `current_sum` atmost `k`.
        while (head + 1 < n && (current_sum + arr[head + 1] <= k))
        {
            head++; // Move head forward
            // include element at head in the data structure
            current_sum += arr[head]; // Add arr[head] to current_sum
        }

        // update the answer for current start
        // At this point, the window [tail, head] has a sum < K.
        // All subarrays ending at 'head' and starting from 'tail' up to 'head' are also valid.
        // The number of such subarrays is (head - tail + 1).
        ans += (head - tail + 1);

        // move start one step forward.
        // This part handles shrinking the window from the left (tail).
        if (tail > head)    // This handles cases where the window became empty (e.g., if arr[0] itself >= K)
        {
            tail++;
            head = tail - 1; // Reset head to be just before the new tail
        }
        else // Normal case: remove arr[tail] as tail moves forward
        {
            // change data structure because removing tail element
            current_sum -= arr[tail]; // Subtract arr[tail] from current_sum
            tail++; // Move tail forward
        }
    }

    cout << ans << endl;
}

signed main()
{
    IOS; // Fast I/O
    int t;
    cin >> t; // Read number of test cases
    while (t--) {
        solve();
    }
    return 0;
}