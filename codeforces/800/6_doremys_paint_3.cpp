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
   map<int,int> mp;// {elt,freq}
   for(int i=0;i<n;i++){
     int elt;
     cin>>elt;
     mp[elt]++;
   }
   if(mp.size()==1){
    cout<<"Yes"<<endl;
    return;
   }
   if(mp.size()!=2){
    cout<<"No"<<endl;
    return;
   }
   auto it = mp.begin();
   int freq1 = it->second;
   it++;
   int freq2 = it->second;

   if(freq1 == freq2 || abs(freq1-freq2)==1){
    cout<<"Yes"<<endl;
   }else{
    cout<<"No"<<endl;
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