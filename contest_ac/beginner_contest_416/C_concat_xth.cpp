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