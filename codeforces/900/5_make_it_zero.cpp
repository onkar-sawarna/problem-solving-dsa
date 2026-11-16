// Question: Which ranges should you overwrite with the XOR of that range so that every element becomes zero?
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
  vi a(n);
  vin(a);

  if(n%2==0){
    cout<<2<<endl;
    cout<<1<<" "<<n<<endl;
    cout<<1<<" "<<n<<endl;
  }else{
    cout<<4<<endl;
    cout<<2<<" "<<n<<endl;
    cout<<2<<" "<<n<<endl;
    cout<<1<<" "<<2<<endl;
    cout<<1<<" "<<2<<endl;
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

// Time Complexity: O(n)
// Space Complexity: O(n)
// Pattern: Constructive - XOR ranges
// explanation:
/*
The array is read, then only the parity of n chooses the ranges.
An even n is cleared by two XOR passes over [1, n].
An odd n uses two passes on [2, n] and two passes on [1, 2].
The stored values are never inspected; the printed pairs are constant for that parity.
*/
