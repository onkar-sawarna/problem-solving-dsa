#include <bits/stdc++.h>
using namespace std;

#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);

#define int long long    
using pi = pair<int, int>;       
using vi = vector<int>;          
using vvi = vector<vi>;          
void solve(){
    int N;
    int L; 
    cin >> N >> L;

    vi d(N - 1); 
    for (int i = 0; i < N - 1; ++i) {
        cin >> d[i];
    }

    if (L % 3 != 0) {
        cout << 0 << "\n";
        return; 
    }

    int third_arc_len = L / 3;
    map<int, int> pos_freq; 

    int current_pos = 0;
    pos_freq[current_pos]++; 

    for (int i = 0; i < N - 1; ++i) {
        current_pos = (current_pos + d[i]) % L;
        pos_freq[current_pos]++;
    }

    int total_equilateral_triples = 0;

    for (auto const& pair_a : pos_freq) {
        int pos_a = pair_a.first;
        int count_a = pair_a.second;
        
        int pos_b = (pos_a + third_arc_len) % L;
        int pos_c = (pos_a + 2 * third_arc_len) % L;

        auto it_b = pos_freq.find(pos_b);
        auto it_c = pos_freq.find(pos_c);

        if (it_b != pos_freq.end() && it_c != pos_freq.end()) {
            total_equilateral_triples += count_a * it_b->second * it_c->second;
        }
    }
    
    cout << total_equilateral_triples / 3 << "\n";
}

signed main() {
    IOS; 
    solve(); 
    return 0; 
}
