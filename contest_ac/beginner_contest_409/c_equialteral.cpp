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

// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Pattern: Math - Circle triples
// explanation:
/*
If L is not divisible by 3, the answer is 0 because no equal side fits on the circle.
Otherwise the side is L / 3. Points are placed by adding the given gaps modulo L, and a map counts copies of each position.
For every occupied position a, the code looks up a + L / 3 and a + 2L / 3, also modulo L.
When both keys exist, the product of the three frequencies is added.
Each geometric triple is seen from all three vertices, so the total is divided by 3.
*/
