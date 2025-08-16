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
    int x;
    cin >> x;

    set<int> x_digits;
    int temp_x = x;
    if (temp_x == 0) {
        x_digits.insert(0);
    } else {
        while (temp_x > 0) {
            x_digits.insert(temp_x % 10);
            temp_x /= 10;
        }
    }

    if (x_digits.count(0)) {
        cout << 0 << endl;
        return;
    }

    cout<<*x_digits.begin()<<endl;
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