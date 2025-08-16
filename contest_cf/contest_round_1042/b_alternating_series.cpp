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

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) cout << -1;
        else {
            if (n == 2 || i== n-1) cout << 2;
            else cout << 3;
        }
        if (i < n - 1) cout << " ";
    }
    cout << "\n";
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