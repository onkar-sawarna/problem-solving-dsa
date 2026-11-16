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
   string s,t;
   cin>>s>>t;
   int n=s.size();
   if(n==1)cout<<"Yes"<<endl;
   else{
   for(int i = 1; i < n; ++i){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if (t.find(s[i-1]) == string::npos) {
                cout << "No" << endl;
                return;
            }
        }
    }  
    cout << "Yes" << endl;
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

// Time Complexity: O(N * |T|)
// Space Complexity: O(N + |T|)
// Pattern: Brute Force - Uppercase check
// explanation:
/*
A string of length 1 prints Yes immediately.
For a longer s, every uppercase s[i] searches t for the previous character s[i - 1].
t.find scans the precondition string from the start.
A missing character prints No and returns.
If every uppercase letter finds its predecessor in t, the answer is Yes.
*/
