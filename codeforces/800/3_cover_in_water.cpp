// Question: What is the minimum number of actions needed to put water in every empty cell?
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
  string s;
  cin>>n>>s;
  int empty = 0;
  int maxi = 0;
  int total = 0;
  for(int i=0;i<n;i++){
    if(s[i]!='#'){
        empty++;
        total++;
    }else{
      maxi=max(maxi,empty);
      empty=0;
    }
  }
  maxi=max(maxi,empty);
  if(maxi>=3)cout<<2<<endl;
  else if(maxi<=2){
    cout<<total<<endl;
  }else{
    cout<<0<<endl;
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
// Pattern: Greedy - Empty runs
// explanation:
/*
empty grows on every cell that is not '#', and total counts those cells.
A '#' closes the current run and stores it in maxi if it is longer.
A final update keeps a run that reaches the end of the string.
A longest run of 3 or more prints 2; a shorter run prints total, one operation per empty cell.
*/
