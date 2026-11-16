// Question: How many index pairs i < j satisfy j - i = a[i] + a[j]?
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
  int ans=0;
  // j-i = Ai+Aj or  j-Aj= Ai+i for j>i
  map<int,int> freq;
  for(int i=0;i<n;i++){
    int target = i-a[i];
    if(freq.count(target)){
        ans+=freq[target];
    }
    int current = a[i]+i;
    freq[current]++;
  }
  cout<<ans<<endl;
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

// Time Complexity: O(N log N)
// Space Complexity: O(N)
// Pattern: Math - Pair frequency
// explanation:
/*
The pair test j - i = a[i] + a[j] is rewritten as j - a[j] = i + a[i] for a later j.
The map counts how many earlier indices stored the key a[i] + i.
At the current index the lookup key is i - a[i], and that frequency is added to ans before the current key is inserted.
Inserting after the lookup counts each pair once, with the right index later in the scan.
Every map operation costs a logarithm in the number of distinct keys.
*/
