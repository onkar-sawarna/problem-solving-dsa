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