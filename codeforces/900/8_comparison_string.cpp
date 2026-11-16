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
  string s;
  cin>>s;
  int lessthan=0,greaterthan=0;
  int maxi=0;
  for(int i=0;i<n;i++){
    if(s[i]=='<'){
      lessthan++;
      greaterthan=0;
      maxi = max(maxi, lessthan);
    }else if(s[i]=='>'){
        greaterthan++;
        lessthan=0;
        maxi = max(maxi, greaterthan);
    }
  }
  cout<<maxi+1<<endl;
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
// Pattern: Greedy - Longest run
// explanation:
/*
lessthan and greaterthan track the current streak of '<' and '>' .
A '<' grows the less-than streak, clears the other counter, and updates maxi.
A '>' does the same for the greater-than streak.
The answer is maxi + 1, one past the longest uninterrupted run.
*/
