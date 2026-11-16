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
   int k;
   cin>>k;
   k++;

   int len=1;
   while(1LL<<(len-1)*len<k){
     k-=(1LL<<(len-1))*len;
     len++;
   }

   int num = ((k+len-1)/len);
   int val = (1LL<<(len-1))+num-1;

   int bitinval = (k-1)%len;

   cout<<((val>>(len-1-bitinval))&1)<<endl;
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

// Time Complexity: O(log k)
// Space Complexity: O(1)
// Pattern: Bit Groups - Kth Bit of the Stream
// explanation:
/*
Positive integers are written in binary with no separators and grouped by bit length.
The group of length len holds 2 to the power (len-1) numbers, and each number contributes len bits.
The loop subtracts whole groups until k falls inside one length, so the iterations follow log k.
That number is rebuilt and the chosen bit is shifted out. Only a few integers are stored.
*/
