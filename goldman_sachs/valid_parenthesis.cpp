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

bool isValid(string s) {
    map<char,int> mp;
    mp['['] = 1;
    mp[']'] = -1;
    mp['('] = 2;
    mp[')'] = -2;
    mp['{'] = 3;
    mp['}'] = -3;

    stack<int> st;

    for (char c : s) {
        int val = mp[c];
        if (val > 0) {
            st.push(val);
        } else {
            if (st.empty() || st.top() != -val)
                return false;
            st.pop();
        }
    }
    return st.empty();
}
void solve(){
    string s = "{(())]";
    cout<<isValid(s)<<endl;
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