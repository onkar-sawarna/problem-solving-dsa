#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long
#define endl "\n"

void solve() {
            int n; cin >> n;
            deque<int> d;
            for(int i = 0; i < n; i++) {
                int x; cin >> x;
                d.push_back(x);
            }
    
            int flag = true;
            while(!d.empty()) {
                if(flag) {
                    if(d.front() < d.back()) { cout << "L"; d.pop_front(); }
                    else { cout << "R"; d.pop_back(); }
                }
                else {
                    if(d.front() > d.back()) { cout << "L"; d.pop_front(); }
                    else { cout << "R"; d.pop_back(); }
                }
                flag = !flag;
            }
            cout << "\n";
        }
    

signed main() {
    IOS;
    int t; cin >> t;
    while (t--) solve();
    return 0;
}

// Time Complexity: O(T * N)
// Space Complexity: O(N)
// Pattern: Greedy - Alternating ends
// explanation:
/*
The n values are pushed onto a deque in input order.
flag starts true and flips after every pop.
A true step removes the smaller end. A false step removes the larger end.
Equal ends take the else branch, so R is printed and the back is popped.
Each element leaves once, and the direction string has length n.
*/
