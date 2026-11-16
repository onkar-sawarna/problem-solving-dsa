// Question: How many ways can a stick of length n be cut into four positive integer sides of a rectangle?
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

// Time Complexity: O(1)
// Space Complexity: O(1)
// Pattern: Math - Stick rectangle count
// explanation:
/*
An odd n cannot be split into four positive integer lengths, so the answer is 0.
For even n the code evaluates (n/2 - 1) / 2.
That expression counts the splits directly, with no loop over side lengths.
No array is allocated.
*/
