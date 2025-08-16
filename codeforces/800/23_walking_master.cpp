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
    int source_x, source_y, destination_x, destination_y;
    cin >> source_x >> source_y >> destination_x >> destination_y;
    if (destination_y < source_y) 
    {
        cout << -1 << endl; 
        return; 
    }
    int moves = destination_y - source_y; 
    source_x += moves; 
    if (source_x < destination_x) 
    {
        cout << -1 << endl; 
        return;
    }
    moves += (source_x - destination_x); 
    cout << moves << endl;
}

signed main()
{
    IOS;
    int t;
    cin>>t;
    while(t--){
     solve();
    }
    return 0;
}