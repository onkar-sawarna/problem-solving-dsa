#include <bits/stdc++.h>
using namespace std;
#define IOS                       \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);                   \
    cout.tie(0);
#define int long long    
using pi = pair<int, int>;       // Alias for pair<long long, long long>
using vi = vector<int>;          // Alias for vector<long long>
using vvi = vector<vi>;          // Alias for vector<vector<long long>>

 

   void solve(){
    int n;
    string t,a;
    cin>>n>>t>>a;
    int flag = 0;
    for(int i=0;i<n;i++){
        if(t[i]=='o' and a[i] == 'o'){
            cout<<"Yes";
            flag=1;
            break;
        }
    }
    if(flag!=1)cout<<"No";
   }

    signed main()
    {
        IOS;
        solve();
        return 0;
    }

// Time Complexity: O(N)
// Space Complexity: O(N)
// Pattern: Brute Force - Aligned scan
// explanation:
/*
t and a are read and walked at the same index.
The first position where both characters are o prints Yes and sets flag.
The break leaves the rest of the strings unread by the loop.
If flag is still clear after the scan, the answer is No.
Both strings are stored in full.
*/
