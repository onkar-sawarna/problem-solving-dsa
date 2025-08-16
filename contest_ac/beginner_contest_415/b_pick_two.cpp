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
  string s;
  cin>>s;
  int n = s.size();
  set<pair<int,int>> st;
  int last_index = 0;
  int cnt=0;
  for(int i=0;i<n;i++){
    if(s[i]=='.'){
        continue;
    }else{
        if(cnt == 0){
            last_index = i+1;
        }
        cnt++;
        if(cnt==2){
         st.insert(make_pair(last_index,i+1));
         cnt=0;
        }
    }
  }
  for(auto it:st){
    cout<<it.first<<","<<it.second<<endl;
  }
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