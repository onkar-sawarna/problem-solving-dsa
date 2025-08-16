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

int firstUniqChar(string s) {
    vector<int> char_counts(256, 0);

    for (char c : s) {
        char_counts[c]++;
    }

    for (int i = 0; i < s.length(); ++i) {
        if (char_counts[s[i]] == 1) {
            return i;
        }
    }

    return -1;
}

void solve(){
    string s;
    cin>>s;
    cout<<firstUniqChar(s)<<endl;
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