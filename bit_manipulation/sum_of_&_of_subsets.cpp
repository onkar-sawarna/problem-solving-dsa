// Question: Find the sum of the bitwise AND of every non-empty subset of the array.
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
   cin>>n;
   int a[n];
   for(int i=0;i<n;i++){
    cin>>a[i];
   }
   long long ans=0;
   for(int bit=0; bit<32; bit++){                  // For each bit
    int countSetBits = 0;
    for(int i=0; i<n; i++){                     // Count set bits
        if((a[i] >> bit) & 1) countSetBits++;
    }
    if(countSetBits > 0){
        ans += ((1LL << countSetBits) - 1) * (1LL << bit); // Add subset contribution
    }
   }
   cout<<ans<<endl;
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

// Time Complexity: O(32 * n)
// Space Complexity: O(1)
// Pattern: Bit Contribution - Subset AND Sum
// explanation:
/*
The outer loop walks 32 bit positions.
The inner loop counts how many array values have that bit set.
The bit stays set in a subset AND for every non-empty subset of those values, and there are 2^count - 1 of them.
Each such subset adds the bit weight. Extra memory is a few counters beside the input array.
*/
