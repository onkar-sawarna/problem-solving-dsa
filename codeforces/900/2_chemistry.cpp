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
   int n,k;
   cin>>n>>k;
   string s;
   cin>>s;
   
   vi freq(26,0);
   for(int i=0;i<n;i++){
     freq[s[i]-'a']++;
   }
   int odd_count=0;
   for(int i=0;i<26;i++){
     if(freq[i]&1)odd_count++;
   }
   if(odd_count>k+1)cout<<"nO"<<endl;
   else cout<<"YeS"<<endl;
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