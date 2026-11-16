// Question: If every ordered concatenation of k strings chosen from the n strings, repeats allowed, is sorted, which one is x-th?
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

void solve() {
    int n, k, x;
    cin >> n >> k >> x;

    x--; 

    vector<string> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    vector<string> generated_strings;

    long long num_combinations = static_cast<long long>(pow(n, k));

    for (long long j = 0; j < num_combinations; ++j) {
        string current_concatenation = "";
        long long temp_j = j;                   

        vector<int> current_indices(k);

        for (int i = 0; i < k; ++i) {
            current_indices[k - 1 - i] = temp_j % n;
            temp_j /= n;
        }

        for (int i = 0; i < k; ++i) {
            current_concatenation += s[current_indices[i]];
        }
        
        generated_strings.push_back(current_concatenation);
    }

    sort(generated_strings.begin(), generated_strings.end());

    cout << generated_strings[x] << "\n";
}

signed main()
{
    IOS;
    int t;
    t=1;
    while(t--){
     solve();
    }
    return 0;
}

// Time Complexity: O(n^k * k * L * log(n^k))
// Space Complexity: O(n^k * k * L)
// Pattern: Brute Force - All concatenations
// explanation:
/*
x is converted to a 0-based rank.
Every integer from 0 to n^k - 1 is decoded in base n into k indices, with the rightmost index taken from the least significant digit.
The chosen strings are joined in that index order and stored.
The vector is then sorted lexicographically.
The printed line is the string at position x after the sort. L is the length of one input string.
*/
