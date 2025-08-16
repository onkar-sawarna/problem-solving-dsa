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
    long long n; 
        cin >> n;
        vi a(n);
        for (int i = 0; i < n; i++) 
            cin >> a[i];

        sort(a.begin(), a.end()); 
        long long max_number = a[n - 1];
        long long min_number = a[0];
        if (max_number == min_number)
        {
            cout << "NO" << endl; 
        }
        else
        {
            cout << "YES" << endl; 
            cout << max_number << " "; 
            for (int i = 0; i < n - 1; i++) 
                cout << a[i] << " ";
            cout << endl; 
        }
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