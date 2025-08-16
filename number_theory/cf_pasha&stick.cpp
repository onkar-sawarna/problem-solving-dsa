#include <iostream>
using namespace std;
#define int long long 

void solve(){
    int n;
    cin>>n;
    if(n % 2 != 0){
        cout << 0 << "\n";
        return;
    }
    int sum = n/2;
    int ans = (sum - 1) / 2;
    cout << ans << "\n";
 }

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t;
    t=1;
    while(t--){
        solve();
    }
    return 0;
}