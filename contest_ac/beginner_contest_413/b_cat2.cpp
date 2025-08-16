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
    vector<string> s(n);
    for(int i = 0; i < n; ++i) {
        cin >> s[i];
    }

    set<string> unique_concatenations;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if (i == j) {
                continue; 
            }
            unique_concatenations.insert(s[i] + s[j]);
        }
    }

    cout << unique_concatenations.size() << endl;
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