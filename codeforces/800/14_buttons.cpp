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
   int a,b,c;
   cin>>a>>b>>c;

   if(c%2){
    if(b>a){
        cout<<"Second"<<endl;
    }else{
        cout<<"First"<<endl;
    }
   }else{
    if(a>b){
        cout<<"First"<<endl;
    }else{
        cout<<"Second"<<endl;
    }
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

// Time Complexity: O(1)
// Space Complexity: O(1)
// Pattern: Greedy - Extra press
// explanation:
/*
c spare presses go one at a time, so an odd c leaves the extra press with the first player.
In that case Second wins only when b > a; otherwise First wins, including a tie.
An even c leaves the counts as given, so First wins only when a > b.
A tie with even c goes to Second.
*/
